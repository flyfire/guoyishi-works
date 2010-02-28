USE TeachingMIS
GO
/*
CREATE FUNCTION Teacher_Total(@TeaNo AS char(6))
RETURNS @T TABLE
(课程号 char(4),
班级号 char(6),
平均分 DECIMAL(5, 2),
最高分 TINYINT,
最低分 TINYINT
) AS
BEGIN
  INSERT @T
    SELECT CS.CourseNo AS '课程号', CS.ClassID AS '班级号',
           AVG(SC.Score) AS '平均分', MAX(SC.Score) AS '最高分',
           MIN(SC.Score) AS '最低分'
    FROM CourseSchedule AS CS INNER JOIN SelectCourse AS SC
         ON CS.SchID = SC.SchID
    WHERE CS.TeaNo = @TeaNo
    GROUP BY CS.CourseNo, CS.ClassID
  RETURN
END
GO
*/
SELECT * FROM Teacher_Total('010001')