USE TeachingMIS
GO
SELECT CS.ClassID AS '���', CS.CourseNo AS '�γ̺�',
       COUNT(SC.StuNo) AS 'ѡ������', AVG(SC.Score) AS 'ƽ���ɼ�',
       MAX(SC.Score) AS '��߳ɼ�', MIN(SC.Score) AS '��ͳɼ�'
FROM CourseSchedule AS CS INNER JOIN SelectCourse AS SC
ON CS.SchID = SC.SchID
WHERE SC.Score IS NOT NULL
GROUP BY CS.ClassID, CS.CourseNo
ORDER BY AVG(SC.Score) DESC
GO