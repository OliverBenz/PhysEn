# Add all example projects
set(listOfExamples rocket)

add_executable(rocket rocket/rocket.cpp)  # Example: Rocket


# Add general settings to every example
foreach(targetName ${listOfExamples})
	target_link_libraries(${targetName} PRIVATE physen)                                   # Link physen library
	target_include_directories(${targetName} PRIVATE "${CMAKE_BINARY_DIR}/out/include/")  # Reference header files
	set_target_properties(${targetName} PROPERTIES FOLDER "${ideFolderExamples}")         # Add to IDE folder "Examples"
endforeach()