USE TeachingMIS
GO
UPDATE Course
SET Hours = Hours + Credit * 2
WHERE Credit <= 3
GO
SELECT * FROM Course
GO