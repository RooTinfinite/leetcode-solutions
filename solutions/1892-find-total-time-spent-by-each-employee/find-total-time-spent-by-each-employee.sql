SELECT event_day AS day, emp_id, 
SUM(out_time) - SUM(in_time) AS total_time
FROM employees
GROUP BY emp_id, day ;