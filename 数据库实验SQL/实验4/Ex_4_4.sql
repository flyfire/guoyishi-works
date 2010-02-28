USE TeachingMIS
GO
DROP VIEW FemaleTeacher
GO
CREATE VIEW FemaleTeacher
AS
  SELECT * FROM Teacher
  WHERE Sex = 'Ů'
WITH CHECK OPTION
GO
SELECT * FROM FemaleTeacher
GO