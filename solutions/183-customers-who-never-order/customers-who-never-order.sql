SELECT NAME as Customers FROM CUSTOMERS
WHERE customers.Id not IN (select CustomerID from Orders)