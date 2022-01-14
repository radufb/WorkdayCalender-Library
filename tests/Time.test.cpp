#include "Time.hpp"

#include <gtest/gtest.h>

using namespace Calender;

struct TimeTest : public ::testing::Test {

    Time workdayStart;
    Time workdayStop;
    void SetUp() override
    {
        workdayStart = Time(8, 0);
        workdayStop = Time(16, 0);
    }
};

TEST_F(TimeTest, InvalidTimeTest)
{
    EXPECT_THROW(Time(25, 1), std::runtime_error);
    EXPECT_THROW(Time(14, 60), std::runtime_error);
    EXPECT_THROW(Time(24, 0), std::runtime_error);
}