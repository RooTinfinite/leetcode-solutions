SELECT 
    p1.product_id AS product1_id
    ,p2.product_id AS product2_id
    ,i1.category AS product1_category
    ,i2.category AS product2_category
    ,COUNT(DISTINCT p1.user_id) AS customer_count
FROM productpurchases p1
JOIN productpurchases p2
    ON p1.user_id=p2.user_id
    AND p1.product_id<p2.product_id
JOIN productinfo i1 ON p1.product_id=i1.product_id
JOIN productinfo i2 ON p2.product_id=i2.product_id
GROUP BY p1.product_id, p2.product_id, i1.category, i2.category
HAVING COUNT(DISTINCT p1.user_id)>=3
ORDER BY customer_count DESC, product1_id ASC, product2_id ASC