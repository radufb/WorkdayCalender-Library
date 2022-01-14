#include "DateTime.hpp"
#include "Date.hpp"
#include "DateTimeConverter.hpp"
#include "Time.hpp"

#include <gtest/gtest.h>
#include <ctime>
#include <cstring>

using namespace Calender;

struct DateTimeConverterTest : public ::testing::Test {
    DateTimeConverterTest()
    : year(2021)
    , month(12)
    , day(28)
    , hour(19)
    , minute(6)
    , date(year, month, day)
    , tmDate{}
    {
        tmDate.tm_mday = static_cast<int>(day);
        tmDate.tm_mon = static_cast<int>(month - 1);
        tmDate.tm_year = static_cast<int>(year - 1900);

        timeTDate = mktime(&tmDate);
        dateInSeconds = static_cast<unsigned long>(timeTDate);
    }

    const unsigned year;
    const unsigned month;
    const unsigned day;
    const unsigned hour;
    const unsigned minute;

    Date date;
    tm tmDate;
    time_t timeTDate;
    unsigned long dateInSeconds;
};

TEST_F(DateTimeConverterTest, SecondsToDateTest)
{
    ASSERT_EQ(DateTimeConverter::secondsToDate(dateInSeconds), date);
}

TEST_F(DateTimeConverterTest, DateToSecondsTest)
{
    ASSERT_EQ(DateTimeConverter::dateToSeconds(date), dateInSeconds);
}

TEST_F(DateTimeConverterTest, SecondsToWeekdayTest)
{
    tm date = {};
    date.tm_min = 6;
    date.tm_hour = 19;
    date.tm_mday = 28;
    date.tm_mon = 12 - 1;
    date.tm_year = 2021 - 1900;

    time_t t = mktime(&date);
    const unsigned long seconds = static_cast<unsigned long>(t);

    ASSERT_EQ(DateTimeConverter::secondsToWeekday(seconds), WeekDay::TUESDAY);
}
