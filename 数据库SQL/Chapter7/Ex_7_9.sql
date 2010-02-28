USE CollegeMIS
GO
/*
CREATE FUNCTION ScoreGrade(@Score tinyint)RETURNS varchar(8)
BEGIN
  DECLARE @GradeStr varchar(8)
  SET @GradeStr =
    CASE
      WHEN @Score >= 90 THEN '����'
      WHEN @Score >= 80 THEN '����'
      WHEN @Score >= 70 THEN '�е�'
      WHEN @Score >= 60 THEN '����'
      ELSE '������'
    END
  RETURN @GradeStr
END
GO
*/
SELECT S.StuNo AS 'ѧ��', S.StuName AS '����',
       dbo.ScoreGrade(SC.Score) AS '�ȼ�'
FROM SelectCourse SC INNER JOIN Student S
ON SC.StuNo = S.StuNo
WHERE CourseNo = '0002'
GO