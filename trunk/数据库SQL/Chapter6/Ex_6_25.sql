create view NetStudent
as
select * from Student where Major = '计算机网络'
go
create view AppStudent
as
select * from Student where Major = '计算机应用'