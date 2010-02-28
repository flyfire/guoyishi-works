USE TeachingMIS
GO
DROP VIEW TeachingGoodCourse
GO
CREATE VIEW TeachingGoodCourse
AS
  SELECT TOP 100 PERCENT
         CS.TeaNo AS '教师号', CS.ClassID AS '班号',
         CS.CourseNo AS '课程号', AVG(SC.Score) AS '平均分',
         COUNT(SC.StuNo) AS '人数'         
  FROM CourseSchedule AS CS INNER JOIN SelectCourse AS SC
  ON CS.SchID = SC.SchID
  GROUP BY CS.TeaNo, CS.ClassID, CS.CourseNo
  HAVING (AVG(SC.Score) >= 80)
  ORDER BY AVG(Sc.Score) DESC,
           COUNT(SC.StuNo) DESC
GO