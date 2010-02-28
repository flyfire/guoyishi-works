use CollegeMIS
go
select StuNo, CourseNo = 
	case CourseNo
		when '0001' then '�����Ӧ�û���'
		when '0002' then '������ƻ���'
		when '0003' then '����ϵͳ'
		else '��������缼��'
	end, Score=
	case
		when Score >= 90 then '����'
		when Score >= 80 then '����'
		when Score >= 70 then '�е�'
		when Score >= 60 then '����'
		else '������'
	end
from SelectCourse
order by StuNo desc
go