# Write your MySQL query statement below
SELECT player_id, event_date AS first_login
FROM (
    SELECT
        player_id, 
        event_date, 
        ROW_NUMBER() OVER (PARTITION BY player_id ORDER BY event_date) AS rn
    FROM Activity
) AS subquery
WHERE rn = 1;