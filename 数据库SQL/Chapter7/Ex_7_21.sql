USE CollegeMIS
GO
IF EXISTS(SELECT name FROM sysobjects
          WHERE name = 'P4_XHCCJ' AND type = 'P')
  DROP PROCEDURE P4_XHCCJ
GO
CREATE PROCEDURE P4_XHCCJ @XH CHAR(9), @PJCJ DECIMAL(4,1) OUTPUT, @SKSL INT OUTPUT
  AS
    SELECT @PJCJ = AVG(SC.Score), @SKSL = COUNT(SC.CourseNo)
      FROM Student S, SelectCourse SC
      WHERE S.StuNo = SC.StuNo AND S.StuNo = @XH
GO
DECLARE @AvgScore DECIMAL(4,1), @CourseNum INT, @StuNo CHAR(9)
SET @StuNo = '060302112'
EXECUTE P4_XHCCJ @StuNo, @AvgScore OUTPUT, @CourseNum OUTPUT
SELECT @StuNo AS '学号', @AvgScore AS '平均成绩', @CourseNum AS '选课门数'
GO