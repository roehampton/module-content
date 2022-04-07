# Software Engineering -- Adding and changing data in the database via your web front end


In this lab, we look at the other three functions of a CRUD system: create, update and delete.  In these functions, data in the database is actually altered.

In order to get data from the user and send it into our applications, we need to use HTML forms.  This was the HTML for our example form, and we also looked at the difference between the two methods for sending user data into the backend: GET and POST.

In this lab we will start by building forms to obtain user data using pug, then we will build more routes in our express applications and in our models to alter the data in the database accordingly.

### Pre-requisites

In particular, you will need to ensure that the /single-student/:id route is working as per previous lab, and the code looks like this and you have all the Modules and Programmes models completed.

```javascript
// Task 3 single student page
app.get("/single-student/:id", async function (req, res) {
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




### Example 1: Adding a note to a student

#### Specification

Before starting, lets make sure we have a specification for the new feature we are going to build.

##### User story

__As an admin I'd like to add a note to a students page with a summary of their progress so that lecturers can see an overview of the student at a glance__

##### Task list (from the user story)

   * Add a column to the student table to store the note
   * Add a textarea form field to the student template for the user to enter the note
   * Create a route in app.js so that the user input can be captured in the backend
   * Add to our backend code so that:
     * The note can be stored in the students table
     * The Student model can be updated with the new data
   * Add to the student template so that the new field can be displayed to the user
   

1.  __Add a column to the student table to store the note__

In phpmyadmin, choose your database and then enter the following in the SQL window:

```sql
ALTER TABLE Students
ADD column note text
AFTER name
```
   

2. __Add a textfield form field the student template for the user to enter the note__

You need to go into the student.pug template and add the HTML form.  
Add the following to the bottom of the students.pug template

``` 
h2 Add a note about this student
    form(action='/add-note', method='POST')
        input(type='hidden' name='id' value=student.id)
        textarea(name='note' rows=6 cols=50)
        div 
        input(type='submit' value='Submit')

```

Note that it will be indented once, as it is part of the content block.

Check the output at ```http://localhost:3000```. Use the inspector in developer tools to make sure you are getting the HTML you expect as well as the output you want.  Pay attention to the 'name' of each form field, you will need this later.

3. __Create a route in app.js so that the user input can be captured in the backend__

Add the following near the top of your app.js file (after the app variable is created), this enables express to read the body of the POST parameter sent by the form

```javascript
app.use(express.urlencoded({ extended: true }));
```

Add the following in app.js after all of your 'get' routes:

```
app.post('/add-note', function (req, res) {
    // Adding a try/catch block which will be useful later when we add to the database
    try {
        // Just a console.log for now to check we are receiving the form field values
        console.log(req.body);
     } catch (err) {
         console.error(`Error while adding note `, err.message);
     }
     // Just a little output for now
     res.send('form submitted');

});
```

This code receives the form submission (POST method), retrieves the parameters, prints them to the console for you to check and then returns a message to the user.  Rough and ready for now but tells us whats needed.


4. __Add to the backend code so that the new data is stored and updated in the model__

Remember that all of our interactions with the student data should make use of the student model.

Go to PhpMyadmin and work out the query you need to update the note value for a specific student.  I think an example is this...  test it in phpmyadmin before you add it to the code.

```sql
UPDATE Students SET note = 'asdfas' WHERE id = 2
```

Now use this in the ```student.js``` model by adding a function called addStudentNote() to the student class, which takes the note value as an argument and adds this to the database

Add a note property to the student class.  To do this, underneath the modules add:

```
    // Student note
    note;
 
```

```javascript

async addStudentNote(note) {
        var sql = "UPDATE Students SET note = ? WHERE Students.id = ?"
        const result = await db.query(sql, [note, this.id]);
        // Ensure the note property in the model is up to date
        this.note = note;
        return result;
    }
```

To call this from app.js, amend the post route you just created as follows

```javascript
app.post('/add-note', function (req, res) {
    // Get the submitted values
    params = req.body;
    // Note that we need the id to get update the correct student
    var student = new Student(params.id)
    // Adding a try/catch block which will be useful later when we add to the database
    try {
        student.addStudentNote(params.note).then(result => {
            // Just a little output for now
            res.send('form submitted');
        })
     } catch (err) {
         console.error(`Error while adding note `, err.message);
     }
});


```

Notice how our OOP, MVP pattern really helps us here to write easy to understand, re-usable, and short code!


__Now lets make sure our note data is pulled into our model so we can use it in the front end__

Lets to that at this point by refactoring the getStudentName() function to be called getStudentDetails().  We can use the same query to get the note and the name as they are in the same table.  We can further improve this code later so that we can ensure that the properties are always properly present.

Replace getStudentName() in the student class with getStudentDetails()

```
async getStudentDetails() {
        if (typeof this.name !== 'string') {
            var sql = "SELECT * from Students where id = ?"
            const results = await db.query(sql, [this.id]);
            this.name = results[0].name;
            this.note = results[0].note;
        }

    }
```

5. __Add to the student template so that the new field can be displayed to the user__

First lets amend app.js, single-student route _app.get('/single-student/:id_ to call our new getStudentDetails function

All you need to do is change...

```

    student.getStudentName().then( 
```

to

```

    student.getStudentDetails().then( 
```

Now we add a new line to the pug template to pull through the student note

In student.pug, add the following line:

```
    p Note for this student: #{student.note}
```

Now check the single-student page with a couple of different ids and ensure you can send the new data through the form and see it when you return to the single student page.


### Tidy up the user journey

A last task is to tidy up the user journey: after the form is submitted it would be much nicer if the user was returned to the single-user page from which they submitted the form.  

You can do this by amending the ```app.post('add-note)``` route code:

Instead of ```res.send('form submitted)```, redirect back to the single-student page the user was viewing with the following:

```
            res.redirect('/single-student/' + params.id);

```


### Example 2: Changing a student's Programme

#### Specification

Before we begin a task, we must make sure that we have a full specification and break down of tasks.

##### User story

__As an administrator, I need to re-assign a programme to a student so that students can change from one programme to another__

##### Task list

* On the single-student page, provide a select dropdown list for allocating a student to a programme
* Populate the select list of available programmes from the database
* Write backend code to catch the form submission and update the database
* Tidy up the user journey by ensuring that the students' current programme shows as selected by default in the dropdown list

### Tasks

1. __On the single-student page, provide a select dropdown list for allocating a student to a programme__

Got to student.pug.  The code for adding a dropdown list is as follows.  Use placeholder values for now just to get your dropdown list right in the frontend, we'll get the actual values from the database in the next task.

```javascript
form(action='/allocate-programme', method='POST')
        select(name='programme')
            option(value=1) One
            option(value=2) Two
            option(value=3) Three
        <div>
        input(type='submit' value='Submit')
```

2.  __Populate the select list of available programmes from the database__

We will need an additional argument sent to the template which will contain the available programmes.  First lets add a function to get all programmes from the database.  We will add a file to the modules directory called ```programmes.js``` and add the following code:

```javascript
const db = require('../services/db');
const { Programme } = require('./programme');

async function getAllProgrammes() {
    var sql = "SELECT * from Programmes"
    const results = await db.query(sql);
    var rows = [];
    for (var row of results) {
    	    // Use our Programme class to neatly format the object going to the template
        rows.push(new Programme(row.id, row.name));
    }
    return rows;
}

module.exports = {
   getAllProgrammes,
}
```

In app.js, first ensure that our new code is available by adding near the top:

```javascript
const programmes = require("./models/programmes");

```


Then amend the single-student route code to simply add in the additional call that gets the list of available programmes

```javascript

app.get("/single-student/:id", async function (req, res) {
    var stId = req.params.id;
    // Create a student class with the ID passed
    var student = new Student(stId);
    await student.getStudentDetails();
    await student.getStudentProgramme();
    await student.getStudentModules();
    resultProgs = await programmes.getAllProgrammes();
    console.log(student);
    res.render('student', {'student':student, 'programmes':resultProgs});
});

```

Now add the dynamic code to the template student.pug in place of the placeholder code for the select list and add the hidden form field for the id:

```
form(action='/allocate-programme', method='POST')
        input(type='hidden' name='id' value=student.id)
        select(name='programme')
            for programme in programmes
                option(value=programme.id) #{programme.name}
        <div>
        input(type='submit' value='Submit')
```

use developer tools to check that that value part of each element in the select list is correctly set to the programme code as this is the unique key we will use when adding to the database.

3. __Write backend code to catch the form submission and update the database__


Add a post route to app.js to catch this form submission.  In app.js, write the following to create and test the new route
        input(type='hidden' name='id' value=student.id)
```
// A post route to recieve new data for a students' programme
app.post('/allocate-programme', function (req, res) {
    params = req.body;
    console.log(params.programme);
    res.send('form submitted');
});
```

Try submitting the form and see if you get the value you expect in the console.

Add an updateStudentProgramme to the student class in your models directory.  Lets take a bit of care here... On the assumpation that there is a business rule that says that a student can only be allocated to one programme, we need to take a few steps:

1. Check if the student is already allocated to a programme
2. If they are, remove that record from the Student_Programme table
3. Add a new record to the Student_Programme table

For 1, we can use the function we have.
For 2, create the following in students.js

```javascript
 async deleteStudentProgramme(programme) {
        var sql = "DELETE FROM Student_Programme WHERE id = ?";
        const result = await db.query(sql, [this.id]);
        // Ensure the note property in the model is up to date
        this.programme = '';
        return result;
    }javascript


```

For 3: create the following:

```javascript
async addStudentProgramme(programme) {
        var sql = "INSERT INTO Student_Programme (id, programme) VALUES (?, ?)";
        const result = await db.query(sql, [this.id, programme]);
        // Ensure the note property in the model is up to date
        this.programme = programme;
        return result;
    }

```

Combine existing class methods to get some robust functionality in the updateStudentProgramme() method

```javascript
    async updateStudentProgramme(programme) {
        const existing  = await this.getStudentProgramme();
        if(this.programme) {
            await this.deleteStudentProgramme(programme);
        }
        await this.addStudentProgramme(programme);
    }
```

See how we can use the behaviours and properties of the class to build up complex functionality with small amounts fo well organised code.

Now in app.js:

```javascript
// A post route to recieve new data for a students' programme
app.post('/allocate-programme', function (req, res) {
    params = req.body;
    var student = new Student(params.id)
    // Adding a try/catch block which will be useful later when we add to the database
    try {
        student.updateStudentProgramme(params.programme).then(result => {
            res.redirect('/single-student/' + params.id);
        })
     } catch (err) {
         console.error(`Error while adding programme `, err.message);
     }
});
```

Test that at http://localhost:3000


4. __Tidy up the user journey by ensuring that the students' current programme shows as selected by default in the dropdown list__

The dropdown list in the template is misleading, because it doesn't indicate the current value of the programme. fix this by amending the new code in the template as follows, making use of the conditional syntax of pug and using the 'selected' attribute you can give it to the options which will make that option selected by default.

```javascript
form(action='/allocate-programme', method='POST')
        input(type='hidden' name='id' value=student.id)
        select(name='programme')
            for programme in programmes
                if programme.id == student.programme.id
                    option(value=programme.id selected='selected') #{programme.name}
                else
                    option(value=programme.id) #{programme.name}
        <div>
        input(type='submit' value='Submit')
```
