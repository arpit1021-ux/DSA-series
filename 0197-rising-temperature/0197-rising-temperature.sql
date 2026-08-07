# Write your MySQL query statement below
SELECT w2.id 
FROM Weather w1
JOIN Weather w2 
ON date_sub(w2.recordDate,interval 1 day)=w1.recordDate
and w2.temperature>w1.temperature;