Use CollegeMIS
select Student.StuNo, Student.StuName, SelectCourse.CourseNo, SelectCourse.Score
from Student inner join SelectCourse on Student.StuNo = SelectCourse.StuNo