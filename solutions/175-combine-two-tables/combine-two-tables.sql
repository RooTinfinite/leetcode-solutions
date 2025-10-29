# Write your MySQL query statement below
select

p.firstName,
p.lastName,
case when p.personId != a.personId then "Null" else a.city end as city,
case when p.personId != a.personId then "Null" else a.state end as state


from Person p
left join Address a on a.personId = p.personId