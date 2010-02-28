USE TeachingMIS
GO

SELECT StuNo AS 'Ñ§ºÅ', '0003' AS '¿Î³ÌºÅ', Score AS '³É¼¨'
FROM SelectCourse
WHERE SchID = ( SELECT SchID
                FROM CourseSchedule
                WHERE ClassID = '060202' AND CourseNo = '0003'
              )
GO