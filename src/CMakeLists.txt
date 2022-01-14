add_compile_options(-Wall -Wextra -Wpedantic)

add_library(Calender Date.cpp DateTimeConverter.cpp Time.cpp WorkdayCalender.cpp)
target_include_directories(Calender PUBLIC "${CMAKE_SOURCE_DIR}/include" "${CMAKE_CURRENT_SOURCE_DIR}")

add_executable(Calender-app main.cpp)
target_link_libraries(Calender-app PRIVATE Calender)