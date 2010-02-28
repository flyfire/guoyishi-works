select * from SelectCourse where CourseNo = '0003'
and exists (select * from SelectCourse where CourseNo = '0003')