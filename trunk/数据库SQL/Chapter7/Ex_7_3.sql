use CollegeMIS
go
declare @CourseNo as char(4)
declare @GoodNum as int
set @CourseNo = '0002'
if exists( select * from SelectCourse where CourseNo = @CourseNo and Score >= 90 )

	begin
		select @GoodNum = Count(StuNo)
		from SelectCourse
		where CourseNo = @CourseNo and Score >= 90
		print '0002号课程优秀人数为:' + convert(char(2), @GoodNum) + '人'
	end
else
	print '0002号课程没有人获得优秀成绩'
go