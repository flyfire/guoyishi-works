USE TeachingMIS
GO
SELECT StuNo AS 'ѧ��', '�����������ƻ���' AS '�γ���',
       Score AS '�ɼ�'
FROM SelectCourse
WHERE SchID = (SELECT SchID
               FROM CourseSchedule
               WHERE ClassID = '060202'
                     AND CourseNo = (SELECT CourseNo
                                     FROM Course
                                     WHERE CourseName = '�����������ƻ���'
                                    )
              )
GO