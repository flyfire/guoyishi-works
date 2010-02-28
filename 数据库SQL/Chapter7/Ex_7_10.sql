USE CollegeMIS
GO
/*
CREATE FUNCTION FailureNum(@CourseNo char(4))
RETURNS int
BEGIN
  DECLARE @Num int
  SELECT @Num = COUNT(Score)
  FROM SelectCourse
  WHERE Score < 60
  AND CourseNo = @CourseNo
  RETURN @Num
END
GO
*/
DECLARE @C int
SET @C = dbo.FailureNum('0001')
PRINT '0001号课不及格的人数是' + CONVERT(char(2), @C)
GO