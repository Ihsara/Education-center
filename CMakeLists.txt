cmake_minimum_required(VERSION 3.10)
project(LibraryStorage)

add_library(${PROJECT_NAME}
    ${CMAKE_SOURCE_DIR}/FileOperation.cpp
)
set(CMAKE_CXX_STANDARD 14)


#Main exec
add_executable(library main.cpp)
target_link_libraries(library ${PROJECT_NAME})
