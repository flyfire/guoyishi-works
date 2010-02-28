USE CollegeMIS
GO
CREATE TRIGGER Delete_Teacher ON Teacher
  FOR DELETE
  AS
    IF( SELECT COUNT(*)
          FROM SelectCourse INNER JOIN Deleted
          ON SelectCourse.TeaNo = Deleted.TeaNo ) > 0
      BEGIN
        PRINT '�ý�ʦ��ѡ�α����Ѿ����ڿ���Ϣ,����ɾ��!'
        ROLLBACK TRANSACTION
      END
    ELSE
      PRINT '��¼ɾ���ɹ�!'
GO