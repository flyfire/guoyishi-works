select StuNo, StuName, Sex
from Student
where Major='�����Ӧ��'
and StuNo in (select StuNo from SelectCourse
				group by StuNo having avg(Score) >= 75)

UNION

select StuNo, StuName, Sex
from Student
where Major = '���������'
and StuNo in (select StuNo from SelectCourse
				group by StuNo having avg(Score) >= 75)