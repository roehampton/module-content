# Lab 03b: Requirements and Issues

In this lab we will use GitHub issues to start tracking our work.  This is stage one of starting a Kanban system to monitor our work.  We will start by defining our **Vision** for the application, using this to define **features**, and from these **User Stories**.

## Behavioural Objectives

After this lab you will be able to:

- [ ] **Create** *issues on GitHub*.
- [ ] **Define** a *basic user story.*
- [ ] **Create** a *composed Docker service using Docker Compose.*
- [ ] **Use** an *SQL database from Java.*

## Vision Statement

Here is a cut-down Vision Statement for the product we will develop in the labs:

### Introduction

#### Purpose

The purpose of the application is to manage employee records for a company.  The system will primarily used by the Human Resources Department (HR) and managers.  An existing SQL database exists with this data.

#### Solution Overview

The application will provide a front-end to the employee database with the ability to add, delete, and update records.  This will allow the HR team to be more efficient in processing employee data, and provide managers with information about current salary and role quickly for appraisal meetings.

### User Description

The users are mainly HR advisors who have limited technical knowledge and require reports to be produced and employee records updated.  The HR advisors work via web interfaces mainly, although a desktop application linked to a server is a possible work-around.

### Features

#### Produce a Salary Report

The application will produce a report on the current salary of all employees (HR), employees in a department (HR and department manager), and employees by job title (HR).  The current salary reports are used in financial reporting and planning.

#### Add a New Employee

The application will allow HR advisors to add a new employee when they start.  This is to ensure new employees are paid.

#### View an Employee Record

The application will allow an HR advisor of department manager to view the record for an employee in a department.  The view is used during any promotion request.

#### Update an Employee Record

The application will allow an HR advisor to update an employee record.  This is to ensure records are kept up-to-date.

#### Delete an Employee Record

The application will allow an HR advisor to delete an employee record.  This is to ensure the organisation does not retain date it no longer needs.

## Getting Started

You need to set-up your application.  Check that everything works after you've pulled down your code.

## Defining User Stories

Our job is to define the initial requirements for the system to be developed.  We will do this by specifying **User Stories** for more details).  A user story has the following form:

> As a *role* I want *feature* so that *value*.

From the vision statement, we can define the following initial user stories:

1. As an *HR advisor* I want *to produce a report on the salary of all employees* so that *I can support financial reporting of the organisation.*
2. As an *HR advisor* I want *to produce a report on the salary of employees in a department* so that *I can support financial reporting of the organisation.*
3. As an *department manager* I want *to produce a report on the salary of employees in my department* so that *I can support financial reporting for my department.*
4. As an *HR advisor* I want *to produce a report on the salary of employees of a given role* so that *I can support financial reporting of the organisation.*
5. As an *HR advisor* I want *to add a new employee's details* so that *I can ensure the new employee is paid.*
6. As an *HR advisor* I want *to view and employee's details* so that *the employee's promotion request can be supported.*
7. As an *HR advisor* I want *to update an employee's details* so that *employee's details are kept up-to-date.*
8. As an *HR advisor* I want *to delete an employee's details* so that *the company is compliant with data retention legislation.*

From an initial pass we have eight features to implement.  We will break down these tasks further as required.

### GitHub Issues

We are going to use GitHub issues to track our User Stories.  From the main GitHub page for your repository you will see **Issues** on the toolbar:

![GitHub Toolbar](img/github-toolbar.png)

**Select the Issues tab**.  This will open the *Issues window*:

![GitHub Issues](img/github-issues.png)

**Click the New Issue button**.  We can now add a new issue.  We will add the first User Story above:

![GitHub New Issue](img/github-new-issue.png)

**Click Submit New Issue**.  Your issue will be added to GitHub.

### Exercise

Add the other seven User Stories as GitHub issues.

## Working on a Feature

We will now work on a User Story.  The simplest one is:

6. As an *HR advisor* I want *to view and employee's details* so that *the employee's promotion request can be supported.*

First, **create a new branch from `develop` called `feature/view-record`**.  This will be our work branch to add this feature.

The User Story contains a number of tasks we need to extract:

1. Connect to the existing database.
2. Add function to extract employee record based on ID.
3. Display the employee record.

For Task 1 we have to have a database of employee data.  We will use the *MySQL Employee Sample Database* provided on [GitHub](https://github.com/datacharmer/test_db) (instructions [here](https://dev.mysql.com/doc/employee/en/)).  To use this, we will have to switch our database container to MySQL, upload the sample data, and integrate with our existing application.  To make this easier, we will use **Docker Compose**.

## Docker Compose

Docker Compose allows us to define a collection of containers that operate together.  We are going to have two containers: a **MySQL** container and an **Application** container.  First, we need to define our database in our application.

### Add Database Support

A Docker container [is available for MySQL](https://hub.docker.com/_/mysql/).  That is the easy part.  What we need to do is add an existing database to the container.  We can do this in a Dockerfile if we have the database on the local file system.  We can get the database from GitHub, and we can incorporate an external Git **submodule** easily.  Let us do that first.

#### Git Submodules

A **Git Submodule** is when we have other Git repositories linked to our main one.  This is useful when we want to include external libraries in our build pipeline.  Git submodules are not included in the tracking of the local repository, so do not add anything to your main repository.  Unfortunately, IntelliJ is not very good at managing submodules, so we will have to do this in the terminal.  IntelliJ does provide a terminal - there is a tab at the bottom:

![IntelliJ Terminal](img/intellij-terminal.png)

From the terminal we need to execute the following two commands:

```shell
git submodule add https://github.com/datacharmer/test_db db/test_db
git submodule init
git submodule update
```

This will create a `.gitmodules` file to the root of the project folder.  The contents of this file are:

```
[submodule "db/test_db"]
path = db/test_db
url = https://github.com/datacharmer/test_db
```

This will add the files from example SQL database to the folder `db/test_db` once we initialise the Git submodule.

Git will pull the repository.  You should now have the `db/test_db` folder.

#### Dockerfile for Database

Next we need a Dockerfile to run a MySQL database instance with the given files.  The following `Dockerfile` should be stored in the `db` folder:

```dockerfile
# Use the latest MySQL image
FROM mysql
# Set the working directory
WORKDIR /tmp
# Copy all the files to the working directory of the container
COPY test_db/*.sql /tmp/
COPY test_db/*.dump /tmp/
# Copy the main SQL file to docker-entrypoint-initdb.d.
# Scripts and SQL files in this folder are executed on container startup.
# This is specific to MySQL.
COPY test_db/employees.sql /docker-entrypoint-initdb.d
# Set the root password
ENV MYSQL_ROOT_PASSWORD example
```

The comments explain what the Dockerfile does.

#### Test Database

We are now in a position to test that our database works.  To do this, just click the green play button in the database Dockerfile and select `Run on Docker`.  Look at the **Log** (give it some time to get finished), and you should see:

```shell
...
mysql: [Warning] Using a password on the command line interface can be insecure.
INFO
CREATING DATABASE STRUCTURE
INFO
storage engine: InnoDB
INFO
LOADING departments
INFO
LOADING employees
INFO
LOADING dept_emp
INFO
LOADING dept_manager
INFO
LOADING titles
INFO
LOADING salaries
```

Now you should commit this change and push it to the remote.  We have completed part of the new feature add.

### Add Docker Compose File

Now we can create a **Docker Compose** file.  This is a configuration file that has more than one service defined.  We want to have our application and our database services up and running.  Therefore, our initial file (saved in `docker-compose.yml` in the root) is as follows:

```yml
version: '3'
services:
  # Application Dockerfile is in same folder which is .
  app:
    build: .

  # db is is db folder
  db:
    build: db/.
    command: --default-authentication-plugin=mysql_native_password
    restart: always
```

When running Docker from the command line, we use `docker compose up` to build and run a composed service.  IntelliJ understands Docker compose files, so we don't have to worry.  We will modify our Travis CI file.

### Test MySQL Connection

First, we need to update the `pom.xml` file to add MySQL support.  Open the file in IntelliJ and add the following to the dependancies:

```xml
<dependencies>
    <dependency>
        <groupId>mysql</groupId>
        <artifactId>mysql-connector-java</artifactId>
        <version>5.1.44</version>
    </dependency>
</dependencies>
```

Now we need to update our main application to move from MongoDB to MySQL.  A MySQL server takes a bit more time to start-up, so we need to have code to attempt to connect multiple times.  The Java code below is our new application.

```java
package com.napier.sem;

import java.sql.*;

public class App
{
    public static void main(String[] args)
    {
        try
        {
            // Load Database driver
            Class.forName("com.mysql.jdbc.Driver");
        }
        catch (ClassNotFoundException e)
        {
            System.out.println("Could not load SQL driver");
            System.exit(-1);
        }

        // Connection to the database
        Connection con = null;
        int retries = 100;
        for (int i = 0; i < retries; ++i)
        {
            System.out.println("Connecting to database...");
            try
            {
                // Wait a bit for db to start
                Thread.sleep(30000);
                // Connect to database
                con = DriverManager.getConnection("jdbc:mysql://db:3306/employees?useSSL=false", "root", "example");
                System.out.println("Successfully connected");
                // Wait a bit
                Thread.sleep(10000);
                // Exit for loop
                break;
            }
            catch (SQLException sqle)
            {
                System.out.println("Failed to connect to database attempt " + Integer.toString(i));
                System.out.println(sqle.getMessage());
            }
            catch (InterruptedException ie)
            {
                System.out.println("Thread interrupted? Should not happen.");
            }
        }

        if (con != null)
        {
            try
            {
                // Close connection
                con.close();
            }
            catch (Exception e)
            {
                System.out.println("Error closing connection to database");
            }
        }
    }
}
```

Now we can test the application and MySQL database together by undertaking the following steps:

1. Compile the application.
2. Package the application.
3. Deploy the composed Docker services - we do this by running the `docker-compose.yml` file as any other Dockerfile.
4. Wait for the application to start-up.
5. Check that "Successfully Connected" is displayed.

### Update Travis File

Now we can update our Travis file to use the Docker compose file.  This is below:

```yml
sudo: required

language: java

services:
  - docker

after_success:
  - docker-compose up --abort-on-container-exit
```

The `--abort-on-container-exit` parameter tells Docker to stop all services once one container has finished.  This will gracefully exit the MySQL container when the main application exits in Travis CI.

### Push Changes

With our files updated we can test that our CI build still works.  To do this, follow the following two steps:

1. Commit the file changes.
2. Push the changes to your GitHub repository.

And that is it.

### Check CI Build

Finally log into Travis and check that the build is successful.  Hopefully you will get something as follows:

![Successful Travis Build](img/travis-success.png)

And we have successfully connected to our existing database.  That is task one of our user story completed.  Let us now move onto the next task - extracting an employee's information.

## Extract Employee Information

Our next step is to extract an employee's information from the SQL database.  Looking at the [information](https://dev.mysql.com/doc/employee/en/employees-introduction.html) about the database we can determine an initial SQL query as:

```sql
SELECT emp_no, first_name, last_name
FROM employees
WHERE emp_no = <ID>
```

Hopefully you remember these basic ideas from database systems.  Constructing this query string is easy.  First we will extract our current application behaviour to make our good easier to work with.

### Extracting Connect and Disconnect Functionality

At the moment we have two pieces of behaviour: connecting to the database and disconnecting from the database.  We can separate these behaviours into two methods: `connect` and `disconnect`:

```java
    /**
     * Connection to MySQL database.
     */
    private Connection con = null;

    /**
     * Connect to the MySQL database.
     */
    public void connect()
    {
        try
        {
            // Load Database driver
            Class.forName("com.mysql.jdbc.Driver");
        }
        catch (ClassNotFoundException e)
        {
            System.out.println("Could not load SQL driver");
            System.exit(-1);
        }

        int retries = 10;
        for (int i = 0; i < retries; ++i)
        {
            System.out.println("Connecting to database...");
            try
            {
                // Wait a bit for db to start
                Thread.sleep(30000);
                // Connect to database
                con = DriverManager.getConnection("jdbc:mysql://db:3306/employees?useSSL=false", "root", "example");
                System.out.println("Successfully connected");
                break;
            }
            catch (SQLException sqle)
            {
                System.out.println("Failed to connect to database attempt " + Integer.toString(i));
                System.out.println(sqle.getMessage());
            }
            catch (InterruptedException ie)
            {
                System.out.println("Thread interrupted? Should not happen.");
            }
        }
    }

    /**
     * Disconnect from the MySQL database.
     */
    public void disconnect()
    {
        if (con != null)
        {
            try
            {
                // Close connection
                con.close();
            }
            catch (Exception e)
            {
                System.out.println("Error closing connection to database");
            }
        }
    }
```

As we update our application you will see why this change is useful.  Next we will test the new version of the application:

### Updated Main

The updated `main` method is as follows:

```java
    public static void main(String[] args)
    {
        // Create new Application
        App a = new App();

        // Connect to database
        a.connect();

        // Disconnect from database
        a.disconnect();
    }
```

We now create an `App` object and call `connect` and `disconnect` on the object.  This is fundamentally the same as the previous application version.  Run it to test.

#### Commit the Change

Even this small change is a commit point through our history.  Create a new commit with these changes and push it to GitHub.

### Getting an Employee

We are now ready to add a new method to extract the employee information.  To make life easier, we will create an `Employee` class.  To do this, perform the following steps:

1. **Right-click** on the **com.sem.napier** package in the **Project** explorer in IntelliJ.
2. Select **New**, **Java Class** to open the **Create New Class** window.
3. Call the class **Employee** and click **OK**.

We are now ready to add the `Employee` class.

#### Employee Class

The `Employee` class is just data.  The full code listing is given below, and should be straightforward to understand.

```java
package com.napier.sem;

/**
 * Represents an employee
 */
public class Employee
{
    /**
     * Employee number
     */
    public int emp_no;

    /**
     * Employee's first name
     */
    public String first_name;

    /**
     * Employee's last name
     */
    public String last_name;

    /**
     * Employee's job title
     */
    public String title;

    /**
     * Employee's salary
     */
    public int salary;

    /**
     * Employee's current department
     */
    public String dept_name;

    /**
     * Employee's manager
     */
    public String manager;
}
```

#### Get Employee Method

We can now extract employee information from the database.  Remember our SQL statement:

```sql
SELECT emp_no, first_name, last_name
FROM employees
WHERE emp_no = <ID>
```

The method will therefore:

- Return an *Employee* (or `null`).
- Requires an *ID* to lookup (and `int`).

Working with SQL in Java requires a bit of knowledge.  A [more comprehensive tutorial](https://www.tutorialspoint.com/jdbc/) covers the details.  Here we will cover the following points:

- Create a SQL statement - a `Statement` object from the database connection.
- Define the SQL query string to execute.
- Execute a query (`executeQuery`) to extract data from the database.  This will return a `ResultSet` object.
- Test that the `ResultSet` has a value - call `next` on the `ResultSet` and check this is `true`.
- Extract the information from the current record in the `ResultSet` using `getInt` for integer data, `getString` for string data, etc.

The code for `getEmployee` is below.  Read the description above to understand the lines of code provided.

```java
    public Employee getEmployee(int ID)
    {
        try
        {
            // Create an SQL statement
            Statement stmt = con.createStatement();
            // Create string for SQL statement
            String strSelect =
                    "SELECT emp_no, first_name, last_name "
                    + "FROM employees "
                    + "WHERE emp_no = " + ID;
            // Execute SQL statement
            ResultSet rset = stmt.executeQuery(strSelect);
            // Return new employee if valid.
            // Check one is returned
            if (rset.next())
            {
                Employee emp = new Employee();
                emp.emp_no = rset.getInt("emp_no");
                emp.first_name = rset.getString("first_name");
                emp.last_name = rset.getString("last_name");
                return emp;
            }
            else
                return null;
        }
        catch (Exception e)
        {
            System.out.println(e.getMessage());
            System.out.println("Failed to get employee details");
            return null;
        }
    }
```

Now run the application and hopefully you will get no errors.

#### Push Update

Once again, it is time to commit your updates.  Do so now.

## Display Employee Information

We cannot really test our get employee functionality until we display the output.  At the moment, we will just display to the console.  The `displayEmployee` method for our `App` is below:

```java
    public void displayEmployee(Employee emp)
    {
        if (emp != null)
        {
            System.out.println(
                    emp.emp_no + " "
                    + emp.first_name + " "
                    + emp.last_name + "\n"
                    + emp.title + "\n"
                    + "Salary:" + emp.salary + "\n"
                    + emp.dept_name + "\n"
                    + "Manager: " + emp.manager + "\n");
        }
    }
```

And we can now update our `main` to test the application:

```java
    public static void main(String[] args)
    {
        // Create new Application
        App a = new App();

        // Connect to database
        a.connect();
        // Get Employee
        Employee emp = a.getEmployee(255530);
        // Display results
        a.displayEmployee(emp);

        // Disconnect from database
        a.disconnect();
    }
```

And running this version of the application will give us:

```shell
Connecting to database...
Successfully connected
255530 Ronghao Garigliano
null
Salary:0
null
Manager: null
```

### Problems

OK, if this didn't work, try the following first:

- Make sure you have performed the following steps via Maven: **Compile** and **Package**.
- Stop all the running containers, delete them, and delete the current `sem_db` and `sem_app` Docker images.  Then rebuild everything and restart.
- Make sure the SQL connection string is correct and the logs from the running database and application.

If this doesn't solve the problem them ask for help.

### Exercise

Complete the SQL query so the employee's current (most recent) job title, salary, department, and manager is displayed.  The SQL schema diagram is available [here](https://dev.mysql.com/doc/employee/en/sakila-structure.html) for reference.  The database uses an end-date of `9999-01-01` to represent the current entry.

## Close the Issue

We can now close our issue on GitHub.  Go to GitHub, open the issues, and select the view record issue.  At the bottom of the page you will find the **Close Issue** button

![Close GitHub Issue](img/github-close-issue.png)

**Click** the button to close the issue.  And we are done.

## Close Branch and Create Release

We are now ready to merge everything together.  Remember what we did last week:

1. Updated the version number in Maven.  Remember to update the copied JAR file name in the Dockerfile as well.
2. Merged our feature branch into `develop`.
3. Merged `develop` into `release`.
4. Created a release - including version tag.
5. Merged `release` into `master`.
6. Merged `release` into `develop`.
7. Clean up.

Our current process has not changed from last week, except we are now using GitHub issues to drive our work.  Therefore we have:

1. Select an issue to work on.
2. Pull the latest `develop` branch.
3. Start a new feature branch for the issue.
4. Once feature is finished, create JAR file.
5. Update and test Docker configuration with Travis.
6. Update feature branch with `develop` to ensure feature is up-to-date.
7. Check feature branch still works.
8. Merge feature branch into `develop`.
9. Repeat 2-7 until release is ready.
10. Merge `develop` branch into `release` and create release.
11. Merge `release` into `master` and `develop`.
12. Close the issue.

## Exercise

Follow the [SQL and Java tutorial](https://www.tutorialspoint.com/jdbc/) to explore this topic further.  You will find it useful.
