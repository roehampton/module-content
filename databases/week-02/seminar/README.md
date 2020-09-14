# Databases Week 2 - Entity-Relationship Diagrams

1. Construct an ER diagram for a car-insurance company whose customers own one or more cars. Each car has associated with it zero to any number of recorded accidents. Car insurance tables that the insurance company is expecting to have are:
   - Person (driver-id, name, address)
   - Car (license, year, model)
   - Accident (report-number, date,  location, damage-amount)
2. There is a product shipping company which keeps the information of shipped items. The shipped items can be characterized by item number, weight, dimensions, insurance, destination, and final delivery date. The items are delivered via transportation. Transportations are characterised by a transport id, transport type, delivery route. The items are collected from warehouses, where the warehouse has its id, title, location, address. The items to be shipped have direct relation with the warehouse.
3. The company you work for wants to digitise their timecards. You have been asked to design the database for submitting and approving timecards. Draw the database ER diagram with the following information. Remember to indicate the key for each entity, as well as the multiplicity of each relationship (e.g. one-to-many) using the appropriate notation.
   - A timecard should have hours worked and date submitted
   - Each timecard is associated with exactly one employee
   - Each timecard must have a ID
   - Each timecard has a status: it is either approved, not approved, or pending
   - Each employee has a unique ID
   - Each employee has a name and address
   - Each employee is associated with exactly one manager
   - Each manager has a ID and a name
   - Each manager oversees multiple employees 
   - Each manager approves timecards for multiple employees

4. Pick and Shovel Construction Company is a multi-state building contractor specialising in medium priced town homes. Assume that Pick and Shovel’s database includes customers, employees, projects and equipment. A customer has a registration number, name, account information, and address. They can hire the company for more than one project where the necessary information about projects are ID, title, starting date, ending date and feedback. Employees sometimes work on more than one project at a time. Equipment, however, is assigned to only one project at a time. Employees have information of name, social security number, department, designation, rank. Equipment holds the information about the type and availability. Draw an ERD showing those entities.

Solutions are available [here](solution).