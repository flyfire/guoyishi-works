select CourseNo as '课号', AVG(Score) as '平均成绩', MAX(Score) as '最高成绩', MIN(Score) as '最低成绩', COUNT(StuNo) as '选课人数'
from SelectCourse group by CourseNo