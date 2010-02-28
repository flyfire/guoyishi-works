USE CollegeMIS
GO
EXEC sp_unbindrule 'Student.Sex'
EXEC sp_unbindrule 'Teacher.Sex'
GO
DROP RULE Sex_Rule
GO