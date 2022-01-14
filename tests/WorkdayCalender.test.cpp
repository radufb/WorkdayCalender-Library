#include "Calender/WorkdayCalender.hpp"

#include <gtest/gtest.h>

using namespace Calender;

struct WorkdayCalenderTest : public ::testing::Test {
    WorkdayCalender workdayCalender;
    DateTime start;
    DateTime result;
    DateTime expected;
    
    void SetUp() override
    {
        workdayCalender.setWorkdayStartAndStop(Time(8, 0), Time(16 ,0));
        workdayCalender.setHoliday(Date(2004, 5, 27));
        workdayCalender.setRecurringHoliday(Date(2003, 5, 17));
    }
};

TEST_F(WorkdayCalenderTest, PositiveIncrementTest_1)
{
    const float incrementInWorkdays = 44.723656;
    start = { Date(2004, 5, 24), Time(19, 3) };
    result = workdayCalender.getWorkdayIncrement(start, incrementInWorkdays);
    expected = { Date(2004, 7, 27), Time(13, 47) };

    ASSERT_EQ(result, expected);
}

TEST_F(WorkdayCalenderTest, PositiveIncrementTest_2)
{
    const float incrementInWorkdays = 12.782709;
    start = { Date(2004, 5, 24), Time(8, 3) };
    result = workdayCalender.getWorkdayIncrement(start, incrementInWorkdays);
    expected = { Date(2004, 6, 10), Time(14, 18) };

    ASSERT_EQ(result, expected);
}

TEST_F(WorkdayCalenderTest, PositiveIncrementTest_3)
{
    const float incrementInWorkdays = 8.276628;
    start = { Date(2004, 5, 24), Time(7, 3) };
    result = workdayCalender.getWorkdayIncrement(start, incrementInWorkdays);
    expected = { Date(2004, 6, 4), Time(10, 12) };

    ASSERT_EQ(result, expected);
}

TEST_F(WorkdayCalenderTest, NoIncrementTest)
{
    const float incrementInWorkdays = 0.0;
    start = { Date(2004, 5, 24), Time(7, 3) };
    result = workdayCalender.getWorkdayIncrement(start, incrementInWorkdays);
    expected = { Date(2004, 5, 24), Time(8, 0) };

    ASSERT_EQ(result, expected);
}

TEST_F(WorkdayCalenderTest, NegativeIncrementTest_1)
{
    const float incrementInWorkdays = -5.5;
    start = { Date(2004, 5, 24), Time(18, 5) };
    result = workdayCalender.getWorkdayIncrement(start, incrementInWorkdays);
    expected = { Date(2004, 5, 14), Time(12, 0) };

    ASSERT_EQ(result, expected);
}

TEST_F(WorkdayCalenderTest, NegativeIncrementTest_2)
{
    const float incrementInWorkdays = -6.7470217;
    start = { Date(2004, 5, 24), Time(18, 3) };
    result = workdayCalender.getWorkdayIncrement(start, incrementInWorkdays);
    expected = { Date(2004, 5, 13), Time(10, 2) };

    ASSERT_EQ(result, expected);
}

TEST_F(WorkdayCalenderTest, NegativeIncrementTest_3)
{
    const float incrementInWorkdays = -6.7470217;
    start = { Date(2004, 5, 24), Time(13, 5) };
    DateTime result = workdayCalender.getWorkdayIncrement(start, incrementInWorkdays);
    expected = { Date(2004, 5, 12), Time(15, 7) };

    ASSERT_EQ(result, expected);
}

TEST_F(WorkdayCalenderTest, NegativeIncrementTest_4)
{
    const float incrementInWorkdays = -6.7470217;
    start = { Date(2004, 5, 24), Time(7, 25) };
    result = workdayCalender.getWorkdayIncrement(start, incrementInWorkdays);
    expected = { Date(2004, 5, 12), Time(10, 2) };

    ASSERT_EQ(result, expected);
}

TEST_F(WorkdayCalenderTest, NegativeIncrementTest_5)
{
    const float incrementInWorkdays = -6.7470217;
    start = { Date(2004, 5, 24), Time(15, 5) };
    result = workdayCalender.getWorkdayIncrement(start, incrementInWorkdays);
    expected = { Date(2004, 5, 13), Time(9, 7) };

    ASSERT_EQ(result, expected);
}
