cmake_minimum_required(VERSION 3.16)
project(wxWTutorial LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Your sources
file(GLOB WXWTUTORIAL_SOURCES CONFIGURE_DEPENDS TutorialProject/src/*.cpp)

# ========== wxWidgets ==========
# Build the local wxWidgets copy
add_subdirectory(extern/wxWidgets EXCLUDE_FROM_ALL)

# Where executables should be placed
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Where libraries should be placed (if you ever build any)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# ========== Your executable ==========
add_executable(wxWTutorial ${WXWTUTORIAL_SOURCES})

if(WIN32)
    add_custom_command(TARGET wxWTutorial POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_BINARY_DIR}/extern/wxWidgets/lib/gcc_x64_dll
        $<TARGET_FILE_DIR:wxWTutorial>
    )
endif()

target_link_libraries(wxWTutorial PRIVATE
    wx::core
    wx::base
)

target_include_directories(wxWTutorial PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/extern/wxWidgets/include
    ${CMAKE_CURRENT_SOURCE_DIR}/TutorialProject/include
)

