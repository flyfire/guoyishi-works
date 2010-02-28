USE CollegeMIS
GO
CREATE TRIGGER Update_Teacher ON Teacher
  FOR UPDATE
  AS
    IF UPDATE(TeaID)
      BEGIN
        PRINT '不能修改教师的身份证号'
        ROLLBACK TRANSACTION
      END
GO