# Lab week 11: Passwords and authentication


In this lab we will look at how users can log in to your site and how, via 'sessions', you can securely personalise data users see and update.
There is a screencast for this lab: [https://roehampton.cloud.panopto.eu/Panopto/Pages/Viewer.aspx?id=33ea7950-de72-4a46-8b27-adf301306b1c](https://roehampton.cloud.panopto.eu/Panopto/Pages/Viewer.aspx?id=33ea7950-de72-4a46-8b27-adf301306b1c)

## User stories

As always, we need at least some specification before we start to code.

As a user I need to set a password matched with my email address so I can log in and see private and/or personalised information

__Tasks__

 * Install session and encryption libraries
 * Create a table to hold user information with unique ids that can be be foreign keys to the Students table. 
 * Create a register form that can add new users and passwords to the table OR add a password to one of the existing users
 * Create a login form using users email address and password
 * Create backend code to set passwords for existing email addresses OR add to the Users table if the email address is new
 * Create backend code to check a users' login credentials entered in the login form
 * Implement sessions so that successfully logged in users can have private and personalised information displayed to them
 * Implement a logout link




## Getting ready

#### Add libraries

Stop your containers, run the following and then run docker-compose up --build

```
npm install express-session
npm install bcryptjs
```
NOTE:  the bcryptjs library as opposed to the bcrypt library will work best with docker on different platforms.


#### Create a table to hold user information with unique ids that can be be foreign keys to the Students table.

Run the following SQL to set up a users table. Note the 'auto increment' - adding a new row will automatically generate a new ID, but that we are adding our existing Students with an ID that matches what is in the Students table.

```sql
CREATE TABLE `Users` (
  `id` int NOT NULL,
  `email` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL
);

--
-- Dumping data for table `Users`
--

INSERT INTO `Users` (`id`, `email`, `password`) VALUES
(1, 'kevin@kevin.com', ''),
(2, 'lisa@lisa.com', ''),
(3, 'arturo@arturo.com', ''),
(4, 'Sobham@sobhan.com', '');

--
-- Indexes for table `Users`
--
ALTER TABLE `Users`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for table `Users`
--
ALTER TABLE `Users`
  MODIFY `id` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;
COMMIT;

```
## Development tasks

### Create templates and routes for your login and register forms


Create a new file ```register.pug```

```
extends layout
block content
    h1 Register here
    form(action='/set-password' method='POST')
        label(for='email') Enter your email: 
        input(name='email') 
        label(for='email') Enter your password: 
        input(name='password' type = 'password')
        input(type='submit' value='Submit')

```

Create a new file ```login.pug```

```
extends layout
block content
    h1 Login here
    form(action='/authenticate' method='POST')
        label(for='email') Enter your email: 
        input(name='email') 
        label(for='email') Enter your password: 
        input(name='password' type = 'password')
        input(type='submit' value='Submit')

```


Create routes for these in ```app.js```


```
// Register
app.get('/register', function (req, res) {
    res.render('register');
});

// Login
app.get('/login', function (req, res) {
    res.render('login');
});

```

### Add a user model with stubs for the methods we will need

Add a new file in the models directory ```/models/user.js```

```
// Get the functions in the db.js file to use
const db = require('../services/db');

class User {

    // Id of the user
    id;

    // Email of the user
    email;

    constructor(email) {
        this.email = email;
    }
    
    // Get an existing user id from an email address, or return false if not found
    async getIdFromEmail()  {
    
    }

    // Add a password to an existing user
    async setUserPassword(password) {

    }
    
    // Add a new record to the users table    
    async addUser(password) {
    
    }

    // Test a submitted password against a stored password
    async authenticate(submitted) {

    }


}

module.exports  = {
    User
}
```


Require this in the app.js file  (add near the top)

```
const { User } = require("./models/user");
```

### Add a method to test the email submitted to see if it has a valid ID

In your ```user.js``` file:

```javascript

// Checks to see if the submitted email address exists in the Users table
async getIdFromEmail() {
        var sql = "SELECT id FROM Users WHERE Users.email = ?";
        const result = await db.query(sql, [this.email]);
        // TODO LOTS OF ERROR CHECKS HERE..
        if (JSON.stringify(result) != '[]') {
            this.id = result[0].id;
            return this.id;
        }
        else {
            return false;
        }
    }

```


### Add a method to hash and store a password for an existing user



Add this to the top of user.js. This provides us with tools to encrypt and compare passwords.

```
const bcrypt = require("bcryptjs");

```

And then this method:

```javascript
 async setUserPassword(password) {
        const pw = await bcrypt.hash(password, 10);
        var sql = "UPDATE Users SET password = ? WHERE Users.id = ?"
        const result = await db.query(sql, [pw, this.id]);
        return true;
    }

```
Reference: https://www.npmjs.com/package/bcryptjs

### Add a method to hash and store the password and submitted email address for a new user

Also in user.js

```javascript

  // Add a new record to the users table
    async addUser(password) {
        const pw = await bcrypt.hash(password, 10);
        var sql = "INSERT INTO Users (email, password) VALUES (? , ?)";
        const result = await db.query(sql, [this.email, pw]);
        console.log(result.insertId);
        this.id = result.insertId;
        return true;
    }

```

### Get data from the register form and update or create user records in the backend


Add the following to app.js. 
This provides a POST route which will first check for a valid user and then add the password to an existing record if there is one (This is needed at this point only because we have email addresses in the database with now password set yet).  If no existing user is found, a new record willb e created. 

```javascript
app.post('/set-password', async function (req, res) {
    params = req.body;
    var user = new User(params.email);
    try {
        uId = await user.getIdFromEmail();
        if (uId) {
            // If a valid, existing user is found, set the password and redirect to the users single-student page
            await user.setUserPassword(params.password);
            console.log(req.session.id);
            res.send('Password set successfully');
        }
        else {
            // If no existing user is found, add a new one
            newId = await user.addUser(params.email);
            res.send('Perhaps a page where a new user sets a programme would be good here');
        }
    } catch (err) {
        console.error(`Error while adding password `, err.message);
    }
});
```

### Implement the authenticate method

in user.js

```javascript
// Test a submitted password against a stored password
async authenticate(submitted) {
        // Get the stored, hashed password for the user
        var sql = "SELECT password FROM Users WHERE id = ?";
        const result = await db.query(sql, [this.id]);
        const match = await bcrypt.compare(submitted, result[0].password);
        if (match == true) {
            return true;
        }
        else {
            return false;
        }
    }

```

in app.js, ass a post route which takes the form input, compares the password and redirects or shows an error message accordingly.

```javascript
// Check submitted email and password pair
app.post('/authenticate', async function (req, res) {
    params = req.body;
    var user = new User(params.email);
    try {
        uId = await user.getIdFromEmail();
        if (uId) {
            match = await user.authenticate(params.password);
            if (match) {
                res.redirect('/single-student/' + uId);
            }
            else {
                // TODO improve the user journey here
                res.send('invalid password');
            }
        }
        else {
            res.send('invalid email');
        }
    } catch (err) {
        console.error(`Error while comparing `, err.message);
    }
});

```



### Use sessions to allow our app to know if a user is logged in and their id
 
Add near the top of app.js

```javascript
// Set the sessions
var session = require('express-session');
app.use(session({
  secret: 'secretkeysdfjsflyoifasd',
  resave: false,
  saveUninitialized: true,
  cookie: { secure: false }
}));

```

Go back to the authenticate route, and add the following two lines in the code block that executes if a match is found.  This is how you set the session.

```javascript
req.session.uid = uId;
req.session.loggedIn = true;
// OPTIONAL: examine the session in the console
console.log(req.session.id);

```
The entire authenticate route code should look like this:


```javascript
// Check submitted email and password pair
app.post('/authenticate', async function (req, res) {
    params = req.body;
    var user = new User(params.email);
    try {
        uId = await user.getIdFromEmail();
        if (uId) {
            match = await user.authenticate(params.password);
            if (match) {
                req.session.uid = uId;
                req.session.loggedIn = true;
                console.log(req.session.id);
                res.redirect('/student-single/' + uId);
            }
            else {
                // TODO improve the user journey here
                res.send('invalid password');
            }
        }
        else {
            res.send('invalid email');
        }
    } catch (err) {
        console.error(`Error while comparing `, err.message);
    }
});


```

Write some code in app.js root route to test if the user is logged in, but seeing if the session is set as expected:


```javascript

// Create a route for root - /
app.get("/", function(req, res) {
    console.log(req.session);
    if (req.session.uid) {
		res.send('Welcome back, ' + req.session.uid + '!');
	} else {
		res.send('Please login to view this page!');
	}
	res.end();
});
```



### Logout

add to app.js

```
// Logout
app.get('/logout', function (req, res) {
    req.session.destroy();
    res.redirect('/login');
  });
  
 ```
 

## EXERCISE:

Create a personalised welcome page for a user.  Do  not include the user id in the route.  Instead, use the session object to test if the user is logged in and retrieve the ID.  HINT:  use ```req.session.uid``` to get the id and ```req.session.loggedIn``` to get the logged in status.

Note that you can add extra values to the session that may help you to build your app, typically for example a users role would be stored.


## Extra resources:

Hashing and salting passwords:
https://auth0.com/blog/hashing-in-action-understanding-bcrypt/

Sessions and cookies:
https://www.section.io/engineering-education/session-management-in-nodejs-using-expressjs-and-express-session/
