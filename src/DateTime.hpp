#pragma once

#include "Date.hpp"
#include "Time.hpp"

namespace Calender {

struct DateTime
{
    Date date;
    Time time;

    bool operator==(const DateTime& dateTime) const
    {
        return (date == dateTime.date && time == dateTime.time);
    }

    friend std::ostream& operator<<(std::ostream& os, const DateTime& dateTime)
    {
        os << dateTime.date << " " << dateTime.time;
        return os;
    }
};
} // namespace Calender