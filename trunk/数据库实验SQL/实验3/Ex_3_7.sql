USE TeachingMIS
GO
/*
CREATE FUNCTION BJH_CJTJ(@ClassID AS char(6))
RETURNS TABLE AS
RETURN
(SELECT CS.CourseNo AS '�γ̺�', MAX(SC.Score) AS '��߷�',
       MIN(SC.Score) AS '��ͷ�', AVG(SC.Score) AS 'ƽ����'
FROM CourseSchedule AS CS INNER JOIN SelectCourse AS SC
     ON CS.SchID = SC.SchID
WHERE CS.ClassID = @ClassID
GROUP BY CS.CourseNo)
GO
*/
SELECT * FROM dbo.BJH_CJTJ('060202')
GO