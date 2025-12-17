create table daily_threat_stats (
  detection_date date primary key,
  threat_count integer
);

insert into daily_threat_stats values
('2025-12-15', 10),
('2025-12-16', 5),
('2025-12-17', 12);

select detection_date,
threat_count,
sum(threat_count) over (order by detection_date) as running_total
from daily_threat_stats;