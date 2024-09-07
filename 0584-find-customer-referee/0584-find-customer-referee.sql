# Write your MySQL query statement below
SELECT 
    cs.name
FROM 
    Customer cs
WHERE 
    cs.referee_id IS NULL OR cs.referee_id != 2;