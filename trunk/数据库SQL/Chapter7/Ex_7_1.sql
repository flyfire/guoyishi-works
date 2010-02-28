use CollegeMIS
go
declare @ERRORNO int
insert into Student(StuNo, StuName, StuID)
values( '050301001', '王高林', '324382475454342321')
set @ERRORNO = @@ERROR
if @ERRORNO <> 0
print '插入错误!'+'错误号'+convert(varchar, @ERRORNO)