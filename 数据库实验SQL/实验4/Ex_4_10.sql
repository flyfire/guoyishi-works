USE TeachingMIS
GO
ALTER PROCEDURE Proc_MaleTeacher
AS
  SELECT TeaNo AS '教师号', TeaName AS '姓名',
         Sex AS '性别', Title AS '职称',
         Marriage AS '婚否', Telephone AS '电话号码'
  FROM Teacher
  WHERE Sex = '男'
GO
EXECUTE Proc_MaleTeacher
GO