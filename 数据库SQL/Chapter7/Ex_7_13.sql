USE CollegeMIS
GO
DECLARE GoodScorecur CURSOR
  LOCAL SCROLL
  FOR
    SELECT *
    FROM SelectCourse WHERE Score >= 90
GO