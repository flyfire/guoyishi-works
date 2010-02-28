USE TeachingMIS
GO
SELECT T.TeaNo, T.TeaName, CS.CourseNo, CS.ClassID, CS.Remark
FROM Teacher T INNER JOIN CourseSchedule CS
ON T.TeaNo = CS.TeaNo
WHERE T.DepartID = '02'
GO

SELECT T.TeaNo, T.TeaName, CS.CourseNo, CS.ClassID, CS.Remark
FROM Teacher T, CourseSchedule CS
WHERE T.TeaNo = CS.TeaNo
AND T.DepartID = '02'
GO