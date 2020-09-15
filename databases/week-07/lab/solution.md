# Databases Lab 7 -- Joining

## Solution

1. Enter data.

2. SQL

   1. ```sql
      SELECT P.description, PP.start_date, PP.end_date, E.name
      FROM project P, project_participation PP, employee E
      WHERE PP.empno = E.empno
      AND P.projectno = PP.projectno;
      ```

   2. ```sql
      SELECT d.location, e.name
      FROM department d, employee e
      WHERE e.deptno = d.deptno;
      ```

   3. ```sql
      SELECT e.empno, e.name, s.grade, e.salary
      FROM employee e, salarygrade s
      WHERE e.salary <= 3000;
      ```

   4. ```sql
      SELECT e.empno, d.name, d.location, MAX(e.salary)
      FROM employee e, department d;
      ```

   5. ```sql
      SELECT emp.name, boss.name, d.name
      FROM employee emp, employee boss, department d, employee e
      WHERE d.name = "research"
      AND emp.boss = boss.empno
      AND e.deptno = d.deptno;
      ```

   6. ```sql
      SELECT e.empno, e.name, e.hiredate, d.name, d.location
      FROM employee e, department d
      ORDER BY d.name;
      ```

   7. ```sql
      SELECT COUNT(pp.empno) AS "total employee", r.role_id, r.description
      FROM project_participation pp, role r
      WHERE pp.role_id = r.role_id
      GROUP BY r.role_id;
      ```

   8. ```sql
      SELECT p.description, p.start_date, p.end_date, r.description
      FROM project p, project_participation pp, role r
      WHERE pp.projectno = p.projectno
      AND pp.role_id = r.role_id;
      ```



