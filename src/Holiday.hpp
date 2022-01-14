#pragma once

#include "Date.hpp"

namespace Calender {

struct Holiday {
    Calender::Date date;
    bool isRecurring;
}; 

} // namespace Calender