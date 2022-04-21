if(NOT BUILD_EXAMPLES)
    return()
endif()

include_directories("../src/physics")

set(listOfExamples rocket)

# Example: Rocket
add_executable(rocket rocket/rocket.cpp)


# Add library and IDE folder structur to every example
foreach(targetName ${listOfExamples})
	target_link_libraries(${targetName} PRIVATE physen)                # Link physen library
	set_target_properties(${targetName} PROPERTIES FOLDER "Examples")  # Add to IDE folder "Examples"
endforeach()