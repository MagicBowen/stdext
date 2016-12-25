
set(PROJECT_NAME "test_stdext")
set(GTEST_ROOT "/Users/wangbo/codes/googletest")

project(${PROJECT_NAME})

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include"
                    "${GTEST_ROOT}/include")
                    
link_directories("${GTEST_ROOT}/lib")

FILE(GLOB_RECURSE all_files
*.cpp
*.cc
*.c++
*.c
*.C)

add_executable(${PROJECT_NAME} ${all_files})
target_link_libraries(${PROJECT_NAME} stdext gtest)
