# Databases Lab 8 -- Subquery

<script src="https://cdn.jsdelivr.net/npm/code-line"></script>
<script>CodeLine.initOnPageLoad({toggleBtn: {show: false}, copyBtn: {show: false}})</script>

<link rel="stylesheet" href="/module-content/css/block.css">

## Solutions

1. Enter data.

2. SQL

   1. ```sql
      SELECT MAX(salary), name
      FROM employee
      WHERE salary < (
        SELECT MAX(salary)
        FROM employee);
      ```

   2. ```sql
      SELECT COUNT(empno)
      FROM employee
      WHERE salary > (
        SELECT AVG(salary)
        FROM employee);
      ```

   3. ```sql
      SELECT e.empno, e.name, s.grade
      FROM employee e, salarygrade s
      WHERE e.salary BETWEEN s.losal AND s.hisal
      AND s.salary <> (
        SELECT MAX(e.salary)
        FROM employee);
      ```

   4. ```sql
      SELECT name, hiredate
      FROM employee
      WHERE name != 'adams'
      AND deptno = (
        SELECT deptno
        FROM employee
        WHERE name = 'adams');
      ```

   5. ```sql
      SELECT e.name AS "Employee Name", p.description AS "Project title", r.description AS "Role of the Employee"
      FROM employee e, project p, project_participation pp, role r
      WHERE e.empno = pp.empno
      AND pp.projectno = p.projectno
      AND pp.role_id = r.role_id
      AND e.salary = (
        SELECT MIN(e.salary)
        FROM employee e);
      ```

   6. ```sql
      SELECT salary
      FROM employee
      WHERE salary < (
        SELECT MAX(salary)
        FROM employee)
      ORDER BY salary DESC;
      ```



