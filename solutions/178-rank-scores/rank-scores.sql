# Using DENSE_RANK - generally what interviewers want
SELECT
    score
    , DENSE_RANK() OVER (ORDER BY score DESC) 'rank'
FROM Scores
    ORDER BY score DESC