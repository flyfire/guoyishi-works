USE TeachingMIS
GO
ALTER PROCEDURE Proc_MaleTeacher
AS
  SELECT TeaNo AS '��ʦ��', TeaName AS '����',
         Sex AS '�Ա�', Title AS 'ְ��',
         Marriage AS '���', Telephone AS '�绰����'
  FROM Teacher
  WHERE Sex = '��'
GO
EXECUTE Proc_MaleTeacher
GO