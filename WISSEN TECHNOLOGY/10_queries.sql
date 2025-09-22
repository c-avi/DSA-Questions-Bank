CREATE TABLE Course (
    course_id INT PRIMARY KEY,
    title VARCHAR(100),
    parent_course_id INT NULL,
    FOREIGN KEY (parent_course_id) REFERENCES Course(course_id)
);

CREATE TABLE Student (
    student_id INT PRIMARY KEY,
    name VARCHAR(100),
    enrollment_date DATE
);

CREATE TABLE Enrollment (
    student_id INT,
    course_id INT,
    enrollment_date DATE,
    PRIMARY KEY (student_id, course_id),
    FOREIGN KEY (student_id) REFERENCES Student(student_id),
    FOREIGN KEY (course_id) REFERENCES Course(course_id)
);

CREATE TABLE Lesson (
    lesson_id INT PRIMARY KEY,
    course_id INT,
    title VARCHAR(100),
    FOREIGN KEY (course_id) REFERENCES Course(course_id)
);

create table LessonCompletion (
  student_id int,
  lesson_id int,
  completion_date date,
  primary key (student_id, lesson_id),
  foreign key (student_id) references Student(student_id),
  foreign key (lesson_id) references Lesson(lesson_id)
);

create table Quiz (
  quiz_id int primary key,
  lesson_id int,
  foreign key (lesson_id) references Lesson(id)
);

create table QuizAttempt (
  student_id int, 
  quiz_id int,
  score decimal(5, 2),
  primary key (student_id, quiz_id),
  foreign key (student_id) references Student(student_id),
  foreign key (quiz_id) references Quiz(quiz_id)
);

insert into Course values(1, 'Java Basics' , null);
insert into Course values(2, 'Advanced Java' , 1);

INSERT INTO Student VALUES (101, 'Alice', '2025-01-01');
INSERT INTO Student VALUES (102, 'Bob',   '2025-01-02');
insert into Student values (103, 'Charlie', '2025-01-03');

insert into Enrollment values (101, 1, '2025-01-01');
insert into Enrollment values (102, 1, '2025-01-02');
insert into Enrollment values (103, 2, '2025-01-03');

insert into Lesson values(201, 1, 'Intro to Java');
insert into Lesson values(202, 1, 'Data Types');
insert into Lesson values(203, 2, 'OOP Concepts');
insert into Lesson values(204, 2, 'Exception Handling');

insert into LessonCompletion values (101, 201, '2025-01-05');
insert into LessonCompletion values (101, 202, '2025-01-06');
insert into LessonCompletion values (102, 201, '2025-01-07');

INSERT INTO QuizAttempt VALUES (101, 301, 85.0);
INSERT INTO QuizAttempt VALUES (101, 302, 90.0);
INSERT INTO QuizAttempt VALUES (102, 301, 75.0);
INSERT INTO QuizAttempt VALUES (103, 303, 80.0);

select e.course_id, Count(Distinct e.student_id) as total_students from Enrollment e group by e.course_id;

select e.course_id, e.student_id,
count(l.lesson_id)- count(lc.lesson_id) as pending_lessons
from Enrollment e
join Lesson l on e.course_id = l.course_id
left join LessonCompletion lc
on lc.lesson_id = l.lesson_id and lc.student_id = e.student_id
group by e.course_id, e.student_id;

select e.course_id, qa.student_id, avg(qa.score) as avg_score
from Enrollment e
join Lesson l on e.course_id = l.course_id
join Quiz q on l.lesson_id = q.lesson_id
join QuizAttempt qa on qa.quiz_id = q.quiz_id and qa.student_id = e.student_id
group by e.course_id, qa.student_id;

