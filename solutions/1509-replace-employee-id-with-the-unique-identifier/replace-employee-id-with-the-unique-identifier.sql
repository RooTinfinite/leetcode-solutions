SELECT
    eUNI.unique_id
    ,e.name
FROM Employees E
LEFT JOIN EmployeeUNI eUNI
    USING (id)