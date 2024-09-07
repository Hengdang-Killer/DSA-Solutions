# Write your MySQL query statement below
SELECT id 
FROM (
    SELECT 
        id, 
        recordDate, 
        temperature, 
        LAG(temperature) OVER (ORDER BY recordDate) AS prev_temperature, 
        LAG(recordDate) OVER (ORDER BY recordDate) AS prev_date
    FROM Weather
) AS subquery
WHERE DateDIFF(recordDate, prev_date) = 1 AND temperature > prev_temperature;