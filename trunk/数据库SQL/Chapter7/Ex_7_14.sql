USE CollegeMIS
GO
DECLARE @XH char(9), @JSH char(6)
DECLARE @KCH char(4), @CJ tinyint
DECLARE GoodScorecur CURSOR
  LOCAL SCROLL
  FOR
    SELECT * FROM SelectCourse WHERE Score >= 90
OPEN GoodScorecur
PRINT '   ѧ��   ' + '  ' + '��ʦ��' + '   ' + '�γ̺�' + '   ' + '�ɼ�'
FETCH NEXT FROM GoodScorecur
INTO @XH, @JSH, @KCH, @CJ
WHILE @@FETCH_STATUS = 0
  BEGIN
    PRINT @XH + '   ' + @JSH + '   ' +
          @KCH + '     ' + CONVERT(char(3), @CJ)
    FETCH NEXT FROM GoodScorecur
    INTO @XH, @JSH, @KCH, @CJ
  END
CLOSE GoodScorecur
DEALLOCATE GoodScorecur
GO