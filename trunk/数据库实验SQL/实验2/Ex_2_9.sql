USE TeachingMIS
GO

SELECT SC.StuNo AS '学号', C.CourseNo AS '课程号',
       C.CourseName AS '课程名', SC.Score AS '成绩'
FROM SelectCourse AS SC INNER JOIN CourseSchedule AS CS
     ON SC.SchID = CS.SchID
     INNER JOIN Course AS C
     ON CS.CourseNo = C.CourseNo
WHERE SC.StuNo LIKE '05%'
GO