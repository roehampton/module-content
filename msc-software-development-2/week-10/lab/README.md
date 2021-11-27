# Software Development 2 Lab 10 -- Adding and changing data in the database via your web front end


So far, we have looked at how you can read data from your database and display it in your front end.  

In this lab, we look at the other three functions of a CRUD system: create, update and delete.  In these functions, data in the database is actually altered.

In order to get data from the user and send it into our applications, we need to use HTML forms.  We looked at these back in in lab 2.  This was the HTML for our example form, and we also looked at the difference between the two methods for sending user data into the backend: GET and POST.

```html
<!DOCTYPE html>
<html>

<head>

</head>

<body>

  <h1>HTML Forms example</h1>

  <form action="" method="GET">
    <div>
      <label for="name">Name:</label>
      <input type="text" id="name" name="name">
    </div>
    <div>
      <label for="mail">E-mail:</label>
      <input type="email" id="mail" name="email">
    </div>
    <div>
      <label for="msg">Message:</label>
      <textarea id="msg" name="message"></textarea>
    </div>
    <button type="submit">Submit!!</button>
  </form>

  <p>If you click the "Submit" button, the form-data will be sent back to this page.
    Usually, the action sends data to a different file with scripts that can process it.</p>

</body>

</html>
```

In this lab we will start by building forms to obtain user data using pug, then we will build more routes in our express applications and in our models to alter the data in the database accordingly.

### Example 1: Adding a note to a student

#### Specification

##### User story

__As an admin I'd like to add a note to a students page with a summary of their progress so that lecturers can see an overview of the student at a glance__

##### Task list

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

This code receives the form submission, retrieves the parameters, prints them to the console for you to check and then returns a message to the user.  Rough and ready for now but tells us whats needed.


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

First lets amend app.js, single-student route to call our new getStudentDetails function

All you need to do is change...

```

    student.getStudentName().then( 
```

to

```

    student.getStudentDetails().then( 
```

Now we add to the pug template to pull through the student note

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
