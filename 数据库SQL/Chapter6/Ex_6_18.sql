select CourseNo as '�κ�', AVG(Score) as 'ƽ���ɼ�', MAX(Score) as '��߳ɼ�', MIN(Score) as '��ͳɼ�', COUNT(StuNo) as 'ѡ������'
from SelectCourse group by CourseNo