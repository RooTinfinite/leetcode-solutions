SELECT 
    p.product_name
    ,s.year
    ,s.price
FROM Sales S
JOIN Product P USING (product_id)