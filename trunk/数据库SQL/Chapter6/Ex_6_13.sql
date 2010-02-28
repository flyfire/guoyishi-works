use CollegeMIS
select StuNo
from SelectCourse
where CourseNo = 
				(select CourseNo from Course
				 where CourseName = '程序设计基础' )