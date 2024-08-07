# Write your MySQL query statement below
SELECT id 
from Weather w1 
WHERE temperature > (
    SELECT temperature 
    from Weather w2 
    WHERE w2.recordDate=DATE_SUB(w1.recordDate,INTERVAL 1 DAY)
); 