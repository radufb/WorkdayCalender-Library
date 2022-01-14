#include "Calender/WorkdayCalender.hpp"
#include "DateTimeConverter.hpp"

#include <cstdlib>

using namespace Calender;

void WorkdayCalender::setHoliday(const Date& date)
{
    m_holidays.push_back(Holiday {date, false});
}

void WorkdayCalender::setRecurringHoliday(const Date& date)
{
    m_holidays.push_back(Holiday {date, true});
}

void WorkdayCalender::setWorkdayStartAndStop(const Time& start, const Time& stop)
{
    m_workdayStartTime = start;
    m_workdayStopTime = stop;
}

DateTime WorkdayCalender::getWorkdayIncrement(const DateTime& startDateTime, const float& incrementInWorkdays)
{
    Date startDate = startDateTime.date;
    Time startTime = startDateTime.time;

    float increment = incrementInWorkdays;
    float timeDiffInHours;

    if (increment > 0 || increment == 0) {
        if (m_workdayStopTime <= startTime) {
            increment++;
        } else if (isWithinWorkhours(startTime)) {
            timeDiffInHours = DateTimeConverter::timeDiffInHours(startTime, m_workdayStartTime);
            increment += timeDiffInHours / getTotalWorkdayHours(); // add the difference in hours to the total increment
        }
        startTime = m_workdayStartTime; // reset start time
    } else { // negative incrementing
        if (startTime < m_workdayStartTime) {
            increment--;
        } else if (isWithinWorkhours(startTime)) {
            timeDiffInHours = DateTimeConverter::timeDiffInHours(m_workdayStopTime, startTime);
            increment -= timeDiffInHours / getTotalWorkdayHours(); // add the difference in hours to the total increment
        }
        startTime = m_workdayStopTime; // reset start time
    }

    int workDaysToIncrement = increment; // extract the integer part
    float workHoursToIncrement = (increment - workDaysToIncrement) * getTotalWorkdayHours(); // extract fractional part and transform to work hours

    DateTime result;
    result.date = incrementDate(startDate, workDaysToIncrement);
    result.time = incrementTime(startTime, workHoursToIncrement);

    return result;
}

Date WorkdayCalender::incrementDate(Date& startDate, int& workDaysToIncrement)
{
    unsigned const dayInSeconds = 86400; // 24h * 60min * 60sec 
    unsigned long currentDateInSec = DateTimeConverter::dateToSeconds(startDate);
    Date date;

    while (workDaysToIncrement != 0) {
        if (workDaysToIncrement > 0) {
            currentDateInSec += dayInSeconds;
            date = DateTimeConverter::secondsToDate(currentDateInSec);
            if (isHoliday(date)) 
                continue;
            if (isWorkday(date.getWeekday()))
                workDaysToIncrement--;
        } else {
            currentDateInSec -= dayInSeconds;
            date = DateTimeConverter::secondsToDate(currentDateInSec);
            if (isHoliday(date)) 
                continue;
            if(isWorkday(date.getWeekday()))
                workDaysToIncrement++;
        }
    }
    Date result = DateTimeConverter::secondsToDate(currentDateInSec);
    return result;
}

Time WorkdayCalender::incrementTime(Time& baseTime, float& workHoursToIncrement)
{
    int minutesToIncrement;
    int hoursToIncrement = workHoursToIncrement;
    int oneHourInMinutes = 60;

    if (workHoursToIncrement < 0) {
        minutesToIncrement = (workHoursToIncrement - static_cast<int>(workHoursToIncrement)) * 60.0; // extract minutes from workhour
        if (minutesToIncrement < 0) {
            minutesToIncrement += oneHourInMinutes;
            hoursToIncrement--;
        }
    } else {
        minutesToIncrement = (workHoursToIncrement - static_cast<int>(workHoursToIncrement)) * 60.0;
    }
    return Time(baseTime.hour() + hoursToIncrement, baseTime.minute() + minutesToIncrement);  
}

unsigned WorkdayCalender::getTotalWorkdayHours()
{
    return m_workdayStopTime.hour() - m_workdayStartTime.hour();
}

bool WorkdayCalender::isWorkday(const WeekDay& weekDay) const
{
    return (weekDay != WeekDay::SATURDAY && weekDay != WeekDay::SUNDAY);
}

bool WorkdayCalender::isHoliday(const Date& date) const
{
    for (Holiday holiday : m_holidays) {
        if (holiday.date == date) {
            if (holiday.isRecurring || holiday.date.year() == date.year()) {
                return true;
            }
        }
    }
    return false;
}

bool WorkdayCalender::isWithinWorkhours(const Time& startTime)
{
    return (m_workdayStartTime <= startTime && startTime <= m_workdayStopTime ); 
}