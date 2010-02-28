USE CollegeMIS
GO
IF EXISTS (SELECT name FROM sysobjects
           WHERE name = 'Delete_Teacher' AND type = 'TR')
  DROP TRIGGER Delete_Teacher
GO