# Write your MySQL query statement below
SELECT *, if(x+y>z and y+z>x and z+x>y, "Yes", "No") AS triangle FROM Triangle