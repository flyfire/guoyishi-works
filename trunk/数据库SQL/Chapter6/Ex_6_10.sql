select Student.StuNo, Student.StuName, SelectCourse.CourseNo, SelectCourse.Score
from Student left join SelectCourse on Student.StuNo = SelectCourse.StuNo