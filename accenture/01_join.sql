create table Department (
  dept_id int primary key,
  dept_name varchar(50)
);

insert into Department (dept_id, dept_name) values
(1, 'HR'),
(2, 'Finance'),
(3, 'Engineering'),
(4, 'Marketing');

  create table Employee (
    emp_id int primary key,
    emp_name varchar(50),
    salary int,
    dept_id int,
    foreign key (dept_id) references Department(dept_id)
  );

insert into Employee (emp_id, emp_name, salary, dept_id) values
(101, 'Amit', 50000, 3),
(102, 'Neha', 45000, 1),
(103, 'Raj', 55000, 2),
(104, 'Simran', 60000, 3),
(105, 'Karan', 40000, 4);

select e.emp_id,
e.emp_name,
e.salary,
d.dept_name
from Employee e
inner join Department d
on e.dept_id = d.dept_id;

 



 
