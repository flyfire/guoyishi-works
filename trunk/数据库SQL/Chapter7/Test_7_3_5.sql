declare @I as smallint
set @I = 0
while @I < 10
	begin
		waitfor delay '00:00:01'
		print 'Time: ' + convert(char(2), @I)
		set @I = @I + 1
	end
