USE TeachingMIS
GO
DECLARE @Remark char(6)
SET @Remark = '优秀'
IF EXISTS (SELECT *
           FROM CourseSchedule
           WHERE Remark = @Remark)
  BEGIN
    SELECT T.TeaNo AS '教师号', T.TeaName AS '教师名',
           C.CourseNo AS '课程号', C.CourseName AS '课程名',
           CL.ClassID AS '班级号', CL.ClassName AS '班级名'
      FROM Teacher AS T INNER JOIN CourseSchedule AS CS
           ON T.TeaNo = CS.TeaNo
           INNER JOIN Course AS C ON C.CourseNo = CS.CourseNo
           INNEr JOIN Class AS CL ON CL.ClassID = CS.ClassID
     WHERE CS.Remark = @Remark
  END
GO