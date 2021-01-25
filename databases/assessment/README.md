# Databases Coursework

The coursework is worth 60% of the module total. This coursework is split into three parts, each worth 20% of the module total.

The coursework meets the following module learning outcomes:

- Evaluate a set of query processing strategies and select the optimal strategy.
- Use SQL to create tables and retrieve (SELECT) information from a database.
- Create a relational database schema in SQL that incorporates key, entity integrity, and referential integrity constraints.

In this coursework you are tasked with creating a database system for the smooth and efficient operation of a business of your choosing. Hence, you are required to specify what type of business you will be building your databases system for, along with the different collections of data that may be required to be stored in your database in order to achieve its purpose. The completion of your coursework will be graded by submission of a written report as well as a script of SQL statements.

You will need to create a formal business report with everything compiled into a single document (PDF). The report should use 12-point font in Times New Roman, 1-inch margins, and double line spaced. Th report should be properly paged, paragraphed, and sectioned, and include the following sections in order.

1. Cover page.
2. Table of contents.
3. Business system summary based on the chosen topic.
4. An overview of the business environment and work objectives.
5. Justification how your developed database meets the project objectives, and how it will support the business.
6. An ERD (logical representation) of your idea using an appropriate tool.
7. A database relationship diagram (physical data model) clearly showing every table, attributes, and data type.
8. Appropriate screenshots of sample data:
   - One screenshot for each table - both structurally and populated with proper and meaningful data.
   - You should enter enough data to demonstrate the use of the database (at least eight records for each table).
9. Demonstration of the scenario you have developed.
   - Design at minimum at least 15 questions/tasks in your application domain that are needed to query the database.
   - Write SQL `SELECT` statements for all queries.
   - There must be at least five complex queries. A complex query is one involving joining and subqueries and some appropriate aggregation functions.
10. Reflection of your learning experience, including problems faced, lessons learned, achievements, and future development.

## SQL Requirements

1. Creating and/or altering database tables, database constraints, dropping existing tables, renaming tables.
2. Inserting appropriate values into tables.
3. Perform `SELECT` operations using:
   - Special operators.
   - Comparison/mathematical operators.
   - Logical operators.
   - Aggregation functions.
   - Ordering operations.
   - Grouping operations.
   - Joining tables (inner, outer, self, and/or left/right).
   - Nested queries.
   - Defining database views and performing selection, updates, deletion, and insertion operations on them.

## Part One

In part one of the coursework, you will submit an overview of your idea of the DBMS you want to design and develop, what are the business questions (SQL you are to perform) that you will cover in your system, and the purpose of having a DBMS you have proposed. You will need a good logical relational database management system representation (ERD) based on your proposed idea. This includes Formal Data Modelling with detailed features of your system.

This part will become Sections 3 to 7 of your full report.

## Part Two

Successful implementation of the system from part 1 using SQL by following the formal data model.

This part will become Sections 8 and 9 of your full report.

## Part Three

A logically well represented report containing Part One and Part Two with appropriate explanation and discussion where critical understanding is present. This includes summarising the learning experience from the database coursework, detailing some of the problems faced, lessons learned, achievements, outcomes, future-plan, and any other throughs and comments.

## Submission Requirements

- An electronic copy of your work/report (a single PDF).
- A single ZIP file containing supporting evidence, e.g., scripts of performed queries.
- If you have used ideas from anywhere other than the lecture notes and tutorial examples (e.g., from a book, the Internet, or a fellow student) then include a reference showing where the code or ideas came from and label your code carefully to show which parts are your and which parts are borrowed.
- You must be available to demonstrate your work and time for your demonstration will be approximately 10 minutes.

## Deadlines

**Part One of the coursework must be uploaded to Moodle by 14.00 on Friday 26th of February (end of Week 6).**

**Part Two of the coursework must be uploaded to Moodle by 14.00 on Friday 26th of March (end of Week 10).**

**Part Three of the coursework must be uploaded to Moodle by 14.00 on Friday 16th of April (after Spring Break).** 

## Marking Scheme

### Part One

| **Criteria**                                                 | **Excellent**                                                | **Good**                                                     | **Developing**                                               | **Not attempted**                                            |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| **Idea** the suitability of the idea for a DBMS.             | The idea requires a DBMS and has been well specified.        | The idea would require a DBMS to manage although the idea is not fully specified. | Idea is simple and could be managed without a DBMS.          | No idea provided or idea unsuitable.                         |
| **Purpose of DBMS** how well defined the purpose of the DBMS is. | The DBMS purpose is clearly defined and represents a good use of a DBMS. | The DBMS purpose is clearly defined although does not clearly represent a good use for a DBMS. | The DBMS purpose is not clearly defined.                     | Purpose of the DBMS not given, or purpose ill defined.       |
| **Business questions** the suitability of the business questions to the DBMS defined. | Precise business questions defined that are clearly suitable for the DBMS defined. | The business questions provided are suitable for the DBMS defined although could be more precise. | The business questions provided are not clearly suitable for the DBMS defined. | No business questions provided or business questions unsuitable. |
| **Entity Relationship Diagram** the quality of the ERD provided. | ERD provided is correct and fully complete for the problem at hand. | ERD provided is correct although is not fully complete.      | ERD provided has some omissions and incorrect features.      | No ERD provided or ERD is grossly misleading.                |
| **Physical Data Model** the quality of the physical data model provided. | Data model is correct and fully complete for the problem at hand. | Data model provided is correct although not fully complete.  | Data model has some omissions and incorrect features.        | No data model provided or data model is grossly misleading.  |
| **Submission** ability to provide a submission that meets the requirements given. | Correct files submitted only with no issues.                 | Correct files submitted only but some issues with files provided. | Correct files submitted but with unwanted files provided and possibly issues in files provided. | Incorrect files submitted.                                   |

### Part Two

| **Criteria**                                                 | **Excellent**                                                | **Good**                                                     | **Developing**                                               | **Not attempted**                                            |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| **SQL comments** code is commented correctly.                | SQL is sufficiently commented with comments on every query, code segment, and special case. | SQL is commented in most cases.                              | SQL is commented but not sufficiently.                       | Code is not commented at all or has very few comments.       |
| **SQL correctness** how correct is the output of the SQL.    | All queries work correctly.                                  | Almost all of the queries work correctly, or output is correct almost all the time. | Some queries do not work correctly, or output is incorrect.  | No output provided from SQL, or output is incorrect.         |
| **SQL execution** how smoothly does the SQL execute -- are there any bugs? | Queries executed correctly.                                  | Queries executed correctly although there are some syntax    | Some queries have syntax errors that mean they do not execute. | No SQL queries provided, or most have syntax errors causing problems. |
| **SQL code structure** structure of code, use of layout to aid understanding. | Code structure follows guidelines.                           | Code structure needs work.                                   | Most queries are in long lines, new lines aren't used properly (e.g., `SELECT` queries are not broken by `SELECT`, `FROM`, `WHERE`, etc.) | No SQL code provided, or SQL code provided is very poorly formatted. |
| **SQL naming conventions** how closely is the naming convention for tables, columns, etc. followed. | All names are easy to understand, consistent and follow guidelines. | Names follow the conventions although some could be better.  | Names need work, and are sometimes unsuitable.               | Names are too short or too cryptic, inconsistent, or do not follow any convention. |
| **Submission** ability to provide a submission that meets the requirements given. | Correct files submitted only with no issues.                 | Correct files submitted only but some issues with files provided. | Correct files submitted but with unwanted files provided and possibly issues in files provided. | Incorrect files submitted.                                   |

### Part Three

| **Criteria**                                                 | **Excellent**                                                | **Good**                                                     | **Developing**                                               | **Not attempted**                                            |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| **Presentation** how well organised is the report.           | Good organisation, points are logically ordered, report order flows together. | Organised, although some points are somewhat jumpy. General flow of report works. | Some organisation points jump around. Flow is unclear.       | Poorly organised. No logical progression. Overall flow is vague. |
| **Discussion** overall level of discussion in the report.    | Excellent overall level of discussion provided.              | Good discussion level provided although unclear or inconsistent in a couple of places. | Discussion is good but lacks clarity and consistency in places. | Discussion is poor and does not provide clarity to the report. |
| **Reflection** ability to reflect on the overall process and assessment deliverable. | Reflection clearly addresses the strengths and weaknesses of the deliverable. | Reflection addresses the majority of the strengths and weaknesses of the deliverable. | Reflection discusses some of the issues around the deliverable but lacks a critical awareness. | No reflection provided or reflection is unsuitable.          |
| **Quality of information** ability to provide details to support the report. | Supporting details specific to subject.                      | Some details are non-supporting to the subject.              | Details are somewhat unclear and do not support the topic.   | Specific details undefined or difficult to find.             |
| **Format** ability to meet the formatting standard defined.  | Report is in the correct format.                             | Report is mostly in the correct format                       | Report has a few formatting issues.                          | Report has many formatting issues or does not meet the guidelines specified. |
| **Submission** ability to provide a submission that meets the requirements given. | Correct files submitted only with no issues.                 | Correct files submitted only but some issues with files provided. | Correct files submitted but with unwanted files provided and possibly issues in files provided. | Incorrect files submitted.                                   |

## Academic Misconduct

All submissions will be processed through a code plagarism tool. If signs of misconduct are found, all students involved will be contacted to discuss further steps. Please see here for information on academic integrity at the university https://portal.roehampton.ac.uk/information/Pages/Academic-Integrity.aspx. Our guiding principle is:

> Academic integrity and honesty are fundamental to the academic work you produce at the University of Roehampton. You are expected to complete coursework which is your own and which is referenced appropriately. The university has in place measures to detect academic dishonesty in all its forms. If you are found to be cheating or attempting to gain an unfair advantage over other students in any way, this is considered academic misconduct and you will be penalised accordingly.

