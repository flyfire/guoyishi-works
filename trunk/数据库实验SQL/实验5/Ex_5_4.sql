USE TeachingMIS
GO
ALTER TABLE Class
  DROP CONSTRAINT CK_ClassName
GO
ALTER TABLE Class
ADD CONSTRAINT CK_ClassName
  CHECK ( (left(ClassName,2)>=65 AND left(ClassName,2)<=99) OR
          (left(ClassName,2)>=00 AND left(ClassName,2)<=07) )
GO