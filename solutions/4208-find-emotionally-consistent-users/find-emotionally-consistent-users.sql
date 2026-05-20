/* Write your T-SQL query statement below */
WITH agg AS (
    SELECT
        user_id,
        reaction,
        COUNT(*) AS reaction_count
    FROM reactions
    GROUP BY user_id, reaction
),
scored_data AS (SELECT 
    user_id,
    reaction,
    reaction_count,
    SUM(reaction_count) OVER(PARTITION BY user_id) as total_reaction_count,
    ROW_NUMBER() OVER(PARTITION BY user_id ORDER BY reaction_count DESC) as reaction_rank
FROM agg
)

SELECT 
    user_id,
    reaction as dominant_reaction,
    ROUND((1.0*reaction_count/total_reaction_count),2) as reaction_ratio
FROM scored_data
WHERE total_reaction_count >= 5 AND reaction_rank = 1 AND (1.0*reaction_count/total_reaction_count)>=0.60
ORDER BY reaction_ratio DESC