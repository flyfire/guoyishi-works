USE TeachingMIS
GO
SELECT StuNo AS 'Ñ§ºÅ', Score AS '0003ºÅ¿Î³É¼¨'
FROM SelectCourse
WHERE StuNo LIKE '05%'
AND SchID IN (SELECT SchID FROM CourseSchedule
             WHERE CourseNo = '0003')
AND Score >= ANY (SELECT SC.Score FROM SelectCourse AS SC
                  INNER JOIN CourseSchedule AS CS
                  ON SC.SchID = CS.SchID
                  WHERE SC.StuNo LIKE '06%'
                  AND CS.CourseNo = '0003')
GO