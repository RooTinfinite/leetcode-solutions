SELECT EMP.name AS Employee FROM Employee EMP,Employee MGR
WHERE EMP.managerId=MGR.id AND EMP.salary>MGR.salary