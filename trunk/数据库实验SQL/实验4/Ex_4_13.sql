USE TeachingMIS
GO
DROP TRIGGER Insert_ClassID
GO
CREATE TRIGGER Insert_ClassID ON Student
FOR INSERT
AS
  IF EXISTS ( SELECT ClassID FROM Inserted
              WHERE ClassID NOT IN (
                 SELECT ClassID FROM Class)
            )
    BEGIN
      PRINT '班号(ClassID)不存在,插入错误!'
      ROLLBACK TRANSACTION
    END
  ELSE
    PRINT '记录插入成功!'
GO
INSERT INTO Student( StuNo, StuID, ClassID )
VALUES ('321451234', '123451234512345123', '051101')
GO
SELECT * FROM Student
GO