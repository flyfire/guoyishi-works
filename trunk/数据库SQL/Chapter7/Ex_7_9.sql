USE CollegeMIS
GO
/*
CREATE FUNCTION ScoreGrade(@Score tinyint)RETURNS varchar(8)
BEGIN
  DECLARE @GradeStr varchar(8)
  SET @GradeStr =
    CASE
      WHEN @Score >= 90 THEN '优秀'
      WHEN @Score >= 80 THEN '良好'
      WHEN @Score >= 70 THEN '中等'
      WHEN @Score >= 60 THEN '及格'
      ELSE '不及格'
    END
  RETURN @GradeStr
END
GO
*/
SELECT S.StuNo AS '学号', S.StuName AS '姓名',
       dbo.ScoreGrade(SC.Score) AS '等级'
FROM SelectCourse SC INNER JOIN Student S
ON SC.StuNo = S.StuNo
WHERE CourseNo = '0002'
GO