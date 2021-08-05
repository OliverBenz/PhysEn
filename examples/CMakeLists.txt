if(!buildExamples)
    return()
endif()

include_directories("../src/physics")

add_executable(rocket rocket.cpp)

target_link_libraries(rocket PRIVATE physen)