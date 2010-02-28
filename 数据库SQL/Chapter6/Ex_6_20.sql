use CollegeMIS
select * from SelectCourse
order by StuNo
compute SUM(Score), AVG(Score), Count(CourseNo) by StuNo