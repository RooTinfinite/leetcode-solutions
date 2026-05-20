with consisitentUsers as (
    select user_id, count(reaction) as total_reactions
    from reactions
    group by user_id
    having count(content_id) >= 5
)
select r.user_id, r.reaction as dominant_reaction, 
round((count(r.reaction)/max(c.total_reactions)),2) as reaction_ratio 
from reactions r
join consisitentUsers c
on r.user_id = c.user_id
group by r.user_id, r.reaction
having (count(r.reaction)/max(c.total_reactions)) >= 0.6
order by reaction_ratio desc, r.user_id