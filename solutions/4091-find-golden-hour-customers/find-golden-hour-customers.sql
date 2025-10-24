# Write your MySQL query statement below
SELECT customer_id, COUNT(order_id) total_orders, 
ROUND(COUNT(CASE WHEN TIME_FORMAT(order_timestamp, '%H:%i') BETWEEN '11:00' AND '14:00' OR TIME_FORMAT(order_timestamp, '%H:%i') BETWEEN '18:00' AND '21:00' THEN 1 ELSE NULL END) / COUNT(order_id) * 100 , 0) peak_hour_percentage ,
ROUND(AVG(order_rating),2) average_rating 
FROM restaurant_orders
GROUP BY customer_id
HAVING total_orders > 2 AND peak_hour_percentage >= 60
AND average_rating >= 4.0 AND COUNT(order_rating) / COUNT(COALESCE(order_rating,1)) >= 0.5
ORDER BY average_rating DESC, customer_id DESC;