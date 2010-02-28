USE CollegeMIS
GO
CREATE TRIGGER Delete_Teacher ON Teacher
  FOR DELETE
  AS
    IF( SELECT COUNT(*)
          FROM SelectCourse INNER JOIN Deleted
          ON SelectCourse.TeaNo = Deleted.TeaNo ) > 0
      BEGIN
        PRINT '该教师在选课表中已经有授课信息,不能删除!'
        ROLLBACK TRANSACTION
      END
    ELSE
      PRINT '记录删除成功!'
GO