USE TeachingMIS
GO
DROP PROCEDURE Proc_MaleTeacher
GO
CREATE PROCEDURE Proc_MaleTeacher
AS
  SELECT * FROM Teacher
  WHERE Sex = 'ÄÐ'
GO