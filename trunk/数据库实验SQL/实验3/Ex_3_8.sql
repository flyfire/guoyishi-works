USE TeachingMIS
GO
/*
CREATE FUNCTION Teacher_Total(@TeaNo AS char(6))
RETURNS @T TABLE
(�γ̺� char(4),
�༶�� char(6),
ƽ���� DECIMAL(5, 2),
��߷� TINYINT,
��ͷ� TINYINT
) AS
BEGIN
  INSERT @T
    SELECT CS.CourseNo AS '�γ̺�', CS.ClassID AS '�༶��',
           AVG(SC.Score) AS 'ƽ����', MAX(SC.Score) AS '��߷�',
           MIN(SC.Score) AS '��ͷ�'
    FROM CourseSchedule AS CS INNER JOIN SelectCourse AS SC
         ON CS.SchID = SC.SchID
    WHERE CS.TeaNo = @TeaNo
    GROUP BY CS.CourseNo, CS.ClassID
  RETURN
END
GO
*/
SELECT * FROM Teacher_Total('010001')