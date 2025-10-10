# Write your MySQL query statement below
with season_category as (
select season, category, sum(quantity) as total_quantity, sum(quantity*price) as total_revenue
from
(select s.sale_id,  s.sale_date ,s.product_id, s.quantity, p.category,s.price, 
    case 
    when month(sale_date) in (12, 1, 2) then 'Winter'
    when month(sale_date) in (3, 4, 5) then 'Spring'
    when month(sale_date) in (6, 7, 8) then 'Summer'
    when month(sale_date) in (9, 10, 11) then 'Fall' end as season
from 
sales as s
inner join products as p
on s.product_id = p.product_id) as sub
group by season, category
order by season asc),
ranked as (
    select 
        season,
        category,
        total_quantity,
        total_revenue,
        rank() over (partition by season order by total_quantity desc, total_revenue desc) as rnk
    from season_category
)
select 
    season,
    category,
    total_quantity,
    total_revenue
from ranked
where rnk = 1
order by season;