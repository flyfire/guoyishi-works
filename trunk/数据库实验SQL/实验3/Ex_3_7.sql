USE TeachingMIS
GO
/*
CREATE FUNCTION BJH_CJTJ(@ClassID AS char(6))
RETURNS TABLE AS
RETURN
(SELECT CS.CourseNo AS '课程号', MAX(SC.Score) AS '最高分',
       MIN(SC.Score) AS '最低分', AVG(SC.Score) AS '平均分'
FROM CourseSchedule AS CS INNER JOIN SelectCourse AS SC
     ON CS.SchID = SC.SchID
WHERE CS.ClassID = @ClassID
GROUP BY CS.CourseNo)
GO
*/
SELECT * FROM dbo.BJH_CJTJ('060202')
GO