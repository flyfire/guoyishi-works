use CollegeMIS
select StuNo
from SelectCourse
where CourseNo = 
				(select CourseNo from Course
				 where CourseName = '������ƻ���' )