SELECT
    teacher_id
    ,COUNT(DISTINCT subject_id) cnt
FROM Teacher
GROUP BY teacher_id