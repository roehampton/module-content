# Databases Lab 8 -- Subquery

**This lab describes the problems that different types of subqueries can solve through single and multi-row outputs while accessing database.**

Subquery is an advanced features used within the `SELECT` block in any SQL statement. For example, if we are asked to find the salaries greater than Jones' salary from the `employee` table then to solve this problem, we need two queries:

1. What is the salary of Jones?
2. Who earns more than Jones from the `employee` table?  

However, to find both the answers combinedly through a single query we can use *subquery*. While performing subquery, there will be one inner `SELECT` block which will find a value (Jones' salary). This value will than be compared with the other values (other employee’s salaries) sequentially to identify the *greater salaries* in the outer `SELECT` block of the query.

```sql
SQL> SELECT sal, ename
     FROM employee
     WHERE SALARY > (
       SELECT sal
       FROM EMPLOYEE
       WHERE ename= 'Jones'); 
```

While performing Subqueries always to remember:

- The subquery (inner query) executes once before the main query.
- The result of the subquery is used by the main query (outer query).

A subquery is a `SELECT` statement that is embedded in a clause of  another `SELECT` statement. Powerful statements can be built out of simple ones  by using subqueries. These approaches can be very useful when we need to  select rows from a table with a condition that depends on the data in the  table itself. The subquery can be placed  in a number of SQL clauses:

- `WHERE` clause.
- `HAVING` clause.
- `FROM` clause.

Comparison operators fall into two classes: single-row operators (>, =, >=, <, <>,  <=) and multiple-row operators (`IN`, `ANY`, `ALL`).  The subquery is  often referred to as a nested `SELECT`, sub-`SELECT`, or inner `SELECT` statement.   

## Single-Row Subqueries

Single-Row subqueries always:

- Return only one row.
- Use single-row comparison operators.

An example of single-row Subquery is given below:

```sql
SQL> SELECT ename, job, sal
     FROM emp
     WHERE sal > (
       SELECT MIN(sal)
       FROM emp);
```

The output that generated from this single-row subquery is:

![Query Output](clip_image004.png)

## Multiple-Row Subqueries

Multiple-row subqueries always:

- Return **MORE THAN ONE** row.
- Use multiple-row comparison operators.

An example of multiple-row subquery is given below.

```sql
SQL> SELECT empno, ename, job
     FROM emp
     WHERE sal < ANY (
       SELECT sal
       FROM employee 
       WHERE job = 'CLERK') 
     AND job <> 'CLERK';
```

![Query Output](clip_image008.png)

```sql
SQL> SELECT empno, ename, job
     FROM emp
     WHERE sal > ALL (
       SELECT AVG(sal)
       FROM employee
       GROUP BY deptno);
```

![Query Output](clip_image010.png)

Guidelines for using subqueries:

- Enclose subqueries in parentheses
- Place subqueries on the right side of the comparison operator
- Use single-row operators with single-row subqueries
- Use multiple-row operators with multiple-row subqueries

However, subqueries can be applied on multiple table(s) at a time. While performing subqueries on more than one table we need to ensure that the joining among those tables are done properly. An example is given below.

Let’s assume we want to query about the employee’s salaries who earns more than the average salary from the employee table, along with the department’s name they are working in. However, the department’s name is available in a different table than employee table, as a result this is confirmed that we will be accessing both the tables, employee and department together by joining them.

```sql
SQL> SELECT e.salary, d.name
     FROM employee e, department d
     WHERE e.deptno = d.deptno
     AND e.salary > (
       SELECT AVG(e.salary)
       FROM employee e);
```

## Lab Task

1. Before starting with the lab task today, keep the sample tables of `EmployeeInfo` database from Week-5 ready in your MySQL server. You can copy and paste the SQL statements step by step to define the tables and populate them with values as it is provided to you in the file. This task SHOULD NOT take you more than 15 minutes.
2. In `EmployeeInfo` database, continue executing the following SQL
   1. Find the second maximum salary and the employee’s name who is paid that salary.
   2. Find the total number of employees who earns more than the average salary.
   3. Find the employee’s number, name and salary grade except for the employee who earns the highest salary.
   4. Write a query to display the employee name and hiredate for all employees in the same department as John. Also Exclude John’s info.
   5. Find the employee’s name as "Employee Name", the project description he is working in as "Project title" and the description of the role as "Role of the Employee" who earns the minimum salary.
   6. Find the salaries for all the employees except for the one who earns the highest salary in a descending order.

Solutions can be found [here](solution).

 