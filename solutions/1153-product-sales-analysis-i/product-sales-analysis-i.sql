SELECT
    p.product_name
    ,s.year
    ,s.price
FROM Product P
JOIN Sales S USING (product_id)