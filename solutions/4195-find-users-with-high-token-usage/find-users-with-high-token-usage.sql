/* Write your T-SQL query statement below */

select
      user_id 
      ,count(*) as prompt_count ,
      round(avg(tokens*1.00),2)  as avg_tokens
from 
     prompts  
group by user_id 
having count(*)>=3 
and count(distinct tokens)>1
order by avg_tokens desc ,user_id asc