#include "DateInfo.hpp"

#include <gtest/gtest.h>

using namespace Calender;

struct DateInfoTest : public ::testing::Test {
    const unsigned leapYear = 1992;
    const unsigned notLeapYear = 1900;

    const unsigned legalYMD[3] { 2001, 11, 9 } ;
    const unsigned ilegalYMD_1[3] { 2001, 15, 10 };
    const unsigned ilegalYMD_2[3] { 2001, 10, 43 };
};

TEST_F(DateInfoTest, LeapYearTest)
{
    ASSERT_EQ(DateInfo::isLeapYear(leapYear), true);
    ASSERT_EQ(DateInfo::isLeapYear(notLeapYear), false);
}

TEST_F(DateInfoTest, LegalYMDTest)
{
    ASSERT_EQ(DateInfo::isLegalYMD(legalYMD[0], legalYMD[1], legalYMD[2]), true);
}

TEST_F(DateInfoTest, IlegalYMDTest)
{
    ASSERT_EQ(DateInfo::isLegalYMD(ilegalYMD_1[0], ilegalYMD_1[1], ilegalYMD_1[2]), false);
    ASSERT_EQ(DateInfo::isLegalYMD(ilegalYMD_2[0], ilegalYMD_2[1], ilegalYMD_2[2]), false);
}