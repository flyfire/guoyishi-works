USE TeachingMIS
GO
SELECT CS.TeaNo AS '教师号', COUNT(CS.CourseNo) AS '讲课门数',
       SUM(C.Hours) AS '总学时数'
FROM CourseSchedule AS CS INNER JOIN Course AS C
ON CS.CourseNo = C.CourseNo
GROUP BY CS.TeaNo
GO