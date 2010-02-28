Use CollegeMIS
select Student.StuNo, Student.StuName, SelectCourse.CourseNo, SelectCourse.Score
from Student, SelectCourse
where Student.StuNo = SelectCourse.StuNo