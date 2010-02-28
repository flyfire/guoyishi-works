USE TeachingMIS
GO
SELECT TeaNo AS '教师号', COUNT(CourseNo) AS '讲课门数'
FROM CourseSchedule
GROUP BY TeaNo
GO