Use CollegeMIS
select X1.StuNo, X1.Score
from SelectCourse X1, Student S, SelectCourse X2
where X1.CourseNo = X2.CourseNo and X1.CourseNo = '0001'
and X1.Score > X2.Score and X2.StuNo = S.StuNo and S.StuName = 'Ì¸ºÍÆ½'