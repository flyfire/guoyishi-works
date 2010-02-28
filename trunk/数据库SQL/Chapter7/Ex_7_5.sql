use CollegeMIS
go
select StuNo, CourseNo = 
	case CourseNo
		when '0001' then '计算机应用基础'
		when '0002' then '程序设计基础'
		when '0003' then '操作系统'
		else '计算机网络技术'
	end, Score=
	case
		when Score >= 90 then '优秀'
		when Score >= 80 then '良好'
		when Score >= 70 then '中等'
		when Score >= 60 then '及格'
		else '不及格'
	end
from SelectCourse
order by StuNo desc
go