USE CollegeMIS
GO
/*
CREATE FUNCTION Score_Total(@year char(2))
RETURNS @cjhz TABLE
  (课程号 char(4),
  课程名 varchar(30),
  平均分 decimal(4,1),
  最高分 tinyint,
  最低分 tinyint
  )
AS
BEGIN
  DECLARE @T1 TABLE(CNo char(4), PJF decimal(4,1),
                   ZGF tinyint, ZDF tinyint)
  INSERT @T1
  SELECT CourseNo, AVG(Score) AS 平均分,
         MAX(Score) AS 最高分, MIN(Score) AS 最低分
    FROM SelectCourse
    WHERE StuNo LIKE @year + '%'
    GROUP BY CourseNo
  INSERT @cjhz
    SELECT C.CourseNo, C.CourseName, T.PJF, T.ZGF, T.ZDF
    FROM Course C INNER JOIN @T1 T
    ON C.CourseNo = T.CNo
  RETURN
END
GO
*/
SELECT * FROM dbo.Score_Total('05')
GO