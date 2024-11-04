SELECT name FROM SalesPerson  WHERE name NOT IN (SELECT S.name FROM

SalesPerson S, Company C,Orders O WHERE S.sales_id = O.sales_id 

AND C.com_id = O.com_id AND C.name='RED')