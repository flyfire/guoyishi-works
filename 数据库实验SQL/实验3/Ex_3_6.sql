USE TeachingMIS
GO
/*
CREATE FUNCTION PJF(@CourseNo AS char(4), @ClassID AS char(6))
RETURNS DECIMAL(5, 2)
BEGIN
  DECLARE @PJF AS DECIMAL(5, 2)
  SELECT @PJF = AVG(Score) FROM SelectCourse
    WHERE SchID IN
      (SELECT SchID FROM CourseSchedule
      WHERE CourseNo = @CourseNo
      AND ClassID = @ClassID)
  RETURN @PJF
END
GO
*/
SELECT dbo.PJF('0003', '060201')