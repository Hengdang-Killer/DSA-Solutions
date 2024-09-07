# Write your MySQL query statement below
WITH OrderCounts AS (
    SELECT 
        customer_number, 
        COUNT(*) AS order_count
    FROM 
        Orders
    GROUP BY 
        customer_number
)
SELECT 
    customer_number
FROM 
    OrderCounts
ORDER BY 
    order_count DESC
LIMIT 1;