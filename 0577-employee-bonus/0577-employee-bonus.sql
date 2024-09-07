# Write your MySQL query statement below
SELECT 
    e.name, 
    b.bonus
FROM 
    Employee e
    LEFT JOIN Bonus b 
        ON e.empid = b.empid
WHERE 
    COALESCE(b.bonus, 0) < 1000;
