cmake_minimum_required(VERSION 2.8.4)
project(Test)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O3")

set(SOURCE_FILES t.cc)
add_executable(Test ${SOURCE_FILES})

add_executable(CacheRandoms fileTest.cc)