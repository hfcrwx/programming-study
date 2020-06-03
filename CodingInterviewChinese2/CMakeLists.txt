cmake_minimum_required(VERSION 3.16)
project(CodingInterviewChinese2)

set(CMAKE_CXX_STANDARD 11)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

add_library(base base/Array.cpp base/BinaryTree.cpp base/BinaryTreeEx.cc base/List.cpp base/StringUtil.cpp base/Tree.cpp)
include_directories(${PROJECT_SOURCE_DIR})

add_executable(01_AssignmentOperator 01_AssignmentOperator/main.cc)
add_executable(03_01_DuplicationInArray 03_01_DuplicationInArray/main.cc)
add_executable(03_02_DuplicationInArrayNoEdit 03_02_DuplicationInArrayNoEdit/main.cc)
add_executable(04_FindInPartiallySortedMatrix 04_FindInPartiallySortedMatrix/main.cc)
add_executable(05_ReplaceSpaces 05_ReplaceSpaces/main.cc)
add_executable(06_PrintListInReverseOrder 06_PrintListInReverseOrder/main.cc)
target_link_libraries(06_PrintListInReverseOrder base)
add_executable(07_ConstructBinaryTree 07_ConstructBinaryTree/main.cc)
target_link_libraries(07_ConstructBinaryTree base)
add_executable(08_NextNodeInBinaryTrees 08_NextNodeInBinaryTrees/main.cc)
target_link_libraries(08_NextNodeInBinaryTrees base)
add_executable(09_QueueWithTwoStacks 09_QueueWithTwoStacks/main.cc)
target_link_libraries(09_QueueWithTwoStacks base)