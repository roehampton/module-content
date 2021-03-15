# Databases Lab 4 -- Database Constraints

<script src="https://cdn.jsdelivr.net/npm/code-line"></script>
<script>CodeLine.initOnPageLoad({toggleBtn: {show: false}, copyBtn: {show: false}})</script>

<link rel="stylesheet" href="/module-content/css/block.css">

## Solution

1. ```sql
   CREATE DATABASE ManufacturerInfo;
   CREATE TABLE Manufacturers(Code INT(10) PRIMARY KEY, Name VARCHAR(255) NOT NULL);
   CREATE TABLE Products(
     Code Int(10) PRIMARY KEY, 
     Name VARCHAR(255) NOT NULL, 
     Price DOUBLE(15, 6) NOT NULL, 
     Manufactuer_Code INT(10) NOT NULL,
     FOREIGN KEY Products(Manufacturer_Code) REFERENCES Manufacturers(Code));
   ```

2. ```sql
   INSERT INTO Manufacturers VALUES(1, 'Sony');
   INSERT INTO Manufacturers VALUES(2, 'Samsung');
INSERT INTO Manufacturers VALUES(4, 'Dell');
   INSERT INTO Manufacturers VALUES(5, 'HP');
   INSERT INTO Manufacturers VALUES(6, 'Winchester');
   INSERT INTO Products VALUES(1, 'Headphone', 240, 2);
   INSERT INTO Products VALUES(2, 'Pendrive', 120, 2);
   INSERT INTO Products VALUES(3, 'Hard Disk', 150, 1);
   INSERT INTO Products VALUES(4, 'DVD', 5, 6);
   INSERT INTO Products VALUES(5, 'Monitor', 240, 4);
   INSERT INTO Products VALUES(6, 'Tablet', 180, 5);
   INSERT INTO Products VALUES(7, 'CD drive', 90, 6);
   INSERT INTO Products VALUES(8, 'Printer', 270, 5);
   INSERT INTO Products VALUES(9, 'DVD  burner', 180, 6);
   ```
   
3. The transaction is unsuccessful because duplication of primary key occurred and value `5` already exists in the table for another record.

4. ```sql
   SELECT Name from Products;
   ```

5. ```sql
   SELECT * FROM Products WHERE Price=240;
   ```

6. ```sql
   UPDATE Products SET Price=150 WHERE Name='Printer';
   ```

7. ```sql
   ALTER TABLE Manufacturers ADD CONSTRAINT uk UNIQUE KEY(Name);
   ```

8. Here, manufacturer’s code in the table manufacturers (parent table) was referred as a foreign key in the table products (child table) while defining them, means “code” attribute has become a referential attribute for the child table.
