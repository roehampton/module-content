# Databases Lab 3 - Data Manipulation Language

**This lab explores how to populate database tables with appropriate values and properly access those records. We will also make changes to the records/values and deleting them within the database using SQL.** 

Data Manipulation Language (DML) is a kind of transaction on the database table which can:

- Add rows in the database table
- Change/update existing rows 
- Remove existing rows of the table

It is important to remember that, any DML operation impacts a row or set of rows and not the whole table or the object.

To illustrate we can see the following example, from a table `Salary`.

| **Salary_Grade** | **Low_Sal** | **High_Sal** |
| ---------------- | ----------- | ------------ |
| 1                | 1000        | 2500         |
| 2                | 3000        | 6000         |
| 3                | 6001        | 7000         |

Here, if there is a new salary grade that is required then it can be included by an *insertion* operation that doesn’t impact on the table structure.

Let’s consider the new grade is `5` and the low and high salary scale for this grade is `10000` and `12000` respectively.

```sql
SQL> INSERT INTO SALARY VALUES (5, 10000, 12000);
1 row inserted.
```

| **Salary_Grade** | **Low_Sal** | **High_Sal** |
| ---------------- | ----------- | ------------ |
| 1                | 1000        | 2500         |
| 2                | 3000        | 6000         |
| 3                | 6001        | 7000         |
| 5                | 10000       | 12000        |

The new row holds all the information about grade `5` salary.

In the existing table the highest limit of the salary, `High_Sal`, of grade `1` requires increasing to `3000` then we have to perform `UPDATE` operation as shown below.

```sql
SQL> UPDATE SALARY SET High_Sal = 3000 WHERE Salary_Grade = 1;
1 row updated.
```

| **Salary_Grade** | **Low_Sal** | **High_Sal** |
| ---------------- | ----------- | ------------ |
| 1                | 1000        | 3000         |
| 2                | 3000        | 6000         |
| 3                | 6001        | 7000         |
| 5                | 10000       | 12000        |

If there is any requirement of removing any record from the table, then *deletion* operation is used. For example, if grade `3` salary is no longer required:

```sql
SQL> DELETE FROM SALARY WHERE GRADE=3;
1 row deleted.
```

| **Salary_Grade** | **Low_Sal** | **High_Sal** |
| ---------------- | ----------- | ------------ |
| 1                | 1000        | 3000         |
| 2                | 3000        | 6000         |
| 5                | 10000       | 12000        |

In order to access the data/records in the database table we use a `SELECT` statement. From the above example if we want to retrieve the existing salary grades present in the salary table then the execution of the query will be:

```sql
SQL> SELECT Salary_Grade FROM Salary;
```

| **Salary_Grade** |
| ---------------- |
| 1                |
| 2                |
| 5                |

If we want to retrieve all the details of the salary grade `2`, then we can restrict the other rows by adding `WHERE` clause while querying:

```sql
SELECT FROM Salary WHERE Salary_Grade=2;
```

| **Salary_Grade** | **Low_Sal** | **High_Sal** |
| ---------------- | ----------- | ------------ |
| 2                | 3000        | 6000         |

## Lab Task

**Department**

| **DEPTNO** | **DNAME**  | **LOC**    |
| ---------- | ---------- | ---------- |
| 10         | ACCOUNTING | WANDSWORTH |
| 20         | RESEARCH   | HOUNSLOW   |
| 30         | SALES      | CLAPHAM    |
| 40         | OPERATIONS | HOUNSLOW   |

1. Define table `Department` and populate the table with the example values using SQL.
2. Find the department numbers and department names from the table.
3. Find all the details of the department which is in Hounslow.
4. How can you add another attribute to the table to store the contact number of the departments using SQL?
5. In this existing table `Department` you have to store contact numbers for each of the department. Do so using SQL.
   - Department of Sales: 07999912345
   - Department of Accounting: 07999912346
   - Department of Research: 07999912348
   - Department of Operations: 07999912349
6. Delete all the information of the department where the location is "Hounslow".
7. How can you change the attribute `LOC` to be presented as `LOCATIONS` using SQL?

Solutions are available [here](solution).

 