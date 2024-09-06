###############################################################################
# Project setup
###############################################################################

cmake_minimum_required(VERSION 3.15)
project(minecraft_cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(MAKE_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")

###############################################################################
# Source files to build
###############################################################################

# This is near the top of the file for ease of access
# Building takes place near the bottom of the file
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(SRC_FILES
    ${SRC_DIR}/main.cpp
)

###############################################################################
# Fetch dependencies
###############################################################################

file(MAKE_DIRECTORY "${PROJECT_SOURCE_DIR}/deps")
set(FETCHCONTENT_BASE_DIR ${PROJECT_SOURCE_DIR}/deps)

# Prevent cmake from re-checking for package updates
# to help speed-up build times
set(FETCHCONTENT_UPDATES_DISCONNECTED ON)

# Let FetchContent tell the user the progress of each download
set(FETCHCONTENT_QUIET FALSE)

include(FetchContent)

# Fetch GLAD
FetchContent_Declare(
    glad
    GIT_REPOSITORY https://github.com/gequalspisquared/glad_gl_core_460
    GIT_TAG        main
    GIT_PROGRESS   TRUE
)

FetchContent_MakeAvailable(glad)

# Fetch GLFW
FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw
    GIT_TAG        3.3-stable
    GIT_PROGRESS   TRUE
)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(glfw)

# Fetch GLM
FetchContent_Declare(
    glm
    GIT_REPOSITORY https://github.com/g-truc/glm
    GIT_TAG        1.0.1
    GIT_PROGRESS   TRUE
)

FetchContent_MakeAvailable(glm)

# Fetch stb
FetchContent_Declare(
    stb
    GIT_REPOSITORY https://github.com/nothings/stb
    GIT_TAG        master
    GIT_PROGRESS   TRUE
)

FetchContent_MakeAvailable(stb)

###############################################################################
# Build
###############################################################################

add_executable(minecraft_cpp "${SRC_FILES}")

target_include_directories(minecraft_cpp PUBLIC "${SRC_DIR}")
target_include_directories(minecraft_cpp PUBLIC "${stb_SOURCE_DIR}")
target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC RESOURCES_PATH="${CMAKE_CURRENT_SOURCE_DIR}/res/")

# Don't include stb as it is just an interface
target_link_libraries("${CMAKE_PROJECT_NAME}" PRIVATE glfw glad glm)
