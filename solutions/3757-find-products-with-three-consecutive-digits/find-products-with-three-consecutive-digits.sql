select * from products
where regexp_like(name,'[0-9]{3}')
and not regexp_like(name,'[0-9]{4}')
order by 1