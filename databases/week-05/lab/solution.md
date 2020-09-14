# Databases Lab 5 -- Special Operators

## Solution

1. Enter the table.

2. SQL

   1. ```sql
      SELECT name, hiredate, salary
      FROM employee 
      WHERE salary < 2450;
      ```

   2. ```sql
      SELECT hisal
      FROM salarygrade 
      WHERE grade IN(4, 5);
      ```

   3. ```sql
      SELECT *
      FROM project 
      WHERE end_date IS NULL;
      ```

   4. ```sql
      SELECT salary AS "Grade_4_salary"
      FROM employee 
      WHERE salary BETWEEN 200 AND 3000;
      ```

   5. ```sql
      SELECT salary, (salary + salary * 20/100) AS "Revised Salary"
      FROM employee 
      WHERE job = "analyst";
      ```

   6. ```sql
      SELECT *
      FROM department 
      WHERE location LIKE "B%" 
      OR location LIKE "%O";
      ```

   7. ```sql
      SELECT name, deptno, salary
      FROM employee
      WHERE salary BETWEEN 2000 AND 3000;
      ```

   8. ```sql
      SELECT name, hiredate, salary, comm
      FROM employee
      WHERE comm IS NULL
      AND hiredate > 1982-01-01;
      ```

   9. ```sql
      SELECT empno, projectno
      FROM project_participation
      WHERE projectno = 1004;
      ```

   10. ```sql
       SELECT salary, comm, (salary * .10) AS "Updated commisson"
       FROM employee
       WHERE comm IS NULL;
       ```

   11. ```sql
       INSERT INTO department VALUES(50, 'Administration', 'LA');
       ```

   12. ```sql
       SELECT name, length(name)
       FROM department
       WHERE location LIKE "%A%";
       ```

   13. ```sql
       DELETE FROM department WHERE deptno = 50;
       ```

       

