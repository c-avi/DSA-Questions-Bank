create table connections (
  source_ip varchar(45),
  dest_ip varchar(45),
  timestamp datetime
);

insert into connections values
('192.168.1.1', '192.168.1.2', '2025-12-17 20:00:00'),
('192.168.1.2', '10.0.0.5', '2025-12-17 20:00:45'),
('172.16.0.1', '172.16.0.5', '2025-12-17 21:00:00');

select c1.source_ip as Initial_Attacker,
c1.dest_ip as Intermidiate_Hop,
c2. dest_ip as Final_target
from connections c1 
join connections c2 on c1.dest_ip = c2.source_ip
where c2.timestamp > c1.timestamp 
and c2.timestamp <= datetime(c1.timestamp, '+1 minute');