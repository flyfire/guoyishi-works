USE TeachingMIS
GO
DECLARE @Remark AS char(6)
DECLARE @CNT AS int, @TCNT AS int
DECLARE @RATE AS DECIMAL(5,2)
SET @Remark = '����'
IF EXISTS (SELECT * FROM CourseSchedule
           WHERE Remark = @Remark)
  BEGIN
    SELECT @CNT = COUNT(*)
      FROM CourseSchedule
      WHERE Remark = @Remark
    SELECT @TCNT = COUNT(*)
      FROM CourseSchedule
    SET @RATE = @CNT * 100.0/ @TCNT
    PRINT '����Ϊ����Ŀγ�����Ϊ:' + CONVERT(char(3), @CNT)
    PRINT '�ܵĿγ�����Ϊ:' + CONVERT(char(3), @TCNT)
    PRINT 'ƽ��Ϊ����Ŀγ�������ռ�ٷֱ�Ϊ:' + CONVERT(char(5), @RATE) + '%'
  END
ELSE
  PRINT 'û������Ϊ����Ŀγ�'
GO