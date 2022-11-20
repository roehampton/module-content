## Solution for single-student page

models/module.js

```javascript
// Get the functions in the db.js file to use
const db = require('../services/db');

class Module {
    // Module code
    code;
    // Module name
    mName;

    constructor(code, name) {
        this.code = code;
        this.mName = name;
    }

    async getModuleName() {
        if (typeof this.name !== 'string') {
            var sql = "SELECT * from Modules where code = ?"
            const results = await db.query(sql, [this.id]);
            this.mName = results[0].name;
            this.code = results[0].code;
        }
    }
}

module.exports = {
    Module
}

```

models/programme.js

```
// Get the functions in the db.js file to use
const db = require('../services/db');

class Programme {
    // Programme ID
    id;
    // Programme name
    pName;

    constructor(id) {
        this.id = id;
    }

    async getProgrammeName() {
        if (typeof this.name !== 'string') {
            var sql = "SELECT * from Programmes where id = ?"
            const results = await db.query(sql, [this.id]);
            this.pName = results[0].name;
        }
    }
}

module.exports = {
    Programme,
}


```


models/student.js with additions

```javascript
// Get the functions in the db.js file to use
const db = require('./../services/db');
const { Programme } = require('./programme');
const { Module } = require('./module');

class Student {
    // Student ID
    id;
    // Student name
    name;
    // Student programme of type Programme
    programme;
    // Student modules: array of type Module
    modules = [];

    constructor(id) {
        this.id = id;
    }
    
    // Gets the student name from the database
    async getStudentName() {
        if (typeof this.name !== 'string') {
            var sql = "SELECT * from Students where id = ?"
            const results = await db.query(sql, [this.id]);
            this.name = results[0].name;
        }

    }
    
    // Gets the programme of this student
    async getStudentProgramme()  {
        if(typeof this.programme !== Programme) {
            var sql = "SELECT * from Programmes p \
            JOIN Student_Programme sp ON p.id = sp.programme \
            WHERE sp.id = ?"
            const results = await db.query(sql, [this.id]);
            this.programme = new Programme(results[0].programme);
            this.programme.pName = results[0].name;
        }
       
    }
    
    async getStudentModules() {
        var sql = "SELECT * FROM Programme_Modules pm \
        JOIN Modules m on m.code = pm.module \
        WHERE programme = ?";
        const results = await db.query(sql, [this.programme.id]);
        for(var row of results) {
            this.modules.push(new Module(row.code, row.name));
        }
    }
}

module.exports = {
    Student
}
```

student.pug

```javascript
extends layout
block content
    h1 Student page for: #{student.name}
    p The ID for the student is: #{student.id}
    h2 Programme: #{student.programme.pName} 
    h2 Modules 
    table(border=1)
        for module in student.modules 
            tr  
                td #{module.code}
                td 
                    a(href='/single-module/' + module.code) #{module.mName}


```


app.js (single student route)

```javascript


// Single student page, using MVC pattern
app.get("/student-single/:id", async function (req, res) {
    var stId = req.params.id;
    // Create a student class with the ID passed
    var student = new Student(stId);
    await student.getStudentName();
    await student.getStudentProgramme();
    await student.getStudentModules();
    console.log(student);
    res.render('student', {student:student});
});

```


