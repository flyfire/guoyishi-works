USE CollegeMIS
GO
DECLARE @XH char(9), @JSH char(6)
DECLARE @KCH char(4), @CJ tinyint
DECLARE GoodScorecur CURSOR
  LOCAL SCROLL
  FOR
    SELECT * FROM SelectCourse
    WHERE Score >= 90
  FOR UPDATE OF Score
OPEN GoodScorecur
FETCH NEXT FROM GoodScorecur
  INTO @XH, @JSH, @KCH, @CJ
WHILE @@FETCH_STATUS = 0
  BEGIN
    UPDATE SelectCourse SET Score = Score - 1
    WHERE CURRENT OF GoodScorecur
    FETCH NEXT FROM GoodScorecur
      INTO @XH, @JSH, @KCH, @CJ
  END
CLOSE GoodScorecur
DEALLOCATE GoodScorecur
GO
SELECT * FROM SelectCourse
WHERE Score >= 90
GO