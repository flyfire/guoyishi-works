USE TeachingMIS
GO
SELECT S.StuNo AS 'ѧ��', S.StuName AS '����',
       C.CourseNo AS '�γ̺�', C.CourseName AS '�γ���',
       SC.Score AS '�ɼ�'
FROM SelectCourse AS SC INNER JOIN Student AS S
     ON SC.StuNo = S.StuNo
     INNER JOIN CourseSchedule AS CS
     ON SC.SchID = CS.SchID
     INNER JOIN Course AS C
     ON CS.CourseNo = C.CourseNo
WHERE S.Grade = 2
      AND SC.Score BETWEEN 85 AND 100
GO