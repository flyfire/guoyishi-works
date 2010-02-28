select StuNo, StuName, Sex, Major
from Student
where StuNo in (select StuNo
				from SelectCourse group by StuNo
				having count(*) > 3)