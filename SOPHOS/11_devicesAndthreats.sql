create table Devices (
  device_id varchar(10) primary key,
  device_name varchar(50)
);

create table Threats (
  threat_id integer primary key,
  device_id varchar(10),
  threat_type varchar(30),
  foreign key(device_id) references Devices(device_id)
);

insert into Devices values ('D1', 'HR-Laptop'), ('D2', 'Finance-PC'), ('D3', 'Server-Alpha');
insert into Threats values (101, 'D1', 'Malware'), (102, 'D1', 'Phishing');

select d.device_name, d.device_id, count(t.threat_id) as total_threats
from Devices d
left join Threats t on d.device_id = t.device_id
group by d.device_id, d.device_name;