USE TeachingMIS
GO
ALTER TABLE Teacher
  DROP CONSTRAINT DF_Teacher_Title
GO
ALTER TABLE Teacher
  ADD CONSTRAINT DF_Teacher_Title
  DEFAULT '����' FOR Title
GO