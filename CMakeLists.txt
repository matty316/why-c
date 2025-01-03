cmake_minimum_required(VERSION 3.31)

project(why)

set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES "${CMAKE_SOURCE_DIR}/src/*.c")
file(GLOB TEST "${CMAKE_SOURCE_DIR}/tests/*.cc")

file(GLOB INCLUDES "${CMAKE_SOURCE_DIR}/include/*.h")
add_executable(why ${SOURCES} ${INCLUDES})

include_directories(${CMAKE_SOURCE_DIR}/include)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

list(REMOVE_ITEM SOURCES "${CMAKE_SOURCE_DIR}/src/main.c")

add_executable(tests ${TEST} ${INCLUDES} ${SOURCES})

enable_testing()

target_link_libraries(tests GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(tests)
