USE CollegeMIS
GO
CREATE TRIGGER Update_Teacher ON Teacher
  FOR UPDATE
  AS
    IF UPDATE(TeaID)
      BEGIN
        PRINT '�����޸Ľ�ʦ�����֤��'
        ROLLBACK TRANSACTION
      END
GO