cmake_minimum_required(VERSION 3.0.0)
project(Find_the_intersection VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

include(CTest)
enable_testing()

find_package(Boost 1.72.0)

set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

aux_source_directory(./src srcs)

add_executable(${PROJECT_NAME} ${srcs})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

if(Boost_FOUND)
    target_link_libraries(${PROJECT_NAME} PRIVATE ${Boost_LIBRARIES})
endif()

target_include_directories(${PROJECT_NAME} PUBLIC ${MY_INCLUDE_DIR})

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif()