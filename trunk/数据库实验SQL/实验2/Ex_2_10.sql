USE TeachingMIS
GO
SELECT SC.StuNo AS 'ѧ��', CS.CourseNo AS '�γ̺�',
       SC.Score AS '�ɼ�'
FROM SelectCourse AS SC INNER JOIN CourseSchedule AS CS
     ON SC.SchID = CS.SchID
     INNER JOIN Class AS C
     ON CS.ClassID = C.ClassID
WHERE CS.ClassID = '060202' AND CS.CourseNo = '0003'
GO