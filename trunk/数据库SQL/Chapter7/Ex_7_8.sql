declare @S as int
declare @I as smallint, @J as smallint
set @S = 0
set @I = 3
while @I < 100
	begin
		set @J = 2
		while @J < @I
			begin
				if @I % @J = 0
					break
				set @J = @J + 1
			end
		if @J = @I
			set @S = @S + @I
		set @I = @I + 1
	end
print 'Sum: ' + convert(char(6), @S)
go