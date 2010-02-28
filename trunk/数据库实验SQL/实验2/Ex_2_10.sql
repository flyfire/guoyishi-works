USE TeachingMIS
GO
SELECT SC.StuNo AS 'Ñ§ºÅ', CS.CourseNo AS '¿Î³ÌºÅ',
       SC.Score AS '³É¼¨'
FROM SelectCourse AS SC INNER JOIN CourseSchedule AS CS
     ON SC.SchID = CS.SchID
     INNER JOIN Class AS C
     ON CS.ClassID = C.ClassID
WHERE CS.ClassID = '060202' AND CS.CourseNo = '0003'
GO