USE TeachingMIS
GO

SELECT Score
FROM SelectCourse
WHERE StuNo LIKE '06%'
AND SchID IN (SELECT SchID FROM CourseSchedule
              WHERE CourseNo = '0003')
GO

SELECT StuNO AS 'Ñ§ºÅ', Score AS '³É¼¨'
FROM SelectCourse
WHERE StuNo LIKE '05%'
AND SchID IN (SELECT SchID FROM CourseSchedule
              WHERE CourseNo = '0003')
AND Score >= ALL ( SELECT Score FROM SelectCourse
                   WHERE StuNo LIKE '06%'
                   AND Score IS NOT NULL
                   AND SchID IN (SELECT SchID FROM COurseSchedule
                                 WHERE CourseNo = '0003')
                 )
GO