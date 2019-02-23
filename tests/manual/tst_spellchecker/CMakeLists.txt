cmake_minimum_required(VERSION 3.10)
project(tst_spellchecker_mnl VERSION 1.0.0)

set(PRODUCTNAME "")
set(DESCRIPTION "")
set(COMPANY     "")
set(COPYRIGHT   "")
set(LIBRARIES
    spellchecker
)

include(../manual.cmake)

find_package(Qt5Core)
target_link_libraries(${PROJECT_NAME} Qt5::Core)
