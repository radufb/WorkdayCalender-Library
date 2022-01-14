#include "Calender/WorkdayCalender.hpp"
#include "Date.hpp"
#include "Time.hpp"
#include "DateTime.hpp"

#include <iostream>

using namespace Calender;

int main(void)
{
    auto print = [] (const DateTime& dateTime, float increment, const DateTime& result) {
        std::cout << dateTime << " with the addition of " << increment << " working days is " << result << std::endl;
    };

    WorkdayCalender workdayCalender;
    workdayCalender.setWorkdayStartAndStop(Time(8, 0), Time(16 ,0));
    workdayCalender.setHoliday(Date(2004, 5, 27));
    workdayCalender.setRecurringHoliday(Date(2004, 5, 17));

    float incrementInWorkdays = -5.5;
    DateTime start = { Date(2004, 5, 24), Time(18, 5) };
    DateTime result = workdayCalender.getWorkdayIncrement(start, incrementInWorkdays);
    print(start, incrementInWorkdays, result);

    incrementInWorkdays = 44.723656;
    start = { Date(2004, 5, 24), Time(19, 3) };
    result = workdayCalender.getWorkdayIncrement(start, incrementInWorkdays);
    print(start, incrementInWorkdays, result);

    incrementInWorkdays = -6.7470217;
    start = { Date(2004, 5, 24), Time(18, 3) };
    result = workdayCalender.getWorkdayIncrement(start, incrementInWorkdays);
    print(start, incrementInWorkdays, result);

    incrementInWorkdays = 12.782709;
    start = { Date(2004, 5, 24), Time(8, 3) };
    result = workdayCalender.getWorkdayIncrement(start, incrementInWorkdays);
    print(start, incrementInWorkdays, result);

    incrementInWorkdays = 8.276628;
    start = { Date(2004, 5, 24), Time(7, 3) };
    result = workdayCalender.getWorkdayIncrement(start, incrementInWorkdays);
    print(start, incrementInWorkdays, result);

    incrementInWorkdays = -6.7470217;
    start = { Date(2004, 5, 24), Time(13, 5) };
    result = workdayCalender.getWorkdayIncrement(start, incrementInWorkdays);
    print(start, incrementInWorkdays, result);

    incrementInWorkdays = -6.7470217;
    start = { Date(2004, 5, 24), Time(15, 5) };
    result = workdayCalender.getWorkdayIncrement(start, incrementInWorkdays);
    print(start, incrementInWorkdays, result);

    return 0;
}