USE TeachingMIS
GO
SELECT CS.ClassID AS '班号', CS.CourseNo AS '课程号',
       COUNT(SC.StuNo) AS '选课人数', AVG(SC.Score) AS '平均成绩',
       MAX(SC.Score) AS '最高成绩', MIN(SC.Score) AS '最低成绩'
FROM CourseSchedule AS CS INNER JOIN SelectCourse AS SC
ON CS.SchID = SC.SchID
WHERE SC.Score IS NOT NULL
GROUP BY CS.ClassID, CS.CourseNo
ORDER BY AVG(SC.Score) DESC
GO