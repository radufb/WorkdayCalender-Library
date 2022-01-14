add_compile_options(-Wall -Wextra -Wpedantic)

include(GoogleTest)
enable_testing()

add_executable(DateInfo-test DateInfo.test.cpp)
target_link_libraries(DateInfo-test PRIVATE gtest_main)

add_executable(WorkdayCalender-test WorkdayCalender.test.cpp)
target_link_libraries(WorkdayCalender-test PRIVATE Calender gtest_main)

add_executable(DateTimeConverter-test DateTimeConverter.test.cpp)
target_link_libraries(DateTimeConverter-test PRIVATE Calender gtest_main)

add_executable(Time-test Time.test.cpp)
target_link_libraries(Time-test PRIVATE Calender gtest_main)

include_directories("${CMAKE_SOURCE_DIR}/include" "${CMAKE_SOURCE_DIR}/src")

gtest_discover_tests(DateInfo-test)
gtest_discover_tests(Time-test)
gtest_discover_tests(WorkdayCalender-test)
gtest_discover_tests(DateTimeConverter-test)