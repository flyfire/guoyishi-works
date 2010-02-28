USE TeachingMIS
GO
UPDATE FemaleTeacher
  SET Birthday = '1960-3-21',
      Marriage = 1
  WHERE TeaNo = '010088'
GO
SELECT * FROM Teacher
GO