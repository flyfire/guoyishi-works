USE TeachingMIS
GO
DROP PROCEDURE Proc_TeaCourseCX
GO
CREATE PROCEDURE Proc_TeaCourseCX @TeaNo char(6)
AS
  SELECT T.TeaNo AS '��ʦ��', T.TeaName AS '����',
         C.CourseName AS '�γ���', CL.ClassName AS '�༶��',
         CS.Remark AS '����'
  FROM CourseSchedule AS CS INNER JOIN Teacher AS T
    ON CS.TeaNo = T.TeaNo
    INNER JOIN Course AS C
    ON CS.CourseNo = C.CourseNo
    INNER JOIN Class AS CL
    ON CS.ClassID = CL.ClassID
  WHERE CS.TeaNo = @TeaNo
GO
EXECUTE Proc_TeaCourseCX '020010'
GO