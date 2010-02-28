select StuNo, Score
from SelectCourse
where CourseNo = '0002' and Score > ANY( select Score from SelectCourse
										 where CourseNo = '0003')