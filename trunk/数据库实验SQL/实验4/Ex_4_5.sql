USE TeachingMIS
GO
IF NOT EXISTS ( SELECT * FROM Teacher WHERE TeaNo = '010088' )
  INSERT INTO FemaleTeacher (TeaNo, TeaName, TeaID, Sex, Title, DepartID)
  VALUES ( '010088', '�ι��', '1231234567891234', 'Ů', '������', '01')
GO
SELECT * FROM  FemaleTeacher
GO
SELECT * FROM Teacher
GO
