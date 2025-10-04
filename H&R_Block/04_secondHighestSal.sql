create table Employees (
    emp_id int primary key,
    name varchar(50),
    salary int,
    department_id int
);

insert into Employees (emp_id, name, salary, department_id) values
  (1, 'Alice', 60000, 10),
  (2, 'Bob', 70000, 10),
  (3, 'Emma', 75000,10),
  (4, 'Carol', 90000, 20),
  (5, 'David', 80000, 20),
  (6, 'Frank', 85000, 20),
  (7, 'Grace', 95000, 30),
  (8, 'Henry', 90000,30),
  (9, 'Ivy', 87000, 30);

  select * from Employees;
  
  select 
  department_id,
  salary as second_highest_salary
  from (
    select 
    department_id,
    salary,
    dense_rank() over (partition by department_id order by salary desc) as rnk
    from Employees
  ) ranked 
where rnk = 2;























