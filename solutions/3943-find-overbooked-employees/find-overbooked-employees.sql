-- Write your MySQL query statement below
WITH process_1 AS (
SELECT employee_id, SUM(duration_hours) duration_total
FROM meetings
GROUP BY employee_id, WEEKOFYEAR(meeting_date), YEAR(meeting_date)
)
SELECT p.employee_id, e.employee_name, e.department, COUNT(p.employee_id) meeting_heavy_weeks 
FROM process_1 p INNER JOIN employees e ON p.employee_id = e.employee_id
WHERE duration_total > 20
GROUP BY p.employee_id, e.employee_name, e.department
HAVING COUNT(p.employee_id) > 1
ORDER BY meeting_heavy_weeks DESC, employee_name;