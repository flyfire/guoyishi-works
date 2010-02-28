USE TeachingMIS
GO
IF EXISTS (SELECT name FROM sysobjects
           WHERE name = 'Proc_BHtoCNT' AND TYPE = 'P')
  DROP PROCEDURE Proc_BHtoCNT
GO
CREATE PROCEDURE Proc_BHtoCNT @ClassID CHAR(6), @Num INT OUTPUT
AS
  SELECT @Num = COUNT(ClassID)
  FROM CourseSchedule
  WHERE ClassID = @ClassID
GO
DECLARE @ClassID CHAR(6)
DECLARE @Num INT
SET @ClassID = '050101'
EXECUTE Proc_BHtoCNT @ClassID, @Num OUTPUT
PRINT @ClassID + '班已经安排' + CONVERT(CHAR(2), @Num) + '门课程'
GO