with cte1 as(
    -- Assign a sequential row number for each user's specific action, ordered by date
    select *,
           row_number() over(partition by user_id, action order by action_date) as rk
    from activity
),
cte2 as(
    -- Subtract the row number (in days) from the action date. 
    -- Consecutive dates will result in the exact same 'diff' base date.
    select *,
           (action_date - interval rk day) as diff
    from cte1
),
cte3 as(
    -- Group by the 'diff' to isolate distinct streaks.
    -- Calculate the total days, start date, and end date for each streak.
    select user_id,
           action,
           count(*) as streak_length,
           min(action_date) as start_date,
           max(action_date) as end_date 
    from cte2
    group by user_id, action, diff
    -- Keep only streaks that lasted for 5 or more consecutive days
    having count(*) >= 5
),
cte4 as(
    -- Rank the valid streaks for each user to find their longest one.
    -- Longest streaks get rank 1 (rkk).
    select *,
           row_number() over(partition by user_id order by streak_length desc) as rkk
    from cte3
)

-- Select the longest streak for each user and sort the final output
select user_id,
       action,
       streak_length,
       start_date,
       end_date 
from cte4
where rkk = 1
order by 3 desc, 1 asc; -- Order by streak_length DESC, then user_id ASC