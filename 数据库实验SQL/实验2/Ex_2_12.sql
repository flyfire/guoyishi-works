USE TeachingMIS
GO
SELECT Score AS '³É¼¨'
FROM SelectCourse
WHERE SchID IN (SELECT SchID
               FROM CourseSchedule
               WHERE CourseNo = '0003'
              )
AND Score IS NOT NULL
AND StuNo LIKE '06%'
GO