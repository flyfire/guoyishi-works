USE TeachingMIS
GO
DECLARE @CourseNo char(4)
DECLARE @CourseName varchar(30)
DECLARE @Hours smallint
DECLARE @Credit tinyint
DECLARE CourseCur CURSOR
FOR
  SELECT CourseNo, CourseName, Hours, Credit FROM Course
OPEN CourseCur
FETCH NEXT FROM CourseCur
INTO @CourseNo, @CourseName, @Hours, @Credit
WHILE @@FETCH_STATUS = 0
  BEGIN
    PRINT @CourseNo + ' ' + @CourseName + ' '
          + CONVERT(char(3), @Hours) + ' ' + CONVERT(char(3), @Credit)
    FETCH NEXT FROM CourseCur
    INTO @CourseNo, @CourseName, @Hours, @Credit
  END
CLOSE CourseCur
DEALLOCATE CourseCur
GO