USE TeachingMIS
GO
DROP VIEW TeachingGoodCourse
GO
CREATE VIEW TeachingGoodCourse
AS
  SELECT TOP 100 PERCENT
         CS.TeaNo AS '��ʦ��', CS.ClassID AS '���',
         CS.CourseNo AS '�γ̺�', AVG(SC.Score) AS 'ƽ����',
         COUNT(SC.StuNo) AS '����'         
  FROM CourseSchedule AS CS INNER JOIN SelectCourse AS SC
  ON CS.SchID = SC.SchID
  GROUP BY CS.TeaNo, CS.ClassID, CS.CourseNo
  HAVING (AVG(SC.Score) >= 80)
  ORDER BY AVG(Sc.Score) DESC,
           COUNT(SC.StuNo) DESC
GO