select p.patient_id ,p.patient_name,p.age,
datediff(min(lr.test_date),min(fr.test_date)) recovery_time 
from covid_tests fr
join covid_tests lr
on fr.patient_id=lr.patient_id
and fr.test_date<lr.test_date
and fr.result='Positive'
and lr.result='Negative'
join patients p
on p.patient_id=fr.patient_id
group by 1,2,3
order by 4,2