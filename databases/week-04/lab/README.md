# Databases Lab 4 -- Database Constraints

<script src="https://cdn.jsdelivr.net/npm/code-line"></script>
<script>CodeLine.initOnPageLoad({toggleBtn: {show: false}, copyBtn: {show: false}})</script>

<link rel="stylesheet" href="/module-content/css/block.css">

**This lab will describe database constraints and how to create and maintain constraints within the database. In addition, how constraints can be added to the existing database tables will be demonstrated.**  

Database constraints work at the table level, which enforces rules whenever a row is inserted, updated, or deleted from that table. The constraint types that will be used are:

- `PRIMARY KEY`
- `FOREIGN KEY`
- `NOT NULL`
- `UNIQUE KEY`

Constraints can be defined:

- When the **table is created**, or
- **By alteration**.

Constraints are defined at the column level or table level and can be viewed in the data dictionary. 

The `PRIMARY KEY` constraint helps to identify each record uniquely in a database table. However, this constraint restricts this attribute as *unique*. It also assures the attribute is `NOT NULL`. For example, in a employee table, employee’s ID can be considered as a primary key because each employee has *ONLY ONE* employee ID and this ID cannot be same with other employees, hence any specific employee’s record can be identified by this attribute.

 **A table has ONLY ONE `PRIMARY KEY` attribute**.

To add the constraint while defining table we perform the SQL as follows:

```sql
CREATE TABLE [schema.]table(
    column datatype [DEFAULT expr] [column_constraint],
    ...
    [table_constraint][,...]); 
```

For example:

```sql
SQL> CREATE TABLE Employee(
         empno INT(4),
         ename VARCHAR(10),
         salary DOUBLE(7,2), 
         commission DOUBLE(7,2),
         PRIMARY KEY(EMPNO));        
```

Alternatively, the same query can also be re-written as:

```sql
SQL> CREATE TABLE Employee(
         empno INT(4) PRIMARY KEY,
         ename VARCHAR(10),
         salary DOUBLE(7,2),
         commission DOUBLE(7,2));
```

By alteration, a constraint can be added to the already defined database table.

```sql
SQL> ALTER TABLE DEPARTMENT ADD CONSTRAINT dept_pk PRIMARY KEY(deptno);
```

`PRIMARY KEY` is by default `NOT NULL`, meaning `empno` cannot be null. Hence every row **MUST HAVE** an employee’s ID. The `NOT NULL` constraint ensures that `NULL` values are not allowed. `NOT NULL` is declared explicitly while defining the table.

```sql
SQL> CREATE TABLE Employee(
         empno INT(4) PRIMARY KEY,
         ename VARCHAR(10) NOT NULL,
         salary DOUBLE(7,2) NOT NULL,
         commission DOUBLE(7,2));
```

The `Employee` table will return as:

| **EMPNO** | **ENAME** | **SALARY** | **COMM** |
| --------- | --------- | ---------- | -------- |
| 7839      | KING      | 7000.50    | 20.00    |
| 7698      | BLAKE     | 2000.00    | 25.00    |
| 7782      | CLARK     | 1900.00    |          |
| 7566      | JONES     | 10000,00   |          |

`EMPNO` is declared as a `PRIMARY KEY` constraint. As a result this attribute becomes `NOT NULL` automatically for all the records in the table. However, among the other attributes, `ENAME` and `SALARY` are explicitly declared as `NOT NULL`, meaning for every record in the `Employee` table these two attributes that cannot consider any `NULL` or missing values. On the other hand, attribute `COMM` is nullable, meaning there can be employees who may/may not have any commission information to get stored in the database table.

Even though there can only be one `PRIMARY KEY` in a table, more than one `UNIQUE KEY` can be declared while defining the table to restrict the repetition of same data under any attribute. `PRIMARY KEY` is a special type of `UNIQUE KEY`, but not all the `UNIQUE KEYS` can be considered as the `PRIMARY KEY` of the table.

```sql
SQL> CREATE TABLE Department(
         deptno INT(2) PRIMARY KEY,
         dname VARCHAR(14) NOT NULL,
         loc VARCHAR(13) NOT NULL,
         CONSTRAINT dept_dname_uk UNIQUE(dname)); 
```

The `Department` table will return as,

| **DEPTNO** | **DNAME**  | **LOC**       |
| ---------- | ---------- | ------------- |
| 10         | ACCOUNTING | CLAPHAM       |
| 30         | RESEARCH   | NEWHAM        |
| 40         | SALES      | TOWER HAMLETS |

Now, if another record where to be inserted as:

```sql
SQL> INSERT INTO Department(50, SALES, TOWER HAMLETS);
```

Then this operation will not be executed because the `dname `SALES` already exists in this table.

The `FOREIGN KEY` constraint is used to define the relationships by *referencing* between two or more tables so that the data among those tables can be accessed at the same time through a single query.

Let’s assume, there is a `Department` table which is referenced in the `Employee` through a `FOREIGN KEY` constraint.

The `FOREIGN KEY` is defined in the child table, and the table containing the referenced column is the parent table. The `FOREIGN KEY`is defined using a combination of the following keywords:

- `FOREIGN KEY` is used to define the column in the child table at the table constraint level.
- `REFERENCES` identify the table and column in the parent table.
- **ONLY** the `PRIMARY KEY` constraint of a child table can be referenced as a `FOREIGN KEY` of any other table 

In the example below the child table will be created. Let’s assume the `Department` table is the child table.

```sql
SQL> CREATE TABLE Department(
         deptno INT(2) PRIMARY KEY,
         dname VARCHAR(14) NOT NULL,
         loc VARCHAR(13) NOT NULL,
         CONSTRAINT dept_dname_uk UNIQUE(dname)); 
```

Now, we create the `Employee` table and its relationship with the table `Department` as:

```sql
SQL> CREATE TABLE Employee(
         empno INT(4) PRIMARY KEY,
         ename VARCHAR(10) NOT NULL,
         salary DOUBLE(7,2) NOT NULL,
         commission DOUBLE(7,2),
         deptno INT(2),
         FOREIGN KEY Employee(deptno) REFERENCES Department(deptno));
```

The constraint(s) of specific database tables have rules for data accessing and this is how the operations become more effective than usual.

## Lab Task

1. Let’s assume there is a database called `ManufacturerInfo` which stores information about the manufactured products and their manufacturers details for a store. Your task will be to create the following  tables. Remember to specify the constraints while defining the tables accordingly and include `NOT NULL` for all the fields/attributes of both the table.
   - `Manufacturers` containing attributes: manufacturer’s code and name.
   - `Products` containing attributes: product’s code, name, price and manufacturer’s code (manufacturer’s code will be referred here as a foreign key constraint).

2. Populate the tables with the records provided here.
   - Manufacturers (code, name):
     - 1, Sony
     - 2, Samsung
     - 4, Dell
     - 5, HP
     - 6, Winchester
   - Product details (code, name, price, manufacturer):
     - 1, 'Headphone', 240, 2
     - 2, 'Pendrive', 120, 2
     - 3, 'Hard Disk', 150, 1
     - 4, 'DVD', 5, 6
     - 5, 'Monitor', 240, 4
     - 6, 'Tablet', 180, 5
     - 7, 'CD Drive', 90, 6
     - 8, 'Printer', 270, 5
     - 9, 'DVD Burner', 180, 6
3. Try to insert the following record to the table `Products`. Also, put your opinion against this successful/unsuccessful transaction.
   - 5, 'Keyboard', 220, 2
4. Find the product names in the store.
5. Find the product details where the price of the product is 240.
6. Update the price of the printer to 150 in the table.
7. Define manufacturer’s name as a unique key constraint.
8. Delete the manufacturers details where the manufacturer’s code is 2. Put your observation on the outcome of the transaction.

Solutions are available [here](solution).

 