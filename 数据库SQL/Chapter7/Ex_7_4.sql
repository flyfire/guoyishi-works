use CollegeMIS
go
select StuNo, CourseNo = 
	case CourseNo
		when '0001' then '计算机应用基础'
		when '0002' then '程序设计基础'
		when '0003' then '操作系统'
		else '计算机网络技术'
	end, Score
from SelectCourse
order by Score desc