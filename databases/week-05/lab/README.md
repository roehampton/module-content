# Databases Lab 5 -- Special Operators in SQL

<script src="https://cdn.jsdelivr.net/npm/code-line"></script>
<script>CodeLine.initOnPageLoad({toggleBtn: {show: false}, copyBtn: {show: false}})</script>

<link rel="stylesheet" href="/module-content/css/block.css">

**This lab focuses on the special types of operators that are used to access information by effective querying from any database table.**  

There are comparison operators which can be used while performing any query on an existing database or database table as below: 

| **Operators** | **Meaning**              |
| ------------- | ------------------------ |
| =             | Equal to                 |
| >             | Greater than             |
| >             | Greater than or Equal to |
| <             | Less than                |
| <=            | Less than or Equal to    |
| <>            | Not Equal to             |

For example, if we want to find the employee’s name and job from the Employee table where the salary of the employee is less than 1000 then:

```sql
SQL> SELECT ename, job FROM Employee WHERE salary<1000;
```

The employee names and jobs will be displayed but only those of whose salaries are less than 1000. 

Other comparison operators used while accessing data from the database table(s) are:

| **Operators**    | **Meaning**                    |
| ---------------- | ------------------------------ |
| `BETWEEN`…`AND`… | Between two values (inclusive) |
| `IN`             | Match any of the list values   |
| `LIKE`           | Match a character pattern      |
| `IS NULL`        | Is a `NULL` value              |

Let’s consider that, we have to find the employee’s name, job and salary who has salaries between 1000 and 2000.

```sql
SQL> SELECT ename, job, salary FROM Employee WHERE salary BETWEEN 1000 AND 2000;
```

To find the department name and location for the sales and accounting departments.

```sql
SQL> SELECT name, location FROM department WHERE name IN('SALES', 'ACCOUNTING');
```

The  comparison operator `LIKE` is mainly used for character match operation, for example, if we want to see who are the employees whose job title starts with letter `M`, or for the jobs which contain letter `A` in their title, or even the job titles which end with `T`.

```sql
SQL> SELECT name, job FROM employee WHERE job LIKE 'M%';
SQL> SELECT name, job FROM employee WHERE job LIKE '%A%';
SQL> SELECT name, job FROM employee WHERE job LIKE '%T';
```

**More About `LIKE` Operators**

| **LIKE Operator**       | **Description**                                              |
| ----------------------- | ------------------------------------------------------------ |
| `WHERE` … `LIKE 'a%'`   | Finds any values that start with "a"                         |
| `WHERE` … `LIKE '%a'`   | Finds any values that end with "a"                           |
| `WHERE` … `LIKE '%or%'` | Finds any values that have "or" in any position              |
| `WHERE` … `LIKE '_r%'`  | Finds any values that have "r" in the second position        |
| `WHERE` … `LIKE 'a_%'`  | Finds any values that start with "a" and are at least 2 characters in length |
| `WHERE` … `LIKE 'a__%'` | Finds any values that start with "a" and are at least 3 characters in length |
| `WHERE` … `LIKE 'a%o'`  | Finds any values that start with "a" and ends with "o"       |

Using the `IS NULL` condition tests for the `NULL` values in the database table(s), for example, the employees whose commission is `NULL` can be checked as:

```sql
SQL> SELECT name, salary, comm FROM employee WHERE comm IS NULL;
```

> Remember that the comparison operators are contained in the `WHERE` block as condition(s).

There are also logical operators. Some of them basically work like *connectives* where there are more than one condition to satisfy or compare:

| **Operators** | **Meaning**                                           |
| ------------- | ----------------------------------------------------- |
| AND           | Returns TRUE if *both* component conditions are TRUE  |
| OR            | Returns  TRUE if *either* component condition is TRUE |
| NOT           | Returns  TRUE if the following condition is FALSE     |

Now, if we want to see the information about the employees who have salaries more than 1000 and they also work as clerk then:

```sql
SQL> SELECT empno, name, salary, job FROM employee 
     WHERE salary > 1000
     AND job= 'CLERK';
```

**Try to find the details of the  employees whose job is either manager or clerk.**  

Let’s try another example where we will find the employees details whose commission is not NULL.

```sql
SQL> SELECT FROM employee WHERE comm IS NOT NULL;
```

 The rules of precedence when using different operators are given here, though the rules can be overridden by using parenthesis:

| **Operators**            | **Orders** |
| ------------------------ | ---------- |
| All Comparison Operators | 1          |
| NOT                      | 2          |
| AND                      | 3          |
| OR                       | 4          |

```sql
SQL> SELECT  name, job, salary FROM employee
     WHERE (job='SALESMAN' OR job='PRESIDENT')
     AND salary > 1500;
```

Here, the parenthesis enforced the `OR` condition to be executed first. 

While querying some functions can be used to manipulate the character strings on the data stored in the database.

| **Functions**               | **Description**                                           | **Results**    |
| --------------------------- | --------------------------------------------------------- | -------------- |
| `CONCAT('Good',  'String')` | Joins values together                                     | `Good  String` |
| `SUBSTR('String',1,3)`      | Extracts  a string of determined length                   | `Str`          |
| `LENGTH('String')`          | Shows  the length of a string as a numeric value          | `6`            |
| `INSTR('String',  'r')`     | Finds  numeric position of a named character              | `3`            |
| `TRIM('S' FROM 'SSMITH')`   | Trims the exact character                                 | `MITH`         |
| `REPLACE('TOY','Y','LET')`  | Does  an replacement of character or a part of the string | `TOLET`        |

Let’s execute the following query to see the result:

```sql
SQL> SELECT name, CONCAT (name, job), LENGTH(name), INSTR(name, 'A') FROM employee
     WHERE SUBSTR(job,1,5) = 'SALES'; 
```

| `name` | `CONCAT(name, job)` | `LENGTH(name)` | `INSTR(name, 'A')` |
| ------ | ------------------- | -------------- | ------------------ |
| ALLEN  | ALLENSALESMAN       | 5              | 1                  |
| WARD   | WARDSALESMAN        | 4              | 2                  |
| MARTIN | MARTINSALESMAN      | 6              | 2                  |
| TURNER | TURNERSALESMAN      | 6              | 0                  |

There is very useful feature of SQL called *SQL Aliases*. Aliases improve the readability of the query report. 

- Renames a column heading
- Is useful with calculations
- Immediately follows column name; optional `AS` keyword between column name and alias
- Requires double quotation marks if it contains spaces or special characters or is case sensitive

For example:

```sql
SQL> SELECT name AS "Employee_name", salary AS "Payroll" FROM employee;
```

Another example:

```sql
SQL> SELECT name AS "Employee_name", (salary * 12) AS "Annual Salary" FROM employee;
```

Also, multiple columns/ attributes can be concatenated if necessary.

- Concatenates columns or character strings to other columns 
- Is represented by two vertical bars (`||`)
- Creates a resultant column that is a character expression

```sql
SQL> SELECT name||job AS "Employees" FROM employee;
```

Another example:

```sql
SQL> SELECT name||' '||'is a'||' '||job AS "Employee Details" FROM  Employee;
```

## Lab Task

1. Before starting with the lab task today, check the file which contains sample tables of `EmployeeInfo` database and keep them ready in your MySQL server. You can copy and paste the SQL statements step by step to define the tables and populate them with values as it is provided to you in the file. This task SHOULD NOT take you more than 15 minutes. Data [here](sql).
2. In `EmployeeInfo` Database, continue executing the following SQL:
   1. Find the employee’s name, hiredate and salary for those, whose salary is no more than 2450.
   2. Find the highest salary range for salary grade 4 and 5.
   3. Find the details about all the projects where the “end date” of the project is null.
   4. Represent the employee’s salary as `Grade_4_Salary` whose salary is between 2000 and 3000.
   5. Find the employee’s salary and "revised salary", increased by 20% who are working as analyst.
   6. Find the details from department table where the location of the department starts with letter "B" or ends with letter "O".
   7. Find the employees name and the department number where the employee’s salaries are between 2000 and 3000.
   8. Find employee’s name, hiredate, salary and commission where the commission is null and hiredate is after 1982-01-01.
   9. Find the employee numbers who are working in project number 1004.
   10. Generate a report of the 10% updated commission of the salary for the employees whose commission is null.
   11. Insert a new record to the department table: 50, ADMINISTRATION, LA
   12. Find the length of the department’s names have letter “A” in their location names.
   13. Delete the information about department number 50.

Solutions are available [here](solution).