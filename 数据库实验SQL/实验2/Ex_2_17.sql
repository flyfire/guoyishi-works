USE TeachingMIS
GO
SELECT CS.TeaNo AS '��ʦ��', COUNT(CS.CourseNo) AS '��������',
       SUM(C.Hours) AS '��ѧʱ��'
FROM CourseSchedule AS CS INNER JOIN Course AS C
ON CS.CourseNo = C.CourseNo
GROUP BY CS.TeaNo
GO