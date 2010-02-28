declare @S as int, @T as int
declare @I as smallint
set @S = 0
set @I = 1
while @I <= 10
	begin
		set @T = @I * @I
		set @S = @S + @T
		set @I = @I + 1
	end
print 'ֵΪ:' + convert(char(6), @S)
go