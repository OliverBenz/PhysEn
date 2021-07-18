include_directories("../src/Physics")

add_executable(rocket Rocket.cpp)

target_link_libraries(rocket PUBLIC Physics Maths)