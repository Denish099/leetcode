# Write your MySQL query statement below
SELECT MAX(salary) as SecondHighestSalary 
FROM employee 
WHERE salary < (
    SELECT MAX(salary) FROM employee 
    )