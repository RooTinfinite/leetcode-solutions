# Write your MySQL query statement below

SELECT customer_id
FROM customer_transactions 
GROUP BY customer_id 
HAVING COUNT( IF(transaction_type = 'purchase', 1,  NULL) ) > 2 
AND DATEDIFF(MAX(transaction_date) , MIN(transaction_date)) > 29 
AND ( COUNT( IF(transaction_type = 'refund' , 1, NULL) ) / COUNT(1) ) < 0.2
ORDER BY customer_id