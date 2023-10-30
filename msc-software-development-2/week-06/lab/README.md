# Software Development 2: Using node.js, Express.js and connecting to MySQL

## Prerequisites

You will need to add to your development environment to enable you to work across all of our server-side software.

We use the industry  standard tool, Docker, to build a consistent cross-platform development environment.

## Installing Docker (if you are using your own computer)

#### On Windows

You need to ensure the wsl (Windows subsystem for Linux) is enabled and that you have installed the 'kernal update package'. 

Docker documentation is here  [installing Docker on Windows] (https://docs.docker.com/desktop/windows/wsl/)

In summary the steps are:

   * Enable WSL 2 on Windows: You should be able to do this via powershell with the command
   
```
wsl --install
```

   * Check that wsl is installed and the version is 2
```
  wsl --list –verbose
```

if you get an error then wsl 1 is installed and you should switch to wsl 2 iwth the command

```
wsl --set-default-version 2
```


  * Downloaded and installed the [Linux kernel update package] (https://docs.microsoft.com/windows/wsl/wsl2-kernel).

__Restart your computer when you have followed these steps__

When you install Docker Desktop, ensure that 'Use WSL 2 based engine' is selected.


#### On Mac

You should simply be able to install docker from the Docker.dmg file in the normal way: https://docs.docker.com/desktop/install/mac-install/
Make sure you also have node.js installed


#### On Linux

https://docs.docker.com/desktop/install/linux-install/



## Docker development environment quickstart

__The video for the quickstart set up described below is here: [https://roehampton.cloud.panopto.eu/Panopto/Pages/Viewer.aspx?id=c98901e7-f193-4b9b-b071-af3e018163fb](https://roehampton.cloud.panopto.eu/Panopto/Pages/Viewer.aspx?id=c98901e7-f193-4b9b-b071-af3e018163fb)__

The video takes you through from step 2.

1. Ensure Docker is installed on your computer OR use the azure virtual machine installation.
2. Download the zip file of the startup files you'be been given and extract it.
3. Move the extracted folder into your documents (win) or home (mac) directory.
2. Open a new window in VS code, choose 'open folder' and open the folder you just created. Choose, yes I trust the authors.  You should now see the startup files in your file explorer.
3. Open a new terminal in VS code
4. run 

```npm install```


5. run 

```docker-compose up```


Pulling the docker containers will take some time and you may see the server start and restart several times.  This is normal for the first startup.

6. To check everything is running visit (in your browser)

http://127.0.0.1:3000  
http://127.0.0.1:8081  

At the first address you are accessing the node.js server and at the second one, the phpmyadmin interface to MySql.


## Express.js

Before diving into database driven development, lets remember the node.js framework Express.js, which is providing us with a 'middleware' framework, receiving requests, giving us a framework for processing them which may include accessing a database, and sending back a response.  You looked at this last week.


## Checking your dynamic routes in Express.js

Find the following code in the app.js file. Use this to test that your scaffolding files are working as expected.

```
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
```

This is an example of a dynamic route. 

The ```:name``` part, indentified by the colon prefix, is not a fixed value but is instead a variable name for a 'parameter' you can then use in your code. We can retrieve the variable via the ```req.params``` object. 

Run this code by visting the following in your browser:

```
http://127.0.0.1:3000/hello/Lisa
```

Look in the console (terminal window of VS code) as you run this and see the console.log message.  You will see the name parameter and its value appended to the req.params object.


## Checking database connectivity

A number of files are provided for you which will help you connect your express app to the database.

### Check your understanding

  * __Visit the file services/db.js.  Note the following:__ 
 
   1. we require the dotenv package which is able to read configuration from the .env file
   2. We require the mysql2 package (which has some more advanced features that the mysql npm package, specifically the part that works with Promises) see: https://www.npmjs.com/package/mysql2
   3. We use the mysql configuration to create a 'pool' of connections
   4. A utility async function query() is supplied that will handle sending a query to the database and returning rows as the result. (This function is a wrapper around the Mysql2 provided execute function which itself provides useful utilities such as prepared statements and releasing a connection back to the pool).
   
```js
// Utility function to query the database
async function query(sql, params) {
  const [rows, fields] = await pool.execute(sql, params);

  return rows;
}
```
   
  * __Visit the app.js file. Note the following__
  
   1. Note that we require the db.js file to set up the database connection
   

### Create a test table and access via Express

   1. Find the sb2-test.sql file in the scaffolding files.
   2. Access Phpmyadmin by going to http://127.0.0.1:8081.
   3. Click onto the sd2-test database in the left side, and, using the SQL    window, paste the contents of the SQL file there.  Click run. You will now have some content for the test table
   4. Access http://127.0.0.1:3000/db_test to see the contents of the table
   5. Add two more rows to the test table via phpmyadmin
   6. Now amend the code in db_test so that it loops through each of the rows of the table, giving the following output:
   
Person with id 1 is Lisa

Person with id 2 is Kimia
etc

HINT:  You can use a 'for' loop to loop through each row in the results object:

```
for (var row of results) {
   // Do something with the row
   // You can access the properties of each row using the dot syntax
   // eg. row.id

}
```
  
   
   
## Further tasks
 
The next lab will develop your knowlege and skills with connecting to a database.
