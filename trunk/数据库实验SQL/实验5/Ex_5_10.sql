USE TeachingMIS
GO
/*
CREATE RULE Score_Rule
AS
  @Score <= 0 AND @Score <= 100
GO
EXECUTE sp_bindrule 'Score_Rule', 'SelectCourse.Score'
GO
*/
EXECUTE sp_unbindrule 'SelectCourse.Score'
GO