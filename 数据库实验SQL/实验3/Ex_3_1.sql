USE TeachingMIS
GO
DECLARE @Remark char(6)
SET @Remark = '����'
IF EXISTS (SELECT *
           FROM CourseSchedule
           WHERE Remark = @Remark)
  BEGIN
    SELECT T.TeaNo AS '��ʦ��', T.TeaName AS '��ʦ��',
           C.CourseNo AS '�γ̺�', C.CourseName AS '�γ���',
           CL.ClassID AS '�༶��', CL.ClassName AS '�༶��'
      FROM Teacher AS T INNER JOIN CourseSchedule AS CS
           ON T.TeaNo = CS.TeaNo
           INNER JOIN Course AS C ON C.CourseNo = CS.CourseNo
           INNEr JOIN Class AS CL ON CL.ClassID = CS.ClassID
     WHERE CS.Remark = @Remark
  END
GO