USE TeachingMIS
GO
SELECT StuNo, StuName, Sex, Telephone
FROM Student
WHERE Grade = 2 AND Major = '������������'
ORDER BY Sex DESC
GO