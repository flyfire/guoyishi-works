USE CollegeMIS
GO
CREATE DEFAULT Sex_Default AS 'ÄÐ'
GO
EXEC sp_bindefault 'Sex_Default','Teacher.Sex'
GO