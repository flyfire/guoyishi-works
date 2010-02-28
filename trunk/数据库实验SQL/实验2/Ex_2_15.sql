USE TeachingMIS
GO

SELECT SC.StuNo AS 'ѧ��', S.StuName AS '����',
       C.CourseName AS '�γ���', SC.Score AS '�ɼ�'
FROM SelectCourse AS SC INNER JOIN Student AS S
     ON SC.StuNo = S.StuNo
     INNER JOIN CourseSchedule AS CS
     ON SC.SchID =CS.SchId
     INNER JOIN Course AS C
     ON CS.CourseNo = C.CourseNo
WHERE CS.CourseNo = '0004'
AND EXISTS(SELECT * FROM CourseSchedule
           WHERE CourseNo = '0004')
GO