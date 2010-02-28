select SC.StuNo, SC.CourseNo, C.CourseName, SC.Score
from Course C inner join SelectCourse SC on C.CourseNo = SC.CourseNo
where StuNo in ( select StuNo from Student
				 where Major = '¼ÆËã»úÍøÂç')