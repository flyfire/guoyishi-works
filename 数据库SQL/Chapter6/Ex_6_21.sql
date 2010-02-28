select StuNo, StuName, Sex
from Student
where Major='计算机应用'
and StuNo in (select StuNo from SelectCourse
				group by StuNo having avg(Score) >= 75)

UNION

select StuNo, StuName, Sex
from Student
where Major = '计算机网络'
and StuNo in (select StuNo from SelectCourse
				group by StuNo having avg(Score) >= 75)