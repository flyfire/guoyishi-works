USE TeachingMIS
GO
IF EXISTS ( SELECT name FROM sysobjects
            WHERE name = 'Update_Student' AND TYPE = 'TR' )
  DROP TRIGGER Update_Student
GO
CREATE TRIGGER Update_Student ON Student
FOR UPDATE
AS
  IF UPDATE(StuID)
    BEGIN
      PRINT '�����޸�ѧ�����֤��'
      ROLLBACK TRANSACTION
    END
GO
UPDATE Student
SET StuID = '123'
WHERE StuNo = '050101001'
GO