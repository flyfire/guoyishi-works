USE TeachingMIS
GO
DECLARE @Remark AS char(6)
DECLARE @CNT AS int, @TCNT AS int
DECLARE @RATE AS DECIMAL(5,2)
SET @Remark = '优秀'
IF EXISTS (SELECT * FROM CourseSchedule
           WHERE Remark = @Remark)
  BEGIN
    SELECT @CNT = COUNT(*)
      FROM CourseSchedule
      WHERE Remark = @Remark
    SELECT @TCNT = COUNT(*)
      FROM CourseSchedule
    SET @RATE = @CNT * 100.0/ @TCNT
    PRINT '评价为优秀的课程门数为:' + CONVERT(char(3), @CNT)
    PRINT '总的课程门数为:' + CONVERT(char(3), @TCNT)
    PRINT '平均为优秀的课程门数所占百分比为:' + CONVERT(char(5), @RATE) + '%'
  END
ELSE
  PRINT '没有评价为优秀的课程'
GO