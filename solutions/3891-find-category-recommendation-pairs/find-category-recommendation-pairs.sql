/* Write your T-SQL query statement below */
with cte as (
select pp.user_id ,pp.product_id ,pi.category
from ProductPurchases pp inner join ProductInfo pi
on pp.product_id =pi.product_id  )



select c1.category as category1 ,c2.category as category2 ,count(distinct c1.user_id) as customer_count
from cte c1 ,cte c2 
where c1.user_id =c2.user_id and c1.category <c2.category and c1.product_id <>c2.product_id
group by c1.category ,c2.category 
having count(distinct c1.user_id) >2 
order by  customer_count desc ,category1 asc ,category2 asc 