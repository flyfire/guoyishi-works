USE TeachingMIS
GO

SELECT StuNo AS 'ѧ��', '0003' AS '�γ̺�', Score AS '�ɼ�'
FROM SelectCourse
WHERE SchID = ( SELECT SchID
                FROM CourseSchedule
                WHERE ClassID = '060202' AND CourseNo = '0003'
              )
GO