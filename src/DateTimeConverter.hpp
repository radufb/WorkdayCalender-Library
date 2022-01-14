#pragma once

namespace Calender {

    class Time;
    class Date;
    struct DateTime;
    enum WeekDay;

namespace DateTimeConverter {

    Calender::Date secondsToDate(const unsigned long& seconds);
    unsigned long dateToSeconds(const Calender::Date& date);
    Calender::WeekDay secondsToWeekday(const unsigned long& seconds);
    float timeDiffInHours(Calender::Time& minuend, Calender::Time& substrahend);

} // namespace DateTimeConverter

} // namespace Calender