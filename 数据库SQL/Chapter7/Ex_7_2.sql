use CollegeMIS
go
declare @XH as char(9)
declare @NUMBER as int
set @XH = '060301002'
select @NUMBER = count(*)
from SelectCourse
where StuNo = @XH
print @XH + '��ѧ��ѡ��' + convert( char(2), @NUMBER ) + '�ſ�'
go