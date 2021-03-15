# Databases Lab 2 -- Data Definition Language

<script src="https://cdn.jsdelivr.net/npm/code-line"></script>
<script>CodeLine.initOnPageLoad({toggleBtn: {show: false}, copyBtn: {show: false}})</script>

<link rel="stylesheet" href="/module-content/css/block.css">

**The contents of this lab will be mainly emphasising on how to describe main database objects, create tables in the database, describing data types which can be used while specifying column definitions, alter tables as well as how to drop, rename, and truncate tables within the database.** 

There are a few considerations to remember while defining any database object (database *table*):

- The name of the table must begin with a letter.
- The name **MUST BE** 1-30 characters long.
- The name **MUST** contain only A–Z, a–z, 0–9, _, $, and #.
- The name **MUST NOT** duplicate the name of another object owned by the same user.
- The name **MUST NOT** be a database server reserved word; e.g. `CREATE` is a reserved word so, it cannot be defined as a name.

If a user has the access to *Create* any object and there’s enough storage area available to perform this task, then creating a new object can be successfully done.

```sql
CREATE TABLE [schema.]table
	(column datatype [DEFAULT expr][, ...]);
```

Here, the table name must be specified along with the column names, column data type and the size of the column. For example, to create table `dept` with attributes: `deptno`, `dname` and `location` the SQL be:

```sql
SQL> CREATE TABLE dept(deptno NUMBER (2), dname VARCHAR (14), loc VARCHAR (13));
Table created.
```

To check if `dept` has been created:

```sql
SQL> DESCRIBE dept;
```

| Name   | Null? | Type         |
| ------ | ----- | ------------ |
| DEPTNO |       | NUMBER (2)   |
| DNAME  |       | VARCHAR (14) |
| LOC    |       | VARCHAR (13) |

**The already created table can also be *altered* if required:**

- To *add* a new column to the table.
- To *modify* the existing column(s).
- Define default value for the column(s).

```sql
ALTER TABLE table ADD (column datatype [DEFAULT expr] [, column datatype] ...);
```

or

```sql
ALTER TABLE table MODIFY (column datatype [DEFAULT expr] [, column datatype] ...);
```

Now, let’s use `ALTER` to add a column `address` in the existing table `dept`.

```sql
SQL> ALTER TABLE dept ADD (address VARCHAR(9));
```

As a result, the table will look like:

| Name    | Null? | Type         |
| ------- | ----- | ------------ |
| DEPTNO  |       | NUMBER (2)   |
| DNAME   |       | VARCHAR (14) |
| LOC     |       | VARCHAR (13) |
| ADDRESS |       | VARCHAR (9)  |

To change the data type, size and/or, default value, we can proceed with those alteration(s) on the existing database table.

```sql
SQL> ALTER TABLE dept MODIFY (address VARCHAR (20));
```

| Name    | Null? | Type         |
| ------- | ----- | ------------ |
| DEPTNO  |       | NUMBER (2)   |
| DNAME   |       | VARCHAR (14) |
| LOC     |       | VARCHAR (13) |
| ADDRESS |       | VARCHAR (20) |

Alteration of a table alters the definition to some extent but to discard the entire table from the database it needs to be dropped explicitly. After the `DROP` operation on any table:

- All data and the structure in the table is deleted.
- Any pending transactions are committed.
- All indexes of the tables are dropped.

**DO NOT EXECUTE THIS CODE!**

```sql
SQL> DROP TABLE dept;
Table dropped.
```

In order to change the name of the object (table) , view, or sequence the `RENAME` statement is used.

```sql
SQL> RENAME TABLE dept to Department;
Table renamed.
```

Another operation, `TRUNCATE`, is used to remove all rows from the table and releases the storage space used by that table.

```sql
SQL> TRUNCATE TABLE Department;
Table truncated.
```

## Lab Task

Let’s consider the following ERD, as the scenario to perform DDL. The scenario is based on a *Bioinformatic Application*.

Patient who has a unique MSP number, a name, date of birth, tissue type and indicator that basically denotes whether the tissue is "Cancerous" or "Normal".

The entire patient library associates a patient with multiple tags. Each tag has a unique tag number and unique nucleotide sequence. For each tag in the patient library, a count is given to record the number of times the tag occurs in the library. In general, the same tag can be associated with any number of patients.

A tag may be mapped to a gene. Each gene has a unique gene name and type. In general, multiple tags may be mapped to the same gene. However, two different genes cannot be mapped to the same tag.

Finally, an article is identified by a unique article number and a journal name. An article may analyse multiple genes and gene may be analysed by multiple articles.

1. Construct the ER model for the above application.
2. The ER- model you developed contains multiple entities, which now you will define as database table(s). Clearly define the attributes with appropriate data types. Use the datatype summary table at the end of this lab to help.
3. There are articles based on genome analysis, identified by article’s number and journal name already, but now a decision has come to keep the information about "article publication date" in the existing table. How can you define it without changing anything in the existing object?
4. How can you change the `JName` in the `Articles` table to `Journal_Name`?
5. Let’s assume we would like to see the `Patients` table titled as `Patient Information`. Which definition statement you would use?
6. Truncate the table `Tags`. [Try `TRUNCATE` operation once the table is populated with values to see the changes it makes].
7. Drop all the tables that you have created considering the above scenario.

A solution is available [here](solution).

## Summary of SQL DDL Operations

| **Statement**    | **Description**                                              |
| ---------------- | ------------------------------------------------------------ |
| `CREATE TABLE`   | Creates table                                                |
| `ALTER TABLE`    | Modifies the structure                                       |
| `DROP TABLE`     | Removes the rows and the table structure                     |
| `RENAME TABLE`   | Changes the name of a table, view, sequence, or synonym      |
| `TRUNCATE TABLE` | Removes all rows from a table and releases the storage space |

**DDL makes changes on any object, meaning the result of the change impacts all the rows present within the object.**

## Summary of Widely Used SQL Datatypes

| **Datatype**             | **Description**                                              |
| ------------------------ | ------------------------------------------------------------ |
| `CHAR`                   | A FIXED length string (can contain letters, numbers, and special characters) |
| `VARCHAR`                | A VARIABLE length string (can contain letters, numbers, and special characters) |
| `BINARY`                 | Like `CHAR`, but stores binary byte strings                  |
| `FLOAT`                  | Floating precision number data                               |
| `BOOLEAN`/`BOOL`         | Zero is considered as false, nonzero values are considered as true |
| `INT`/` INTEGER`         | A medium-sized integer                                       |
| `BIGINT`                 | A large-sized integer                                        |
| `DOUBLE (S, P)`          | A normal-size floating point number -- the total  number of digits is specified in `S` |
| `DATE`                   | A date with format: YYYY-MM-DD                               |
| `DATETIME`               | A date and time combination with format: YYYY-MM-DD  hh:mm:ss |
| `TIMESTAMP`              | The number of seconds since the Unix epoch ('1970-01-01 00:00:00' UTC). Format: YYYY-MM-DD  hh:mm:ss. The supported range is from '1970-01-01 00:00:01' UTC to  '2038-01-09 03:14:07' UTC. |
| `YEAR`                   | A year in four-digit format                                  |
| `DECIMAL (S, P)`         | An exact fixed-point number -- total number of  digits is specified in `S` |
| `IMAGE`                  | Variable width binary string                                 |
| `TEXT`                   | Variable width character string                              |
| `ENUM (val1,val2,val3…)` | A string object that can have only one value, chosen from a list of possible values |