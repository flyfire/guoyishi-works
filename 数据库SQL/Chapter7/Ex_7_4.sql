use CollegeMIS
go
select StuNo, CourseNo = 
	case CourseNo
		when '0001' then '�����Ӧ�û���'
		when '0002' then '������ƻ���'
		when '0003' then '����ϵͳ'
		else '��������缼��'
	end, Score
from SelectCourse
order by Score desc