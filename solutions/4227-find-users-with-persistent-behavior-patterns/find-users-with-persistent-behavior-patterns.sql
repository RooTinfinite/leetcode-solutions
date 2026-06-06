WITH cte AS (
    SELECT
        user_id,
        action,
        action_date,
        DATEADD(DAY, -ROW_NUMBER() OVER (PARTITION BY user_id, action ORDER BY action_date), action_date) AS group_date
    FROM activity
)
SELECT
    user_id,
    action,
    COUNT(*)         AS streak_length,
    MIN(action_date) AS start_date,
    MAX(action_date) AS end_date
FROM cte
GROUP BY user_id, action, group_date
HAVING COUNT(*) >= 5
ORDER BY streak_length DESC, user_id ASC