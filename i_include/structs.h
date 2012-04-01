#ifndef DATETIME_H
#define DATETIME_H


namespace Date{
  class time{
  public:
    short hours;
    short minutes;
    short seconds;
  };
  class date{
  public:
    short day;
    short month;
    short year;
    time _time;
  };
}

#endif
