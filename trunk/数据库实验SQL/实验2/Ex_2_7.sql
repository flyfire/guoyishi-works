USE TeachingMIS
GO

SELECT T.TeaNo, T.TeaName, C.CourseName, CL.ClassName, CS.Remark
FROM Teacher AS T 
     INNER JOIN Course AS C 
     INNER JOIN Class AS CL 
     INNER JOIN CourseSchedule AS CS
ON CS.ClassID = CL.ClassID
ON CS.CourseNo = C.CourseNo
ON CS.TeaNo = T.TeaNo
WHERE T.DepartID = '02'
ORDER BY CL.ClassName
GO