#pragma once

#include "Date.hpp"
#include "DateTime.hpp"
#include "Holiday.hpp"
#include "Time.hpp"
#include "WeekDay.hpp"

#include <vector>

namespace Calender {

class WorkdayCalender {
public:
    WorkdayCalender() = default;
    void setHoliday(const Date& date);
    void setRecurringHoliday(const Date& date);  
    void setWorkdayStartAndStop(const Time& start, const Time& stop);
    DateTime getWorkdayIncrement(const DateTime& startDateTime, const float& incrementInWorkdays);

private:
    Time m_workdayStartTime;
    Time m_workdayStopTime;
    std::vector<Holiday> m_holidays;
    Date incrementDate(Date& startDate, int& workDaysToIncrement);
    Time incrementTime(Time& baseTime, float& workHoursToIncrement);
    bool isWorkday(const WeekDay& weekDay) const;
    bool isHoliday(const Date& date) const;
    bool isWithinWorkhours(const Time& startTime);
    unsigned getTotalWorkdayHours();
};

} // namespace Calender