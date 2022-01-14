#pragma once

namespace Calender {

namespace DateInfo {

/* We discard the 0 element so that users can access the values in a more natural manner */
const unsigned DAYS_IN_MONTH [13] {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isLeapYear (unsigned const& year) {
    return (0 == year % 4) && ((0 != year % 100) || (0 == year % 400)); 
}

bool isLegalYMD (unsigned const& year, unsigned const& month, unsigned const& day) {
    return month > 0 && month <= 12 && day > 0 && 
        (day <= DAYS_IN_MONTH[month] || (day == 29 && month == 2 && isLeapYear(year)));
}

} // namespace DateInfo
} // namespace Calender