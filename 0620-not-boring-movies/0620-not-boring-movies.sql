# Write your MySQL query statement below
# First select movies wih odd number index
# then select movies which has description not 0

SELECT * 
FROM Cinema 
WHERE id % 2 = 1 
  AND description != 'boring'
ORDER BY rating DESC;
