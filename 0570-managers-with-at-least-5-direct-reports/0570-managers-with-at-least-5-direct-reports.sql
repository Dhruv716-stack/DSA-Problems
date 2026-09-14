# Write your MySQL query statement below
with EmpId as (
    select managerId as cnt from Employee group by managerId having COUNT(*)>=5
)

select e.name from Employee as e join EmpId as eid on e.id=eid.cnt;