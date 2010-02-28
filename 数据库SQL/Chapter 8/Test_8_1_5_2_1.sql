USE CollegeMIS
GO
DROP TRIGGER Insert_DepartNo
GO
CREATE TRIGGER Insert_DepartNo ON Teacher
FOR INSERT
AS
  DECLARE @DepartNo char(2)
  SELECT @DepartNo = Department.DepartNo
    FROM Department, Inserted
    WHERE Department.DepartNo = Inserted.DepartNo
  IF @DepartNo <> ''
    PRINT '��ʦ��Ϣ����ɹ�!'
  ELSE
    BEGIN
      PRINT 'ϵ����û�и�ϵ����Ϣ,����ʧ��!'
      ROLLBACK TRANSACTION
    END
GO