create view ScoreReport
as
select S.StuNo, S.StuName, C.CourseNo, C.CourseName, SC.Score
from Student S inner join Course C inner join SelectCourse SC
on C.CourseNo = SC.CourseNo
on S.StuNo = SC.StuNo 
