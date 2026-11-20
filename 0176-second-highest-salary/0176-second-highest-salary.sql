# Write your MySQL query statement below
select max(e1.salary) as secondHighestSalary from employee e1 where e1.salary < (
    select e.salary from Employee e order by e.salary desc limit 1
) 
