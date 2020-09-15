# Databases Lab 9 -- Views

## Solutions

1. Enter data.

2. SQL

   1. ```sql
      CREATE OR REPLACE VIEW emp_v_1 AS 
        SELECT *
        FROM employee
        WHERE deptno IN (10, 20);
      ```

   2. ```sql
      CREATE OR REPLACE VIEW emp_dept_info AS
        SELECT e.empno, e.name, e.job, e.boss, e.hiredate, e.salary, e.comm, e.deptno, d.name AS dname, d.location
        FROM employee e, department d
        WHERE e.deptno = d.deptno;
      ```

   3. ```sql
      CREATE OR REPLACE VIEW project_v AS 
        SELECT pp.empno, e.name, r.description AS "role description", p.description AS "project description"
        FROM project p, project_participation pp, employee e, role r
        WHERE pp.empno = e.empno
        AND pp.projectno = p.projectno
        AND pp.role_id = r.role_id;
      ```

   4. ```sql
      CREATE OR REPLACE VIEW emp_s_info AS
        SELECT *
        FROM employee
        WHERE salary > (
          SELECT AVG(salary)
          FROM employee)
        ORDER BY empno;
      ```

   5. ```sql
      CREATE OR REPLACE VIEW empv_dept AS
        SELECT AVG(salary), deptno
        FROM employee
        GROUP BY deptno;
      SELECT *
      FROM empv_dept;
      ```



