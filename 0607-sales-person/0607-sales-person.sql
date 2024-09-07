# Write your MySQL query statement below
SELECT 
    s.name 
FROM 
    Salesperson s 
WHERE 
    s.name NOT IN (
        SELECT s.name 
        FROM Salesperson s 
        JOIN 
            Orders o ON s.sales_id = o.sales_id 
        LEFT JOIN 
            Company c ON c.com_id = o.com_id WHERE c.name="RED"
);