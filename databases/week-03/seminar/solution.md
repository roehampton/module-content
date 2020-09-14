# Databases Week 3 -- Basic SQL

## Solutions

1. Answer the statements as TRUE/FALSE. If FALSE then give the correct answer:

   1. (FALSE). DDL impacts the entire table whereas DML only impacts rows or set of rows.
   2. (FALSE). `TRUNCATE` clears the values stored in any database table but the definition of the table still remains whereas `DROP` entirely clears the table from the database.
   3. (TRUE).
   4. (FALSE). Deletion can only remove rows/set of rows present in the table.

2. ```sql
   INSERT INTO EMPLOYEE VALUES (8000, 'XYZ', 'MAINTENER', NULL, 1000);
   ```

3. ```sql
   UPDATE EMPLOYEE SET SAL=2000 WHERE JOB='SALESMAN';
   ```

4. ```sql
   DELETE FROM EMPLOYEE WHERE JOB='MANAGER';
   ```

5. ```sql
   SELECT ENAME, SALARY FROM EMPLOYEE;
   ```

