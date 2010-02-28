USE CollegeMIS
GO
ALTER FUNCTION dbo.FailureNum(@CourseNo char(4))
RETURNS int AS
BEGIN
  DECLARE @Num int
  SELECT @Num = COUNT(StuNo)
  FROM SelectCourse
  WHERE CourseNo = @CourseNo AND Score < 55
  RETURN @Num
END
GO