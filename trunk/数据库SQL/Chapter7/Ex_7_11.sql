USE CollegeMIS
GO
/*
CREATE FUNCTION StuNo_Score(@StuNo char(9)) RETURNS TABLE
AS
RETURN
  (SELECT S.StuNo AS 'ѧ��', S.StuName AS '����',
          C.CourseNo AS '�γ̺�', C.CourseName AS '�γ���',
          SC.Score AS '�ɼ�'
  FROM Student S, Course C, SelectCourse SC
  WHERE S.StuNo = @StuNo AND
        S.StuNo = SC.StuNo AND SC.CourseNo = C.CourseNo
  )
GO
*/
SELECT * FROM StuNo_Score('060301002')
GO