USE TeachingMIS
GO
ALTER FUNCTION Prime(@Num int)
RETURNS tinyint
BEGIN
  DECLARE @IS_PRIME AS tinyint
  DECLARE @I AS int
  SET @IS_PRIME = 1
  SET @I = 2
  IF @NUM = 2
    RETURN 0
  WHILE @I < @NUM
    BEGIN
      IF @NUM % @I = 0
        BEGIN
          SET @IS_PRIME = 0
          BREAK
        END
      SET @I = @I + 1
    END
  RETURN @IS_PRIME
END
GO
DECLARE @N AS INT
SET @N = 3
WHILE @N <= 10000
  BEGIN
    IF dbo.Prime(@N) = 1
      IF dbo.Prime(@N + 2) = 1
        PRINT CONVERT(char(5), @N) + ', ' + CONVERT(char(5), @N+2)
    SET @N = @N + 2
  END
GO