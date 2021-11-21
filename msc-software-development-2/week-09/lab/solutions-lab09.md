models/programme.js

```javacript
// Get the functions in the db.js file to use
const db = require('../services/db');

class Programme {
    // Programme ID
    id;
    // Programme name
    name;

    constructor(id, name) {
        this.id = id;
        this.name = name;
    }

    async getProgrammeName() {
        if (typeof this.name !== 'string') {
            var sql = "SELECT * from Programmes where id = ?"
            const results = await db.query(sql, [this.id]);
            this.name = results[0].name;
        }
    }
}

module.exports = {
    Programme,
}

```


models/module.js

```javascript

/ Get the functions in the db.js file to use
const db = require('../services/db');

class Module {
    // Module code
    code;
    // Module name
    name;

    constructor(code, name) {
        this.code = code;
        this.name = name;
    }

    async getModuleName() {
        if (typeof this.name !== 'string') {
            var sql = "SELECT * from Modules where code = ?"
            const results = await db.query(sql, [this.id]);
            this.name = results[0].name;
        }
    }
}

module.exports = {
    Module
}

```


Student.js with additions

```javascript
// Get the functions in the db.js file to use
const db = require('../services/db');
const { Programme } = require('./programme');
const { Module } = require('./module');

class Student {
    // Student ID
    id;
    // Student name
    name;
    // Student programme: an object of type programme
    programme;
    // Student modules
    modules = [];

    constructor(id) {
        this.id = id;
    }

    async getStudentName() {
        if (typeof this.name !== 'string') {
            var sql = "SELECT * from Students where id = ?"
            const results = await db.query(sql, [this.id]);
            this.name = results[0].name;
        }

    }

    async getStudentProgramme() {
        if(typeof this.programme !== Programme) {
            var sql = "SELECT * from Programmes p \
            JOIN Student_Programme sp ON p.id = sp.programme \
            WHERE sp.id = ?"
            const results = await db.query(sql, [this.id]);
            console.log(results);
            this.programme = new Programme(results[0].programme, results[0].name);
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


app.js (amended)

```javascript
// Get the models
const { Student } = require("./models/student");
const { Programme } = require("./models/programme");

// Task 3 single student page
app.get("/single-student/:id", function (req, res) {
    var stId = req.params.id;
    // Create a student class with the ID passed
    var student = new Student(stId);
    student.getStudentName().then(
        Promise => {
            student.getStudentProgramme().then(Promise => {
                student.getStudentModules().then(Promise => {
                    res.render('student', { student: student });
                });
            });
        });
});
```

student.pug


```
extends layout
block content
    h1 Student page for: #{student.name}
    p The ID for the student is: #{student.id}
    h2 Programme: #{student.programme.name} 
    h2 Modules 
    table(border=1)
        for module in student.modules 
            tr  
                td #{module.code}
                td 
                    a(href='/single-module/' + module.code) #{module.name}
```

