# Write your MySQL query statement below
SELECT 
    cs.name
FROM 
    Customer cs
WHERE 
    COALESCE(cs.referee_id, 0) != 2;