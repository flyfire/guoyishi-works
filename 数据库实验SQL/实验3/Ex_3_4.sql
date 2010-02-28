DECLARE @I tinyint
DECLARE @T DECIMAL(11)
DECLARE @SUM DECIMAL(11)
SET @I = 0
SET @T = 2
SET @SUM = 0
WHILE @I < 10
  BEGIN
    SET @SUM = @SUM + @T
    SET @T = @T * 10 + 2
    SET @I = @I + 1
  END
PRINT 'SUM:' + CONVERT(char(11), @SUM)
GO
