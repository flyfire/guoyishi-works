USE TeachingMIS
GO
SELECT * FROM Course
GO
DECLARE @XF TINYINT
DECLARE CourseCur CURSOR
  FOR
    SELECT Credit FROM Course
  FOR UPDATE
OPEN CourseCur
FETCH NEXT FROM CourseCur
  INTO @XF
WHILE @@FETCH_STATUS = 0
  BEGIN
    IF @XF <= 2
      BEGIN
        DELETE FROM Course
        WHERE CURRENT OF CourseCur
      END
    FETCH NEXT FROM CourseCur
      INTO @XF
  END
CLOSE CourseCur
DEALLOCATE CourseCur
GO
SELECT * FROM Course
GO