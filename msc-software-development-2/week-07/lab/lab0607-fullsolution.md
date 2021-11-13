Complete app.js file for labs weeks 6 and 7


```javascript

// Import express.js
const express = require("express");

// Create express app
var app = express();

// Add static files location
app.use(express.static("static"));

// Get the functions in the db.js file to use
const db = require('./services/db');

// Create a route for root - /
app.get("/", function(req, res) {
    res.send("Hello world!");
});


// Task 1 JSON formatted listing of students
app.get("/all-students", function(req, res) {
    var sql = 'select * from Students';
    // As we are not inside an async function we cannot use await
    // So we use .then syntax to ensure that we wait until the 
    // promise returned by the async function is resolved before we proceed
    db.query(sql).then(results => {
        console.log(results);
        res.json(results);
    });

});

// Task 2 display a formatted list of students
app.get("/all-students-formatted", function(req, res) {
    var sql = 'select * from Students';
    // As we are not inside an async function we cannot use await
    // So we use .then syntax to ensure that we wait until the 
    // promise returned by the async function is resolved before we proceed
    var output = '<table border="1px">';
    db.query(sql).then(results => {
        for (var row of results) {
            output += '<tr>';
            output += '<td>' + row.id + '</td>';
            output += '<td>' + '<a href="./single-student/' + row.id + '">' + row.name + '</a>' + '</td>';
            output += '</tr>'
        }
        output+= '</table>';
        res.send(output);
    });
});

// Task 3 single student page
app.get("/single-student/:id", function (req, res) {
    var stId = req.params.id;
    console.log(stId);
    var stSql = "SELECT s.name as student, ps.name as programme, \
    ps.id as pcode from Students s \
    JOIN Student_Programme sp on sp.id = s.id \
    JOIN Programmes ps on ps.id = sp.programme \
    WHERE s.id = ?";
    var modSql = "SELECT * FROM Programme_Modules pm \
    JOIN Modules m on m.code = pm.module \
    WHERE programme = ?";
    db.query(stSql, [stId]).then(results => {
        console.log(results);
        var pCode = results[0].pcode;
        output = '';
        output += '<div><b>Student: </b>' + results[0].student + '</div>';
        output += '<div><b>Programme: </b>' + results[0].programme + '</div>';

        //Now call the database for the modules
        db.query(modSql, [pCode]).then(results => {
            output += '<table border="1px">';
            for (var row of results) {
                output += '<tr>';
                output += '<td><a href="/single-module/' + row.module + '">' + row.module + '</a></td>';
                output += '<td>' + row.name + '</td>';
                output += '</tr>'
            }
            output+= '</table>';
            res.send(output);
            
        });

    });

});


//Independent task 1: JSON output of all programmes
app.get("/all-programmes", function(req, res) {
    var sql = 'select * from Programmes';
    // As we are not inside an async function we cannot use await
    // So we use .then syntax to ensure that we wait until the 
    // promise returned by the async function is resolved before we proceed
    db.query(sql).then(results => {
        console.log(results);
        res.json(results);
    });

});

// Task 2 display a formatted list of programmes with each linked by ID
app.get("/programmes", function(req, res) {
    var sql = 'select * from Programmes';
    var output = '<table border="1px">';
    db.query(sql).then(results => {
        for (var row of results) {
            output += '<tr>';
            output += '<td>' + row.id + '</td>';
            output += '<td>' + '<a href="./single-programme/' + row.id + '">' + row.name + '</a>' + '</td>';
            output += '</tr>'
        }
        output+= '</table>';
        res.send(output);
    });
});


// Task 3 single programme page
app.get("/single-programme/:id", function (req, res) {
    var pCode = req.params.id;
    output = '';
    output += "<h1>Programme</h1>";
    //Get the programme title
    var pSql = "SELECT * FROM Programmes WHERE id = ?";
    db.query(pSql, [pCode]). then(results => {
        output += results[0].name;
    });
    //Now call the database for the modules
    //Why do you think that the word modules is coming in before the name of the programme??
    var modSql = "SELECT * FROM Programme_Modules pm \
    JOIN Modules m on m.code = pm.module \
    WHERE programme = ?";
    output += "<h2>Modules</h2>";
    db.query(modSql, [pCode]).then(results => {
        output += '<table border="1px">';
        for (var row of results) {
            output += '<tr>';
            output += '<td><a href="/single-module/' + row.code + '">' + row.module + '</a></td>';
            output += '<td>' + row.name + '</td>';
            output += '</tr>'
        }
        output+= '</table>';
        res.send(output);     
    });

});

// Task 6 single module page with programme and students for the module
app.get("/single-module/:id", function (req, res) {
    var mCode = req.params.id;
    output = '';
    output += "<h1>Module</h1>";
    //Get the module title
    var pSql = "SELECT * FROM Modules WHERE code = ?";
    db.query(pSql, [mCode]). then(results => {
        output += results[0].name;
    });
    //Now call the database for the programmes that have this module
    var pSql = "SELECT * FROM `Programme_Modules` pm \
    JOIN Programmes p ON p.id = pm.programme\
    WHERE module = ?";
    output += "<h2>Programmes with this module</h2>";
    var programmes = [];
    db.query(pSql, [mCode]).then(results => {
        output += '<table border="1px">';
        for (var row of results) {
            programmes.push(row.programme);
            output += '<tr>';
            output += '<td><a href="/single-programme/' + row.programme + '">' + row.name + '</a></td>';
            output += '<td>' + row.name + '</td>';
            output += '</tr>'
        }
        output += '</table>';

        // Now the students
        // Now call the database for the students in the module for each programme as there is a problem with the IN query

        // Generate placeholders - shouldnt be necessary!
        var placeholders = '';
        for (var prog of programmes) {
            placeholders += '?,'
        }
        placeholder = placeholders.replace(/,\s*$/, "");

        var sSql = "SELECT * FROM `Student_Programme` sp JOIN `Students` s on s.id = sp.id WHERE `programme` IN (" + placeholder + ")";
        output += "<h2>Students on this module</h2>";
        db.query(sSql, programmes).then(results => {
            output += '<table border="1px">';
            for (var row of results) {
                output += '<tr>';
                output += '<td><a href="/single-student/' + row.id + '">' + row.name + '</a></td>';
                output += '<td>' + row.programme + '</td>';
                output += '</tr>'
            }
            output += '</table>';
            res.send(output);

        });

    });

});

// Create a route for testing the db
app.get("/db_test", function(req, res) {
    // Assumes a table called test_table exists in your database
    var sql = 'select * from test_table';
    // As we are not inside an async function we cannot use await
    // So we use .then syntax to ensure that we wait until the 
    // promise returned by the async function is resolved before we proceed
    db.query(sql).then(results => {
        console.log(results);
        res.json(results)
    });
});

// Create a route for /goodbye
// Responds to a 'GET' request
app.get("/goodbye", function(req, res) {
    res.send("Goodbye world!");
});

// Create a dynamic route for /hello/<name>, where name is any value provided by user
// At the end of the URL
// Responds to a 'GET' request
app.get("/hello/:name", function(req, res) {
    // req.params contains any parameters in the request
    // We can examine it in the console for debugging purposes
    console.log(req.params);
    //  Retrieve the 'name' parameter and use it in a dynamically generated page
    res.send("Hello " + req.params.name);
});

// Start server on port 3000
app.listen(3000,function(){
    console.log(`Server running at http://127.0.0.1:3000/`);
});
```