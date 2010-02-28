USE TeachingMIS
GO

SELECT SC.StuNo AS 'ѧ��', C.CourseNo AS '�γ̺�',
       C.CourseName AS '�γ���', SC.Score AS '�ɼ�'
FROM SelectCourse AS SC INNER JOIN CourseSchedule AS CS
     ON SC.SchID = CS.SchID
     INNER JOIN Course AS C
     ON CS.CourseNo = C.CourseNo
WHERE SC.StuNo LIKE '05%'
GO