cmake_minimum_required(VERSION 2.8)
project(async-api C)

set(CMAKE_C_STANDARD 99)

include_directories(/usr/include/mysql)
link_directories(/usr/lib64/mysql)

add_executable(async_example async_example.c)
target_link_libraries(async_example mysqlclient)

add_executable(async_queries async_queries.c)
target_link_libraries(async_queries mysqlclient  event)
