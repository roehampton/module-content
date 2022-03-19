# Create a calendar with a datepicker and store/retrieve a date and time data


### 0. Get some libraries

Date storage and formatting can be a tricky business with a lot of options.  Library code will help you. On the server side we will use a node.js library called luxon.  In a later stage we will use the jQuery libraries to build the user interface.

Install luxon

```
npm install luxon
```

Include luxon in your app.js file. Add this near the top near where you import other libraries:

```
// Add the luxon date formatting library
const { DateTime } = require("luxon");
```

Refresh your containers

```bash
docker-compose up --build
```

### 1. Create a table in your database using the mysql datetime type

(This is just an example - you can add a datetime column anywhere in your database on tables where it makes sense for you)

```sql

CREATE TABLE `test_database`.`dates` ( `date_id` INT NOT NULL AUTO_INCREMENT , `date` DATETIME NOT NULL , PRIMARY KEY (`date_id`));
```

### 2. Pull jQuery libraries into your code and add a datepicker function

In this case, The libraries and function are added to a brand new template (calendar.pug).  However a better place for the libraries and function may be in the head section in layout.pug

Create a file in the views directory called calendar.pug and add the following.  This will display a datepicker and submit button, and will also print a list of all the dates in your dates table of the database (this is just so you can see how to output dates)

```javascript
extends layout
block content
    // - jQuery plus the datepicker function are probably better placed in the layout template but they will work here
    script(src='https://ajax.googleapis.com/ajax/libs/jquery/3.6.0/jquery.min.js')
    script(src='https://ajax.googleapis.com/ajax/libs/jqueryui/1.12.1/jquery-ui.min.js')
    link(rel="stylesheet" href="//code.jquery.com/ui/1.12.1/themes/base/jquery-ui.css")
    script.
        $(function(){
            $("#datepicker").datepicker({
                dateFormat: "yy-mm-dd"
            });
        });
    // - Date picker form including submit
    form(action='/set-date', method='POST')
        input(type='text' id='datepicker' name='date')
        input(type='submit' value='Submit')
    ul
    - // Now we loop through the dates and display them
    for date in dates
        li #{date}
```

### 3. Create a route in app.js to call the calendar template

This code will call the template and also provides code to populate the list of dates, just so you can see how to retrieve and format dates

In app.js add this function:

```javascript
// Create route for the calendar
// Here we have a page which demonstrates how to both input dates and display dates
app.get("/calendar", async function(req, res) {
    // Get all the dates from the db to display
    // NB Move this to a model that is appropriate to your project
    sql = "SELECT * from dates";
    // We could format dates either in the template or in the backend
    dates = [];
    results = await db.query(sql);
    // Loop through the results from the database
    for (var row of results) {
        // For some reason the dates are fomatted as jsDates. I think thats the Mysql2 library at work!
        dt = DateTime.fromJSDate(row['date']);
        // Format the date and push it to the row ready for the template
        // NB Formatting could also be done in the template
        // NB date formats are usually set up to work throughout your app, you would not usually set this in every row.
        // you could put this in your model.
        dates.push(dt.toLocaleString(DateTime.DATE_HUGE));
    }
    // Render the calendar template, injecting the dates array as a variable.
    res.render('calendar', {dates: dates});
});
```

### 4. Create another route in app.js which will capture the input and add it to the database

In app.js, add this function

```javascript
// Capture the date input and save to the db
app.post('/set-date', async function (req, res) {
    params = req.body.date;
    console.log(params);
    //construct a date object from the submitted value - use a library
    var inputDate = DateTime.fromFormat(params, 'yyyy-M-dd');
    console.log(inputDate);
    // Add the date: NB this should be in a model somewhere
    sql = "INSERT into dates (date) VALUES (?)";
    try {
        await db.query(sql, [inputDate.toSQLDate()]);
    } catch (err) {
        console.error(`Error while adding date `, err.message);
        res.send('sorry there was an error');
    }
    res.send('date added');
});

```

Useful references on jQuery datepicker

https://www.codexworld.com/add-date-time-picker-input-field-jquery/

https://www.codexworld.com/add-datepicker-to-input-field-jquery-ui/

Luxon and timezones:
https://www.thisdot.co/blog/how-to-handle-time-zones-using-datetime-and-luxon
https://timetc.medium.com/working-with-dates-some-things-i-learned-so-far-43b9e0c8df75