cmake_minimum_required(VERSION 3.20)

project(LogisticRegression C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(model
    src/main.c
    src/model.c
    src/parser.c
)

target_include_directories(model PRIVATE lib)

if(NOT MSVC)
    target_link_libraries(model PRIVATE m)
endif()
