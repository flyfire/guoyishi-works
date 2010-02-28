USE TeachingMIS
GO

SELECT SC.StuNo AS '学号', S.StuName AS '姓名',
       C.CourseName AS '课程名', SC.Score AS '成绩'
FROM SelectCourse AS SC INNER JOIN Student AS S
     ON SC.StuNo = S.StuNo
     INNER JOIN CourseSchedule AS CS
     ON SC.SchID =CS.SchId
     INNER JOIN Course AS C
     ON CS.CourseNo = C.CourseNo
WHERE CS.CourseNo = '0004'
AND EXISTS(SELECT * FROM CourseSchedule
           WHERE CourseNo = '0004')
GO