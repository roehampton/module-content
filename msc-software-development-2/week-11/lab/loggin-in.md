# Lab week 11: Passwords and authentication


In this lab we will look at how users can log in to your site and how, via 'sessions', you can securely personalise data users see and update.


## Getting ready

#### You will need some new libraries.

Stop your containers, run the following and then run docker-compose up --build

```
npm install express-session
npm install express-flash
npm install bcrypt
```

#### Add a users table, and pre-populate with the user IDs we have already (to help us test)

Normally, you will have a separate users table, and your

```sql
CREATE TABLE `Users` (
  `id` int NOT NULL,
  `email` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Dumping data for table `Users`
--

INSERT INTO `Users` (`id`, `email`, `password`) VALUES
(1, 'kevin@kevin.com', ''),
(2, 'lisa@lisa.com', ''),
(3, 'arturo@arturo.com', ''),
(4, 'Sobham@sobhan.com', '');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `Users`
--
ALTER TABLE `Users`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `Users`
--
ALTER TABLE `Users`
  MODIFY `id` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;

```

## Create templates and routes for your login and register forms

#### Register form

register.pug

```
extends layout
block content
    h1 Register here
    form(action='/register' method='POST')
        label(for='email') Enter your email: 
        input('name'='email') 
        label(for='email') Enter your password: 
        input('name'='password')
        input(type='submit' value='Submit')


```

login.pug

```

extends layout
block content
    h1 Login here
    form(action='/login' method='POST')
        label(for='email') Enter your email: 
        input('name'='email') 
        label(for='email') Enter your password: 
        input('name'='password')
        input(type='submit' value='Submit')
```



app.js

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

### Add a user model with stubs for setPassword and authenticate

/models/user.js

```
// Get the functions in the db.js file to use
const db = require('../services/db');

class User {

    // Id of the user
    id;

    // Email of the user
    email;

    constructor(password) {
        this.password = password;
    }


    async setUserPassword(password) {

    }

    async authenticate(password) {

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

```javascript

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


### Add a method to 'hash' and store a password



Add this to the top of user.js

```
const bcrypt = require("bcrypt");

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
Reference: https://www.npmjs.com/package/bcrypt

This to app.js to check for a valid user and then check the pw (rigth now this will only work for users we have already added to our users table.)

```javascript
app.post('/set-password', function (req, res) {
    params = req.body;
    var user = new User(params.email);
    console.log(user);
    try {
        user.getIdFromEmail().then( uId => {
            if(uId) {
                user.setUserPassword(params.password).then ( result => {
                    res.redirect('/single-student/' + uId);
                });
            }
            else {
                // TODO call a new adduser function
                res.send('invalid email');
            }
        })
     } catch (err) {
         console.error(`Error while adding password `, err.message);
     }
});

```

### Implement the authenticate method

in users.js

```javascript
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

in app.js

```javascript
app.post('/authenticate', function (req, res) {
    params = req.body;
    var user = new User(params.email);
    try {
        user.getIdFromEmail().then(uId => {
            if (uId) {
                user.authenticate(params.password).then(match => {
                    if (match) {
                        res.redirect('/single-student/' + uId);
                    }
                    else {
                        res.send('invalid password');
                    }
                });
            }
            else {
                res.send('invalid email');
            }
        })
    } catch (err) {
        console.error(`Error while comparing `, err.message);
    }
});

```



### Set a session cookie 
in top of app.js

```javascript
// Set the sessions
var session = require('express-session');
app.set('trust proxy', 1) // trust first proxy
app.use(session({
  secret: 'xxxyyy',
  resave: false,
  saveUninitialized: true,
  cookie: { secure: false }
}))


```

in the authenticate route:

```javascript
// Check a submitted creds
app.post('/authenticate', function (req, res) {
    params = req.body;
    var user = new User(params.email);
    try {
        user.getIdFromEmail().then(uId => {
            if (uId) {
                user.authenticate(params.password).then(match => {
                    if (match) {
                        req.session.uid = uId;
                        req.session.loggedIn = true;
                        res.redirect('/single-student/' + uId);
                    }
                    else {
                        // req.flash('No email found');
                        res.send('invalid password');
                    }
                });
            }
            else {
                res.send('invalid email');
            }
        })
    } catch (err) {
        console.error(`Error while comparing `, err.message);
    }
});


```

Check it...


```javascript

/ Create a route for root - /
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

```
// Logout
app.get('/logout', function (req, res) {
    req.session.destroy();
    res.redirect('/login');
  });
  
 ```
 
TODO create a personalised welcome page with NO uid in the route but taking it from the session instead


