declare @S as int
declare @I as smallint
set @S = 0
set @I = 1
while @I <= 100
	begin
	if @I % 3 = 0
		set @S = @S + @I
	set @I = @I + 1
	end
print 'Sum: ' + convert(char(6), @S)
go