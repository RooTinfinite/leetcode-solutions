-- Write your PostgreSQL query statement below
SELECT 
    employee_id,
    CASE
        WHEN employee_id % 2 = 1 AND substring(name FROM 1 FOR 1) != 'M'
        THEN salary
        ELSE 0 
    END AS bonus
FROM Employees
ORDER BY employee_id;