WITH RECURSIVE cte AS (
    SELECT giver_id, receiver_id, 1 AS len, gift_value FROM SecretSanta
    UNION ALL
    SELECT a.giver_id, b.receiver_id, a.len + 1 AS leng, a.gift_value + b.gift_value AS gift_value FROM cte a, SecretSanta b WHERE a.giver_id <> a.receiver_id AND a.receiver_id = b.giver_id 
)


SELECT RANK() OVER (ORDER BY chain_length DESC, total_gift_value DESC) AS chain_id, chain_length, total_gift_value FROM (SELECT DISTINCT len AS chain_length, gift_value AS total_gift_value FROM cte WHERE giver_id = receiver_id) t