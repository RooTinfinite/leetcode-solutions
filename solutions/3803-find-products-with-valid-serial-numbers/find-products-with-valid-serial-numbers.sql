SELECT * FROM PRODUCTS
WHERE REGEXP_LIKE(description, '\\bSN[0-9]{4}-[0-9]{4}([^0-9]|$)', 'c')
order by product_id asc