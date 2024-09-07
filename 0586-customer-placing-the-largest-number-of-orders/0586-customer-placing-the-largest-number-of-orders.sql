# Write your MySQL query statement below
SELECT 
    p1.customer_number
FROM 
    Orders p1
GROUP BY 
    p1.customer_number
ORDER BY 
    COUNT(p1.customer_number) DESC LIMIT 1;