USE CollegeMIS
GO
CREATE RULE Sex_Rule AS @Sex = 'ÄÐ' OR @Sex = 'Å®'
GO
EXEC sp_bindrule 'Sex_Rule', 'Student.Sex'
EXEC sp_bindrule 'Sex_Rule', 'Teacher.Sex'
GO