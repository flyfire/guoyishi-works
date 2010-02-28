USE CollegeMIS
GO
ALTER TABLE Department
  DROP CONSTRAINT IX_Telphone
GO
ALTER TABLE Department
  ADD CONSTRAINT IX_Telphone
  UNIQUE (Telephone)
GO