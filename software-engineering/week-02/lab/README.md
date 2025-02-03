# Software Engineering: Setting up a development environment with Docker

## Prerequisites

You will need to add to your development environment to enable you to work across all of our server-side software.

We use the industry  standard tool, Docker, to build a consistent cross-platform development environment.

## Installing Docker (if you are using your own computer)

#### On Windows

https://docs.docker.com/desktop/install/windows-install/

When you install Docker Desktop, ensure that 'Use WSL 2 based engine' is selected.

In case WSL is missing (it should be installed with Docker Desktop), go to the instructions at the bottom of this sheet


#### On Mac

You should simply be able to install docker from the Docker.dmg file in the normal way: https://docs.docker.com/desktop/install/mac-install/
Make sure you also have node.js installed


#### On Linux

https://docs.docker.com/desktop/install/linux-install/

## Testing Docker

To test if Docker is correctly installed

1. Open VS code
2. Open a terminal window in VS code
3. Type
   ```
   docker run hello-world
   ```
You should see a Docker image being pulled and a message displayed informing you that Docker is running correctly.


## Docker development environment quickstart

__The video for the quickstart set up described below is here: [https://roehampton.cloud.panopto.eu/Panopto/Pages/Viewer.aspx?id=c98901e7-f193-4b9b-b071-af3e018163fb](https://roehampton.cloud.panopto.eu/Panopto/Pages/Viewer.aspx?id=c98901e7-f193-4b9b-b071-af3e018163fb)__

The video takes you through from step 2.

1. Ensure Docker is installed on your computer OR use the azure virtual machine installation.
2. Download the zip file of the startup files (labelled Scaffolding files in Moodle), and extract it.
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


To log in to Phpmyadmin you need the shared database credentials. These are found in the ``` .env ``` file.  Try using the root user and root password.


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
   2. Access Phpmyadmin by going to http://127.0.0.1:8081. (use the credentials in the .env file)
   3. Click onto the sd2-test database in the left side, and, using the SQL    window, paste the contents of the SQL file there.  Click run. You will now have some content for the test table
   4. Access http://127.0.0.1:3000/db_test to see the contents of the table

## Known Gotchas with Docker

1. Do not try to run Docker from any onedrive mounted location
2. __Do not try to install any additional software on uni computers__ - everything is there already and trying to install Docker again breaks everything
3. On any mac, docker-compose may fail.  Remove the sqlite3 package with ```npm remove sqlite3``` and all should be well
4. On students' own laptops, they may be prompted to re-install or update wsl.  Follow the instruction given and restart. This usually works.
5. On windows, restart after installation of Node and docker desktop to ensure changes are picked up.
  

