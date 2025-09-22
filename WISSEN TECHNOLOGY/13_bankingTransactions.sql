CREATE TABLE Account (
    account_id INT PRIMARY KEY,
    customer_name VARCHAR(100),
    balance DECIMAL(10,2)
);

create table Transactions (
  txn_id int primary key,
  account_id int,
  amount decimal(10, 2),
  txn_type varchar(10),
  txn_date date,
  foreign key (account_id) references Account(account_id)
);

insert into Account values (1, 'Alice', 500.00), (2, 'Bob', -50.0), (3, 'Charlie', 1000.00);
insert into Transactions values (101, 1, 200.00, 'deposit', '2025-01-01'), (102, 1, 100.00, 'withdrawl', '2025-01-05'), (103, 2, 150.00, 'withdrawl', '2025-01-06');

--1 Customers with negative balanve:
select account_id, customer_name, balance
from Account
where balance < 0;

--2 Total deposits & withdrawls per account
select account_id, 
sum(case when txn_type = 'deposit' then amount else 0 end) as total_deposists,
sum(case when txn_type = 'withdrawl' then amount else 0 end) as total_withdrawls
from Transactions
group by account_id;