USE TeachingMIS
GO
DROP TRIGGER Delete_Class
GO
CREATE TRIGGER Delete_Class ON Class
FOR DELETE
AS
IF EXISTS ( SELECT ClassID FROM Deleted
            WHERE ClassID IN ( SELECT ClassID
                               FROM CourseSchedule )
          )
  BEGIN
    PRINT '不能删除该ClassID的记录, 删除失败!'
    ROLLBACK TRANSACTION
  END
ELSE
  PRINT '记录已删除!'
GO
SELECT DISTINCT C.ClassID AS '被引用ID'
  FROM Class AS C INNER JOIN CourseSchedule CS
  ON C.ClassID = CS.ClassID
GO
DELETE FROM Class
WHERE ClassID = '050101'
GO