WITH
last_three_reviews AS (
    SELECT 
        pr.employee_id
        ,pr.review_date
        ,pr.rating
        ,ROW_NUMBER() OVER (
            PARTITION BY employee_id 
            ORDER BY review_date DESC
        ) AS rn
    FROM performance_reviews pr
)
SELECT 
    e.employee_id
    ,e.name
    ,(SELECT rating FROM last_three_reviews WHERE employee_id=e.employee_id AND rn=1) -
    (SELECT rating FROM last_three_reviews WHERE employee_id=e.employee_id AND rn=3) 
    AS improvement_score
FROM employees e
WHERE (SELECT COUNT(employee_id) FROM last_three_reviews WHERE employee_id=e.employee_id AND rn<=3) >= 3
    AND (SELECT rating FROM last_three_reviews WHERE employee_id=e.employee_id AND rn=1) > 
        (SELECT rating FROM last_three_reviews WHERE employee_id=e.employee_id AND rn=2)
    AND (SELECT rating FROM last_three_reviews WHERE employee_id=e.employee_id AND rn=2) >
        (SELECT rating FROM last_three_reviews WHERE employee_id=e.employee_id AND rn=3)
ORDER BY improvement_score DESC, e.name ASC