USE CollegeMIS
GO
CREATE DEFAULT Sex_Default AS '��'
GO
EXEC sp_bindefault 'Sex_Default','Teacher.Sex'
GO