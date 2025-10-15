-- Write your PostgreSQL query statement below
WITH process_1 AS (
	SELECT i.store_id , store_name, location, MAX(price) max_price, MIN(price) min_price
	FROM inventory i
    INNER JOIN stores s ON i.store_id = s.store_id
	GROUP BY i.store_id , store_name, location
	HAVING COUNT(DISTINCT product_name) > 2
)
, process_2 AS (
	SELECT i.store_id, p.store_name, p.location, i.quantity, i.product_name, i.price
	FROM inventory i 
	INNER JOIN process_1 p ON i.store_id = p.store_id  AND (i.price = p.max_price OR i.price = p.min_price )
)
    SELECT p.store_id, p.store_name, p.location, p1.product_name most_exp_product, p.product_name cheapest_product, 
        round( p.quantity / p1.quantity , 2) imbalance_ratio  
    FROM process_2 p INNER JOIN process_2 p1 ON p.store_id = p1.store_id AND p.price < p1.price AND p1.quantity < p.quantity
    ORDER BY imbalance_ratio DESC, store_name