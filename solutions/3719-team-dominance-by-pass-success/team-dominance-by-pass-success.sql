SELECT
    T1.team_name,
    IF(time_stamp <= "45:00", 1, 2) AS 'half_number',
    SUM(IF(T1.team_name = T2.team_name, 1, -1)) AS 'dominance'
FROM Passes P 
    JOIN Teams T1 ON P.pass_from = T1.player_id
    JOIN Teams T2 ON P.pass_to = T2.player_id
GROUP BY T1.team_name, half_number
ORDER BY T1.team_name, half_number