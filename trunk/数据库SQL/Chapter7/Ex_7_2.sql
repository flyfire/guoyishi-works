use CollegeMIS
go
declare @XH as char(9)
declare @NUMBER as int
set @XH = '060301002'
select @NUMBER = count(*)
from SelectCourse
where StuNo = @XH
print @XH + '号学生选了' + convert( char(2), @NUMBER ) + '门课'
go