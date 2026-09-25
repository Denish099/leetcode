# Write your MySQL query statement below
SELECT p.unique_id, e.name from Employees AS e LEFT JOIN EmployeeUNI AS p ON
e.id = p.id  