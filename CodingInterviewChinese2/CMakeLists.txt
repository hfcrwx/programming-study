cmake_minimum_required(VERSION 3.16)
project(CodingInterviewChinese2)

set(CMAKE_CXX_STANDARD 11)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

add_library(base base/Array.cpp base/BinaryTree.cpp base/List.cpp base/StringUtil.cpp base/Tree.cpp)
include_directories(${PROJECT_SOURCE_DIR})

add_executable(01_AssignmentOperator 01_AssignmentOperator/main.cc)
add_executable(03_01_DuplicationInArray 03_01_DuplicationInArray/main.cc)
add_executable(03_02_DuplicationInArrayNoEdit 03_02_DuplicationInArrayNoEdit/main.cc)
add_executable(04_FindInPartiallySortedMatrix 04_FindInPartiallySortedMatrix/main.cc)
add_executable(05_ReplaceSpaces 05_ReplaceSpaces/main.cc)
add_executable(06_PrintListInReverseOrder 06_PrintListInReverseOrder/main.cc)
target_link_libraries(06_PrintListInReverseOrder base)