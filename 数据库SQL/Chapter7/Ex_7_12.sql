USE CollegeMIS
GO
/*
CREATE FUNCTION Score_Total(@year char(2))
RETURNS @cjhz TABLE
  (�γ̺� char(4),
  �γ��� varchar(30),
  ƽ���� decimal(4,1),
  ��߷� tinyint,
  ��ͷ� tinyint
  )
AS
BEGIN
  DECLARE @T1 TABLE(CNo char(4), PJF decimal(4,1),
                   ZGF tinyint, ZDF tinyint)
  INSERT @T1
  SELECT CourseNo, AVG(Score) AS ƽ����,
         MAX(Score) AS ��߷�, MIN(Score) AS ��ͷ�
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