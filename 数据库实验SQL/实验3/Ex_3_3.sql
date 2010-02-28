USE TeachingMIS
GO
SELECT CS.SchID AS '�ڿα��', CS.TeaNo AS '��ʦ��',
       CO.CourseName AS '�γ���', CS.ClassID AS '���',
       Remark = 
         CASE
           WHEN CS.Remark = '����' THEN 9
           WHEN CS.Remark = '����' THEN 8
           WHEN CS.Remark = '�е�' THEN 7
           WHEN CS.Remark = 'һ��' THEN 6
           ELSE 5
         END
FROM CourseSchedule AS CS INNER JOIN Course AS CO
     ON CS.CourseNo = CO.CourseNo
ORDER BY CS.Remark DESC
GO
SELECT SchID, TeaNo, CourseNo =
  CASE CourseNo
    WHEN '0001' THEN 'ͨ����·'
    WHEN '0002' THEN '��ѧ���������'
    WHEN '0003' THEN '�����������ƻ���'
    ELSE '���ݽṹ'
  END, ClassID,
  Remark =
  CASE
    WHEN Remark = '����' THEN 9
    WHEN Remark = '����' THEN 8
    WHEN Remark = '�е�' THEN 7
    WHEN Remark = 'һ��' THEN 6
    ELSE 5
  END
FROM CourseSchedule
ORDER BY Remark DESC