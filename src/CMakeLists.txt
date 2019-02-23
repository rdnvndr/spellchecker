cmake_minimum_required(VERSION 3.10)
project(spellchecker VERSION 1.0.0)

set(PRODUCTNAME "SpellChecker Library")
set(DESCRIPTION "SpellChecker Library")
set(COMPANY     "")
set(COPYRIGHT   "")

include("${CMAKE_SOURCE_DIR}/cmake/libs.cmake")

target_compile_definitions(${PROJECT_NAME} PRIVATE -DSPELLCHECKER_LIBRARY)

find_package(Qt5Core)
target_link_libraries(${PROJECT_NAME} Qt5::Core -lhunspell)
