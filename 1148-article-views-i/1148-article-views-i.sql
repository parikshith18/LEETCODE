# Write your MySQL query statement below
SELECT DISTINCT author_id as id from Views
where Views.author_id = Views.viewer_id
order by id ASC;



-- DISTINCT	Removes duplicates
-- WHERE	Filters rows
-- ORDER BY	Sorts results
-- ASC	Ascending order
-- AS	Gives a column an alias