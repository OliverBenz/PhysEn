# ----- Helper Functions -----
function(copy_headers_to_output targetName headerFiles)
    foreach(filePath ${headerFiles})
        get_filename_component(fileName ${filePath} NAME)

        add_custom_command(TARGET ${targetName} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_if_different ${filePath} "${CMAKE_BINARY_DIR}/out/include/physen/${fileName}"
                )
    endforeach()
endfunction()