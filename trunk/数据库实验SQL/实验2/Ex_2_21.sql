USE TeachingMIS
GO
DELETE FROM Course
WHERE CourseNo IN ('0005', '0006')
GO
SELECT * FROM Course
GO