USE CollegeMIS
GO
ALTER TABLE SelectCourse
  DROP CONSTRAINT pk_xuanke
GO
ALTER TABLE SelectCourse
  ADD CONSTRAINT pk_xuanke
  PRIMARY KEY ( StuNo, TeaNo, CourseNo )
GO