-- Write your PostgreSQL query statement below
WITH temp AS(
    SELECT DISTINCT student_id, subject, 
    FIRST_VALUE(score) OVER(PARTITION BY student_id, subject ORDER BY exam_date) first_score,
    LAST_VALUE(score) OVER(PARTITION BY student_id, subject ORDER BY exam_date ROWS BETWEEN UNBOUNDED PRECEDING AND UNBOUNDED FOLLOWING) latest_score,
    COUNT(student_id) OVER(PARTITION BY student_id, subject) diff_dates
    FROM Scores
)
SELECT 
    student_id, subject ,first_score, latest_score
FROM temp
WHERE first_score < latest_score AND  diff_dates > 1
ORDER BY student_id, subject