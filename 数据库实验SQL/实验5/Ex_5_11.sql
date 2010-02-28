USE TeachingMIS
GO
DROP DEFAULT Sex_Default
GO
/*
CREATE DEFAULT Sex_Default AS 'ÄÐ'
GO
*/
/*
EXECUTE sp_bindefault 'Sex_Default', 'Teacher.Sex'
GO
*/
/*
EXECUTE sp_unbindefault 'Teacher.Sex'
GO
*/