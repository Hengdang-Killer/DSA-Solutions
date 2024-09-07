# Write your MySQL query statement below
SELECT 
    s.name 
FROM 
    Salesperson s 
WHERE 
    NOT EXISTS (
        SELECT 1
        FROM 
            Orders o 
            LEFT JOIN Company c ON c.com_id = o.com_id
        WHERE 
            s.sales_id = o.sales_id 
            AND c.name = 'RED'
    );