USE CollegeMIS
GO
CREATE RULE Sex_Rule AS @Sex = '��' OR @Sex = 'Ů'
GO
EXEC sp_bindrule 'Sex_Rule', 'Student.Sex'
EXEC sp_bindrule 'Sex_Rule', 'Teacher.Sex'
GO