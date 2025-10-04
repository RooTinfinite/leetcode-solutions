WITH tagged AS (
  SELECT
    p.pass_from,
    p.pass_to,
    p.time_stamp,
    tf.team_name AS team_from,
    tt.team_name AS team_to,
    CASE WHEN tf.team_name = tt.team_name THEN 1 ELSE 0 END AS is_success
  FROM Passes p
  JOIN Teams tf ON tf.player_id = p.pass_from
  JOIN Teams tt ON tt.player_id = p.pass_to
),
per_team AS (
  -- patrzymy tylko na podania wykonywane przez daną drużynę, w porządku chronologicznym
  SELECT
    team_from AS team_name,
    time_stamp,
    is_success,
    SUM(CASE WHEN is_success = 0 THEN 1 ELSE 0 END)
      OVER (PARTITION BY team_from ORDER BY time_stamp) AS fail_block
  FROM tagged
),
streaks AS (
  -- długości serii udanych podań między nieudanymi podaniami tej samej drużyny
  SELECT
    team_name,
    fail_block,
    COUNT(*) AS streak_len
  FROM per_team
  WHERE is_success = 1
  GROUP BY team_name, fail_block
),
best AS (
  SELECT team_name, MAX(streak_len) AS longest_streak
  FROM streaks
  GROUP BY team_name
)
SELECT team_name, longest_streak
FROM best
ORDER BY team_name;