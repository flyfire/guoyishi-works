USE CollegeMIS
GO
CREATE PROCEDURE P2_CJCX
AS
  SELECT S.StuNo AS '学号', S.StuName AS '姓名',
         C.CourseNo AS '课程号', C.CourseName AS '课程名',
         SC.Score AS '成绩'
  FROM Student S, Course C, SelectCourse SC
  WHERE S.StuNo = SC.StuNo AND S.Major = '计算机应用' AND C.CourseNo = SC.CourseNo