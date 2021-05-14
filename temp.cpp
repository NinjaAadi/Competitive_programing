Write a MongoDB query for the following:  
The collection in the database should have the name ‘Departments‘. It should have the following fields: Departments (Dept_id, Dept_name, Manager_id, Location)  
Insert at-least SIX records.  
a) Find the names of all departments which are located at Kolkata.  
b) Sort the departments according to increasing order of their  ‘Dept_id‘.  
c) Find the names of all departments which are located either in ‘Delhi‘ or ‘Bombay‘.  
d) Rename the department name where Manager_id is 100



db.Departments.insert({
 "Dept_id" :1,
 "Dept_name" : "Management",
 "Manager_id" : 101,
 "Location" : "Ranchi"
 }
 )
 db.Departments.insert({
 "Dept_id" :1,
 "Dept_name" : "Management",
 "Manager_id" : 150,
 "Location" : "Delhi"
 }
 )
 db.Departments.insert({
 "Dept_id" :1,
 "Dept_name" : "Management",
 "Manager_id" : 263,
 "Location" : "Mumbai"
 }
 )
 db.Departments.insert({
 "Dept_id" :1,
 "Dept_name" : "Management",
 "Manager_id" : 543,
 "Location" : "Hydrabad"
 }
 )
 db.Departments.insert({
 "Dept_id" :2,
 "Dept_name" : "Finance",
 "Manager_id" : 134,
 "Location" : "Delhi"
 }
 )
 db.Departments.insert({
 "Dept_id" :2,
 "Dept_name" : "Finance",
 "Manager_id" : 455,
 "Location" : "Kolkata"
 }
 )