#include "Date.hpp"
#include "DateTime.hpp"
#include "DateTimeConverter.hpp"
#include "WeekDay.hpp"

#include <ctime>
#include <cstring>

using namespace Calender;

Date DateTimeConverter::secondsToDate(const unsigned long& seconds)
{
    const time_t time = static_cast<time_t>(seconds);
    tm epochTime;
    std::memcpy(&epochTime, localtime(&time), sizeof(tm));
    Date date (static_cast<unsigned>(epochTime.tm_year + 1900), 
               static_cast<unsigned>(epochTime.tm_mon + 1), 
               static_cast<unsigned>(epochTime.tm_mday));
    return date;
}

unsigned long DateTimeConverter::dateToSeconds(const Date& date)
{
    tm tmDate = {};

    tmDate.tm_mday = static_cast<int>(date.day());
    tmDate.tm_mon = static_cast<int>(date.month() - 1);
    tmDate.tm_year = static_cast<int>(date.year() - 1900);

    const time_t timeT = mktime(&tmDate);

    return static_cast<unsigned long>(timeT);
}

WeekDay DateTimeConverter::secondsToWeekday(const unsigned long& seconds)
{
    const time_t time = static_cast<time_t>(seconds);
    tm epochTime;
    std::memcpy(&epochTime, localtime(&time), sizeof(tm));
    return WeekDay(epochTime.tm_wday);
}

float DateTimeConverter::timeDiffInHours(Time& minuend, Time& subtrahend)
{
    int workHourDiff = minuend.hour() - subtrahend.hour();
    int workMinuteDiff = minuend.minute() - subtrahend.minute();
    if (workMinuteDiff < 0) {
        int minutesInHour = 60;
        workMinuteDiff += minutesInHour;
        workHourDiff--;
    }
    return workHourDiff + workMinuteDiff / 60.0 ;
}
