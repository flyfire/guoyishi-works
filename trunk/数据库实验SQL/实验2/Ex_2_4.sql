USE TeachingMIS
GO
SELECT TeaName AS '教师姓名', Title AS '职称',
       Sex AS '性别', Birthday AS '出生日期'
FROM Teacher
ORDER BY Title ASC, Sex ASC
GO 