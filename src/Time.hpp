#pragma once

#include <iostream>

namespace Calender {

class Time {
public:
    Time() = default;
    Time(unsigned hour, unsigned minute);
    unsigned hour() const;
    unsigned minute() const;
    unsigned long toMinutes() const;

    bool operator==(const Time& other) const noexcept;
    bool operator<(const Time& other) const noexcept;
    bool operator>(const Time& other) const noexcept;
    bool operator<=(const Time& other) const noexcept;
    friend std::ostream& operator<<(std::ostream& os, const Time& time);

private:
    unsigned m_hour;
    unsigned m_minute;
};

std::ostream& operator<<(std::ostream& os, const Time& time);

} // namespace Calender