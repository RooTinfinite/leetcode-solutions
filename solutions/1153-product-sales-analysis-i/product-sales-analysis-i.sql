SELECT 
    p.product_name
    ,s.year
    ,s.price
FROM Sales S
JOIN Product p USING (product_id)