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
    PRINT '教师信息插入成功!'
  ELSE
    BEGIN
      PRINT '系表中没有该系的信息,插入失败!'
      ROLLBACK TRANSACTION
    END
GO