USE CollegeMIS
GO
IF EXISTS (SELECT name FROM sysobjects
           WHERE name = 'P3_XHCJ' AND type = 'P')
  DROP PROCEDURE P3_XHCJ
GO
CREATE PROCEDURE P3_XHCJ @XH CHAR(9)
  AS
  SELECT S.StuName AS '姓名', C.CourseName AS '课程名', SC.Score AS '成绩'
  FROM Student S, Course C, SelectCourse SC
  WHERE S.StuNo = SC.StuNo AND C.CourseNo = SC.CourseNo
GO
EXECUTE P3_XHCJ '060301002'
GO