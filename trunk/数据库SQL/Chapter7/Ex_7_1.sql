use CollegeMIS
go
declare @ERRORNO int
insert into Student(StuNo, StuName, StuID)
values( '050301001', '������', '324382475454342321')
set @ERRORNO = @@ERROR
if @ERRORNO <> 0
print '�������!'+'�����'+convert(varchar, @ERRORNO)