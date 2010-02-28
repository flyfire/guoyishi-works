USE TeachingMIS
GO
SELECT CS.SchID AS '授课编号', CS.TeaNo AS '教师号',
       CO.CourseName AS '课程名', CS.ClassID AS '班号',
       Remark = 
         CASE
           WHEN CS.Remark = '优秀' THEN 9
           WHEN CS.Remark = '良好' THEN 8
           WHEN CS.Remark = '中等' THEN 7
           WHEN CS.Remark = '一般' THEN 6
           ELSE 5
         END
FROM CourseSchedule AS CS INNER JOIN Course AS CO
     ON CS.CourseNo = CO.CourseNo
ORDER BY CS.Remark DESC
GO
SELECT SchID, TeaNo, CourseNo =
  CASE CourseNo
    WHEN '0001' THEN '通信线路'
    WHEN '0002' THEN '大学计算机基础'
    WHEN '0003' THEN '计算机程序设计基础'
    ELSE '数据结构'
  END, ClassID,
  Remark =
  CASE
    WHEN Remark = '优秀' THEN 9
    WHEN Remark = '良好' THEN 8
    WHEN Remark = '中等' THEN 7
    WHEN Remark = '一般' THEN 6
    ELSE 5
  END
FROM CourseSchedule
ORDER BY Remark DESC