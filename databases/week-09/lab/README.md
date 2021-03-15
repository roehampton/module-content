# Databases Lab 9 -- Views

<script src="https://cdn.jsdelivr.net/npm/code-line"></script>
<script>CodeLine.initOnPageLoad({toggleBtn: {show: false}, copyBtn: {show: false}})</script>

<link rel="stylesheet" href="/module-content/css/block.css">

**The content of today’s lesson is based on creating *views* and to query relevant data dictionary object to retrieve information about views.** 

`VIEW` is a logical representation of data as a subset from one or more table(s).

- A view contains no data of its own but is like a window through which data from tables can be viewed or changed.
- The tables on which a view is based are called base tables.
- The view is stored as a `SELECT` statement in the data dictionary. 

Advantages of using views.

- Views restrict access to the database because the view can display a selective portion of data from the database.
- Views allow users to make simpler queries to retrieve the results from complicated queries, for instance, views allow users to query information from multiple tables without performing joins every time
- Views provide data independence for ad-hoc users and application programs.
- One view can be used to retrieve data from several table.
- Different views of same data can be presented if required.
- Views provide groups of user access to data according to their criteria.

There are two types of views: simple and complex.  The basic difference is related to the DML (`INSERT`, `UPDATE`, and `DELETE`) operations.

- A simple view:
  - Derives data from only one table.
  - Contains no functions or groups of data.
  - Can perform DML through the view.
- A complex view:
  - Derives data from many tables.
  - Contains functions or groups of data.
  - Does not always allow DML through the view.

 ```sql
CREATE [OR REPLACE] [FORCE|NOFORCE] VIEW view[(alias[,  alias]...)]
AS subquery [WITH CHECK OPTION [CONSTRAINT constraint]] [WITH READ ONLY] 
 ```

Now, let’s create a view `Empv_1` that contains all the details of the employees of department 10.

```sql
SQL> CREATE OR REPLACE VIEW empv_1
     AS SELECT empno, ename, job
        FROM emp
        WHERE deptno = 10;
SQL> DESCRIBE empv_1;
```

The `OR REPLACE` option allows a view to be created even if one exists with this name already, thus  replacing the old version of the view for its owner. This means that the view  can be altered without dropping, re-creating, and regranting object  privileges. When assigning column aliases in the `CREATE VIEW` clause, remember that the aliases are listed in the same order as the columns in the subquery.

Alternatively, the view can be created without mentioning the replacement of the existing one (same name) from the database.

```sql
SQL> CREATE VIEW empv_1
     AS SELECT empno, ename, job
        FROM emp
        WHERE deptno = 10;
SQL> DESCRIBE empv_1;
```

Now, we are to create a complex view that contains data from more than one table. Also we will use `GROUP` function as a condition in it.

```sql
SQL> CREATE VIEW deptv_1(name, minsal, maxsal, avgsal)
     AS SELECT d.dname, MIN(e.sal), MAX(e.sal), AVG(e.sal)
        FROM emp e, dept d
        WHERE e.deptno = d.deptno
        GROUP BY d.dname;
SQL> DESCRIBE deptv_1;
```

## Removing a View

Using `DROP VIEW` statement any view can be removed.

The statement  removes the view definition from the database. Dropping views has no effect on the tables on which the view was based. Views or other applications based on deleted views become invalid. Only the creator or a user with the `DROP ANY VIEW` privilege can remove a view.

```sql
SQL> DROP VIEW empv_1;
View dropped.
```

## Lab Task

1. Before starting with the lab task today, keep the sample tables of `EmployeeInfo` database from Week-5 ready in your MySQL server. You can copy and paste the SQL statements step by step to define the tables and populate them with values as it is provided to you in the file. This task SHOULD NOT take you more than 15 minutes.
2. In `EmployeeInfo` Database, continue executing the following SQL:
   1. Create a view to hold information about the employees work in department number 10 and 20.
   2. Create a view to store all the employee and department information from employee and department table.
   3. Create a view which holds information about project’s description and the employees who are working in those projects along with their roles in those projects.
   4. Create a view which only holds information about the employees who earns salary more their average salary order by their employee numbers.
   5. Create a view which will hold department wise average salaries of all the employees.

Solutions are available [here](solution).   