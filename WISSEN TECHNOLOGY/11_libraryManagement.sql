create table Author (
  author_id int primary key,
  name varchar(100)
);

create table Book (
  book_id int primary key,
  title varchar(100),
  author_id int,
  foreign key (author_id) references Author(author_id)
);

create table Borrow (
  student_id int,
  book_id int,
  borrow_date date,
  return_date date,
  primary key (student_id, book_id, borrow_date),
  foreign key (book_id) references Book(book_id)
);

insert into Author values (1, 'J.K. Rowling'), (2, 'George R.R. Martin');
insert into Book values (101, 'Harry Potter', 1), (102, 'Game of Thrones', 2), (103, 'Clash of Kings', 2);
insert into Borrow values (201, 101, '2025-01-01', '2025-01-15'), (202, 101, '2025-01-02', null), (203, 102, '2025-01-10', '2025-01-25'), (204, 103, '2025-01-11', null);

select b.title, count(*) as borrow_count
from Borrow br
join Book b on br.book_id = b.book_id
group by b.title
order by borrow_count desc
limit 3;

select student_id, book_id
from Borrow where return_date is null
and borrow_date < date('now', '-30 day');

select a.name, count(distinct br.book_id) as total_books_borrowed
from Author a
join Book b on a.author_id = b.author_id
join Borrow br on b.book_id = br.book_id
group by a.name;