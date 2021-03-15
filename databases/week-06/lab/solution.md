# Databases Lab 6 -- Aggregation Functions

<script src="https://cdn.jsdelivr.net/npm/code-line"></script>
<script>CodeLine.initOnPageLoad({toggleBtn: {show: false}, copyBtn: {show: false}})</script>

<link rel="stylesheet" href="/module-content/css/block.css">

## Solutions

1. Enter the data.

2. SQL

   1. ```sql
      SELECT COUNT(empno), deptno FROM employee GROUP BY deptno;
      ```

   2. ```sql
      SELECT AVG(salary), deptno FROM employee GROUP BY deptno;
      ```

   3. ```sql
      SELECT SUM(salary) FROM employee WHERE job="Manager";
      ```

   4. ```sql
      SELECT AVG(salary), job FROM employee GROUP BY job;
      ```

   5. ```sql
      SELECT name, hiredate
      FROM employee
      WHERE salary >= 1000
      AND salary <= 2400
      ORDER BY hiredate;
      ```

   6. ```sql
      SELECT deptno, AVG(salary) AS "AVERAGE PAYROLL"
      FROM employee
      GROUP BY deptno
      HAVING hiredate < 1982-01-01;
      ```

   7. ```sql
      SELECT COUNT(DISTINCT(deptno)) FROM employee;
      ```

   8. ```sql
      SELECT hiredate, job
      FROM employee
      ORDER BY hiredate DESC;
      ```

   9. ```sql
      SELECT *
      FROM project
      ORDER BY end_date ASC;
      ```

   10. ```sql
       SELECT projectno, MAX(end_date) FROM project;
       ```

