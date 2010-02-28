USE CollegeMIS
GO
ALTER TABLE Student
  DROP CONSTRAINT CK_Birthday
GO
ALTER TABLE Student
  ADD CONSTRAINT CK_Birthday
  CHECK (Birthday <= GetDate())
GO