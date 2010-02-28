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
    PRINT '����ɾ����ClassID�ļ�¼, ɾ��ʧ��!'
    ROLLBACK TRANSACTION
  END
ELSE
  PRINT '��¼��ɾ��!'
GO
SELECT DISTINCT C.ClassID AS '������ID'
  FROM Class AS C INNER JOIN CourseSchedule CS
  ON C.ClassID = CS.ClassID
GO
DELETE FROM Class
WHERE ClassID = '050101'
GO