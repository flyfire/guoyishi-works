USE TeachingMIS
GO
SELECT S.StuNo AS '学号', S.StuName AS '姓名',
       C.CourseNo AS '课程号', C.CourseName AS '课程名',
       SC.Score AS '成绩'
FROM SelectCourse AS SC INNER JOIN Student AS S
     ON SC.StuNo = S.StuNo
     INNER JOIN CourseSchedule AS CS
     ON SC.SchID = CS.SchID
     INNER JOIN Course AS C
     ON CS.CourseNo = C.CourseNo
WHERE S.Grade = 2
      AND SC.Score BETWEEN 85 AND 100
GO