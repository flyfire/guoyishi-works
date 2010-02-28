USE TeachingMIS
GO
SELECT * FROM Course
GO
DECLARE @KCH AS CHAR(4)
DECLARE @KCM AS VARCHAR(30)
DECLARE @KS AS SMALLINT
DECLARE @XF AS TINYINT
DECLARE CourseCur CURSOR
  FOR
    SELECT CourseNo, CourseName, Hours, Credit
    FROM Course
  FOR UPDATE OF Hours
OPEN CourseCur
FETCH NEXT FROM CourseCur
  INTO @KCH, @KCM, @KS, @XF
WHILE @@FETCH_STATUS = 0
  BEGIN
    UPDATE Course
      SET Hours = Hours - Credit * 2
      WHERE CURRENT OF CourseCur
    FETCH NEXT FROM CourseCur
      INTO @KCH, @KCM, @KS, @XF
  END
CLOSE CourseCur
DEALLOCATE CourseCur
GO
SELECT * FROM Course