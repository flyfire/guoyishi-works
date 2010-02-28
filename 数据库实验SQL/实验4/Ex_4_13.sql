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
      PRINT '���(ClassID)������,�������!'
      ROLLBACK TRANSACTION
    END
  ELSE
    PRINT '��¼����ɹ�!'
GO
INSERT INTO Student( StuNo, StuID, ClassID )
VALUES ('321451234', '123451234512345123', '051101')
GO
SELECT * FROM Student
GO