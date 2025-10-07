SELECT 
    user_id
    ,ROUND(AVG(CASE WHEN activity_type='free_trial' THEN activity_duration ELSE NULL END),2) AS trial_avg_duration
    ,ROUND(AVG(CASE WHEN activity_type='paid' THEN activity_duration ELSE NULL END),2) AS paid_avg_duration
FROM useractivity
WHERE user_id IN (
    SELECT user_id
    FROM useractivity
    GROUP BY user_id
    HAVING COUNT(DISTINCT CASE WHEN activity_type='free_trial' THEN 1 END)>0
        AND COUNT(DISTINCT CASE WHEN activity_type='paid' THEN 1 END)>0
)
GROUP BY user_id
ORDER BY user_id