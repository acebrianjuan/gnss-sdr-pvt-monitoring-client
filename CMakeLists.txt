cmake_minimum_required (VERSION 2.8)
project (gnss-sdr-pvt-monitoring-client CXX C)

set (CMAKE_CXX_STANDARD 11)

set(Boost_USE_STATIC_LIBS OFF)
find_package(Boost COMPONENTS system serialization REQUIRED)
if(NOT Boost_FOUND)
     message(FATAL_ERROR "Fatal error: Boost required.")
endif(NOT Boost_FOUND)

set (CURSES_NEED_NCURSES TRUE)
find_package(Curses REQUIRED)
if(NOT CURSES_FOUND)
     message(FATAL_ERROR "Fatal error: NCurses required.")
endif(NOT CURSES_FOUND)

include_directories(
        ${CMAKE_SOURCE_DIR}
        ${Boost_INCLUDE_DIRS}
        ${CURSES_INCLUDE_DIRS}
     )

add_library(monitoring_lib ${CMAKE_SOURCE_DIR}/monitor_pvt_udp_source.cc)

ADD_EXECUTABLE(gnss-sdr-pvt-monitoring-client ${CMAKE_SOURCE_DIR}/main.cc)
target_link_libraries(gnss-sdr-pvt-monitoring-client monitoring_lib pthread ${Boost_LIBRARIES})
target_link_libraries(gnss-sdr-pvt-monitoring-client monitoring_lib pthread ${CURSES_LIBRARIES})
