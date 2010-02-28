USE TeachingMIS
GO
SELECT StuNo, StuName, Sex, Telephone
FROM Student
WHERE Grade = 2 AND Major = '计算机软件技术'
ORDER BY Sex DESC
GO