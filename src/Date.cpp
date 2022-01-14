#include "Date.hpp"
#include "DateTimeConverter.hpp"
#include "DateInfo.hpp"

#include <stdexcept>
#include <iomanip>

using namespace Calender;

Date::Date(unsigned year, unsigned month, unsigned day)
        : m_year(year), m_month(month), m_day(day)
{
    if(!DateInfo::isLegalYMD(year, month, day))
        throw std::runtime_error("Invalid input!");
    m_seconds = DateTimeConverter::dateToSeconds(*this);
}

unsigned Date::year() const
{
    return m_year;
}

unsigned Date::month() const
{
    return m_month;
}

unsigned Date::day() const
{
    return m_day;
}

WeekDay Date::getWeekday()
{
    return DateTimeConverter::secondsToWeekday(m_seconds);
}

bool Date::operator==(const Date& date) const
{
    return (m_year == date.year()
            && m_month == date.month()
            && m_day == date.day());
}

std::ostream& Calender::operator<<(std::ostream& os, const Date& date)
{
    os << std::setw(2) << std::setfill('0')
       << static_cast<unsigned int>(date.day()) << "."
       << std::setw(2) << std::setfill('0')
       << static_cast<unsigned int>(date.month()) << "."
       << std::setw(4) << std::setfill('0')
       << static_cast<unsigned int>(date.year());
    return os;
}