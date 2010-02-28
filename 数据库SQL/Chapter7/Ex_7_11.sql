USE CollegeMIS
GO
/*
CREATE FUNCTION StuNo_Score(@StuNo char(9)) RETURNS TABLE
AS
RETURN
  (SELECT S.StuNo AS '学号', S.StuName AS '姓名',
          C.CourseNo AS '课程号', C.CourseName AS '课程名',
          SC.Score AS '成绩'
  FROM Student S, Course C, SelectCourse SC
  WHERE S.StuNo = @StuNo AND
        S.StuNo = SC.StuNo AND SC.CourseNo = C.CourseNo
  )
GO
*/
SELECT * FROM StuNo_Score('060301002')
GO