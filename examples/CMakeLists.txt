add_compile_options(-Wall -Wextra -Wpedantic)

add_executable(WorkdayCalender-app main.cpp)
target_link_libraries(WorkdayCalender-app PRIVATE Calender)