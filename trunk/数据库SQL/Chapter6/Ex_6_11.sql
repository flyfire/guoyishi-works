select Student.StuName, SelectCourse.Score
from Student left join SelectCourse on Student.StuNo = SelectCourse.StuNo
where SelectCourse.CourseNo = '0001'