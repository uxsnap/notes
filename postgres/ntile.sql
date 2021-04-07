-- ntile (int number) 
-- function for group division in 'over' statements

-- ## Example:

-- Divides window function groups by 3
SELECT name, ntile(3) over (order by amount)
FROM sales -- ( name, amount )

-- If there are 5 rows in result so the ntile gives them nums like 1, 1, 2, 2, 3