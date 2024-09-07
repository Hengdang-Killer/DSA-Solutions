# Write your MySQL query statement below
SELECT W2.id FROM Weather W1, Weather W2 WHERE DateDIFF(W2.recordDate, W1.recordDate) = 1 AND W2.temperature > W1.temperature