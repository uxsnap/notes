-- generate_series (int start, int end, real int?) 
-- very helpful function that generates series of numbers


-- Can be used to generates speicific dates as there is exists
-- version with dates arguments

-- ## Example:

-- Generates date from 1 August 2021 to the last day of month 
SELECT dates.d FROM generate_series(
	date '2021-08-01',  -- start
	date '2021-08-31', -- end date
	'1 day'::interval -- interval argument
) as dates(d)

-- ## Harder example

-- Generate average revenue for the last 15
-- days from 1 August 2021 to the last day of month
-- ( Tables were taken from https://pgexercises.com/)
SELECT date(dates.d), sum(
	b.slots 	* 
		case
			when b.memid = 0 then f.guestcost else f.membercost
		end 
	) / 15 as revenue
from (
	SELECT dates.d FROM generate_series(date '2021-08-01', date '2021-08-31', '1 day'::interval) AS dates(d)
) dates
JOIN cd.bookings b ON 1 = 1
JOIN cd.facilities f ON f.facid = b.facid
WHERE starttime BETWEEN 
	dates.d - '14 day'::interval AND dates.d + '1 day'::interval
	GROUP BY dates.d
	ORDER BY dates.d
