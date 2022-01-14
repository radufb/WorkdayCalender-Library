#pragma once

#include "WeekDay.hpp"

#include <iostream>

namespace Calender { 

class Date {
public:
    Date() = default;
    Date(unsigned year, unsigned month, unsigned day);
    unsigned year() const;
    unsigned month() const;
    unsigned day() const; 
    WeekDay getWeekday();
    bool operator==(const Date& date) const;
    friend std::ostream& operator<<(std::ostream& os, const Date& date);

private:
    unsigned long m_seconds; // date in seconds since the year 1900
    unsigned m_year;
    unsigned m_month;
    unsigned m_day;
};

std::ostream& operator<<(std::ostream& os, const Date& date);

} // namespace Calender