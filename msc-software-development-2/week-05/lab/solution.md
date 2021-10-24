app.js


```js

// Import express.js
const express = require("express");

// Import the classes
const { Student } = require('./models/student.js');
const { Lesson } = require('./models/lesson.js');

// Create express app
var app = express();

// Create a route for root - /
app.get("/", function(req, res) {

   // Create a lesson object
   var lesson1 = new Lesson('Lisah', 'DB 218');

   // Add some student objects to the lesson
   lesson1.addStudent(new Student('Fred', 'Wright', 1));
   lesson1.addStudent(new Student('Ethan', 'Hayter', 2));
   lesson1.addStudent(new Student('Marianna', 'Voss', 1));
   lesson1.addStudent(new Student('Lizzie', 'Deigen', 1));

   // Take a peek at whats going on
   console.log(lesson1);

   // Now get the students and print them
   // Set up a string for the output
   var output = '';
   output += '<h1>Class register</h1>';
   output += '<h2><b>Teacher </b>' + lesson1.teacher + '</h2>';
   output += '<h2><b>Room </b>' + lesson1.roomNumber + '</h2>';

   //get the Students array, each element of the array will be a Student object
   var students = lesson1.getStudents();
   for (var student of students) {
       output += '<p>' + student.getFormattedName() + '</p>';
   }
   res.send(output);
});


// Start server on port 3000
app.listen(3000,function(){
    console.log(`Server running at http://127.0.0.1:3000/`);
});






```


models/lesson.js

```js
class Lesson {

    students = [];   // An array of students
    teacher;
    roomNumber;

    constructor (teacher, roomNumber)  {
        this.teacher = teacher;
        this.roomNumber = roomNumber;
    }

    addStudent(student) {
        this.students.push(student);
    }

    getStudents() {
        return this.students;
    }

}

module.exports = {
    Lesson
}

```

models/student.js

```js

class Student {
    // Attributes
    firstName;
    lastName;
    courseId;
    
    constructor(firstName, lastName, courseId) {
    
        this.firstName = firstName;
        this.lastName = lastName;
        this.courseId = courseId;
    }

    getFormattedName() {
        return this.firstName + ' ' + this.lastName;
    }
  }

  module.exports = {
      Student
  }

```