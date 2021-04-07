-- Function that takes timestamp and
-- returns remaining days of the provided month 

-- ## Example: 2021-04-04 -> 27 days

-- #### 
create function remainingMonthDays(timestamp) returns interval
language sql
as 
$$ 
  select date_trunc('month', $1)  + interval '1 month' - date_trunc('day', $1) 
$$;
-- ###
