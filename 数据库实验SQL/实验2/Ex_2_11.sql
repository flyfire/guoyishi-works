USE TeachingMIS
GO
SELECT StuNo AS '学号', '计算机程序设计基础' AS '课程名',
       Score AS '成绩'
FROM SelectCourse
WHERE SchID = (SELECT SchID
               FROM CourseSchedule
               WHERE ClassID = '060202'
                     AND CourseNo = (SELECT CourseNo
                                     FROM Course
                                     WHERE CourseName = '计算机程序设计基础'
                                    )
              )
GO