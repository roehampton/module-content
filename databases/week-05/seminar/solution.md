# Databases Week 5 -- Normalization

## Solutions

1. iv.
2. ii.
3. iv.
4. i.
5. i.

Normalization.

First Normal Form:

| Course Code | Course Name  | Teacher Name | Roll No | System Used | Hourly rate |
| ----------- | ------------ | ------------ | ------- | ----------- | ----------- |
| C1          | Visual Basic | ABC          | 100     | P-1         | 20          |
| C1          | Visual Basic | ABC          | 101     | P-11        | 30          |
| C1          | Visual Basic | ABC          | 102     | Celeron     | 10          |
| C1          | Visual Basic | ABC          | 103     | P-14        | 40          |
| C2          | Oracle&Dev   | EFG          | 100     | P-1         | 20          |
| C2          | Oracle&Dev   | EFG          | 104     | P-111       | 35          |
| C2          | Oracle&Dev   | EFG          | 105     | P-11        | 30          |
| C3          | DB Tools     | HIK          | 106     | P-111       | 35          |
| C3          | DB Tools     | HIK          | 107     | P-14        | 40          |
| C3          | DB Tools     | HIK          | 108     | p-1         | 20          |
| C4          | Java         | KPP          | 109     | Cyrix       | 20          |

Second Normal Form:

“Courses” Table:

| Course Code | Course Name  |
| ----------- | ------------ |
| C1          | Visual Basic |
| C1          | Visual Basic |
| C1          | Visual Basic |
| C1          | Visual Basic |
| C2          | Oracle&Dev   |
| C2          | Oracle&Dev   |
| C2          | Oracle&Dev   |
| C3          | DB Tools     |
| C3          | DB Tools     |
| C3          | DB Tools     |
| C4          | Java         |

 “Teachers” Table:

| TID  | Teacher  Name |
| ---- | ------------- |
| 201  | ABC           |
| 201  | ABC           |
| 201  | ABC           |
| 201  | ABC           |
| 202  | EFG           |
| 202  | EFG           |
| 202  | EFG           |
| 203  | HIK           |
| 203  | HIK           |
| 203  | HIK           |
| 204  | KPP           |

“Trainees” table:

| Roll No |
| ------- |
| 100     |
| 101     |
| 102     |
| 103     |
| 100     |
| 104     |
| 105     |
| 106     |
| 107     |
| 108     |
| 109     |

“Systems” table:

| SystemCode | System Used | Hourly rate |
| ---------- | ----------- | ----------- |
| 301        | P-1         | 20          |
| 302        | P-11        | 30          |
| 303        | Celeron     | 10          |
| 304        | P-14        | 40          |
| 301        | P-1         | 20          |
| 305        | P-111       | 35          |
| 302        | P-11        | 30          |
| 305        | P-111       | 35          |
| 304        | P-14        | 40          |
| 301        | p-1         | 20          |
| 306        | Cyrix       | 20          |

Third Normal Form:

“Courses” table:

| CourseCode | CourseName   |
| ---------- | ------------ |
| C1         | Visual Basic |
| C2         | Oracle&Dev   |
| C3         | DB Tools     |
| C4         | Java         |

“Teachers” table:

| TID  | TeacherName |
| ---- | ----------- |
| 201  | ABC         |
| 202  | EFG         |
| 203  | HIK         |
| 204  | KPP         |

“Trainees” table:

| RollNo |
| ------ |
| 100    |
| 101    |
| 102    |
| 103    |
| 104    |
| 105    |
| 106    |
| 107    |
| 108    |
| 109    |

“Systems” table:

| SystemCode | SystemUsed | HourlyRate |
| ---------- | ---------- | ---------- |
| 301        | P-1        | 20         |
| 302        | P-11       | 30         |
| 303        | Celeron    | 10         |
| 304        | P-14       | 40         |
| 305        | P-111      | 35         |
| 306        | Cyrix      | 20         |

Finally, the junction table be like:

| CourseCode | TID  | RollNo | SystemCode |
| ---------- | ---- | ------ | ---------- |
| ..         | …    | …      | …          |

 