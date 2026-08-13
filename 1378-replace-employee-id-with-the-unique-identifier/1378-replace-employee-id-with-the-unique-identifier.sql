# Write your MySQL query statement below
SELECT u.unique_id,e.name 
from EmployeeUNI u
RIGHT JOIN Employees e
ON u.id=e.id