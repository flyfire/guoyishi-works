USE TeachingMIS
GO
SELECT TeaNo AS '��ʦ��', COUNT(CourseNo) AS '��������'
FROM CourseSchedule
GROUP BY TeaNo
GO