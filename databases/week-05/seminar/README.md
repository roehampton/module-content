# Databases Week 5 -- Normalization

**Answer the following multiple-choice questions.**

1. Every Boyce-Codd normal form is in:
   1. 1NF
   2. 2NF
   3. 3NF
   4. All of the above
2. "Every Non-key attribute is functionally dependent on the primary key" is true for relation in:
   1. 1NF
   2. 2NF
   3. 3NF
   4. 4NF
3. Which of the following statement is true?
   1. A relationship in BCNF if it is not in 4NF
   2. BCNF is stricter than 3NF
   3. A relation is in BCNF if every determinant is a key
   4. All of the above 
4. Which of the following statement is true?
   1. A relation in BCNF is always in 3NF 
   2. A relation in 3NF is always in BCNF
   3. BCNF and 3NF are the same
   4. A relation in BCNF is not in 3NF
5. Functional dependencies are a generalization of:
   1. Key dependencies
   2. Relational dependencies
   3. Database dependencies
   4. None of the above

Normalize the data given below till 3NF and show how can it be appropriate for performing “Lossless Joining” in a database.

| Course Code | Course Name  | Teacher Name | Roll No | System Used | Hourly rate |
| ----------- | ------------ | ------------ | ------- | ----------- | ----------- |
| C1          | Visual Basic | ABC          | 100     | P-1         | 20          |
|             |              |              | 101     | P-11        | 30          |
|             |              |              | 102     | Celeron     | 10          |
|             |              |              | 103     | P-14        | 40          |
| C2          | Oracle&Dev   | EFG          | 100     | P-1         | 20          |
|             |              |              | 104     | P-111       | 35          |
|             |              |              | 105     | P-11        | 30          |
| C3          | DB Tools     | HIK          | 106     | P-111       | 35          |
|             |              |              | 107     | P-14        | 40          |
|             |              |              | 108     | p-1         | 20          |
| C4          | Java         | KPP          | 109     | Cyrix       | 20          |

 Solutions are available [here](solution).