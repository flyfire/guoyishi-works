USE CollegeMIS
GO
ALTER PROCEDURE P2_CJCX
AS
  SELECT S.StuNo AS 'ѧ��', S.StuName AS '����', C.CourseName AS '�γ���', SC.Score AS '�ɼ�'
  FROM Student S, Course C, SelectCourse SC
  WHERE S.StuNo = SC.StuNo AND S.Major = '�����Ӧ��' AND C.CourseNo = SC.CourseNo