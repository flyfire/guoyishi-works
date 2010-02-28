USE TeachingMIS
GO
DROP PROCEDURE Proc_TeaCourseCX
GO
CREATE PROCEDURE Proc_TeaCourseCX @TeaNo char(6)
AS
  SELECT T.TeaNo AS '教师号', T.TeaName AS '姓名',
         C.CourseName AS '课程名', CL.ClassName AS '班级名',
         CS.Remark AS '评价'
  FROM CourseSchedule AS CS INNER JOIN Teacher AS T
    ON CS.TeaNo = T.TeaNo
    INNER JOIN Course AS C
    ON CS.CourseNo = C.CourseNo
    INNER JOIN Class AS CL
    ON CS.ClassID = CL.ClassID
  WHERE CS.TeaNo = @TeaNo
GO
EXECUTE Proc_TeaCourseCX '020010'
GO