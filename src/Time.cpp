#include "Time.hpp"

#include <stdexcept>
#include <iomanip>

using namespace Calender;

Time::Time(unsigned hour, unsigned minute)
        : m_hour(hour), m_minute(minute)
{
    if( !(hour <= 23) || !(minute <= 59) )
        throw std::runtime_error("Invalid input!");
}

unsigned Time::hour() const
{
    return m_hour;
}

unsigned Time::minute() const
{
    return m_minute;
}

unsigned long Time::toMinutes() const
{
    return m_hour * 60 + m_minute;
}

bool Time::operator==(const Time& other) const noexcept
{
    return (m_hour == other.hour() && m_minute == other.minute());
}

bool Time::operator<(const Time& other) const noexcept
{
    return (this->toMinutes() < other.toMinutes());
}

bool Time::operator>(const Time& other) const noexcept
{
    return (this->toMinutes() > other.toMinutes());
}

bool Time::operator<=(const Time& other) const noexcept
{
    return (this->toMinutes() < other.toMinutes() || this->toMinutes() == other.toMinutes());
}

std::ostream& Calender::operator<<(std::ostream& os, const Time& time)
{
    os << std::setw(2) << std::setfill('0')
       << time.hour() << ":"
       << std::setw(2) << std::setfill('0')
       << time.minute();
    return os;
}