cmake_minimum_required(VERSION 3.26)
project(purchase)

set(CMAKE_CXX_STANDARD 17)

file(GLOB PURCHASE_HDRS
        ${CMAKE_SOURCE_DIR}/include/purchase/*.hpp
        ${CMAKE_SOURCE_DIR}/include/purchase/*.cpp
)

file(GLOB PURCHASE_SRCS
        ${CMAKE_SOURCE_DIR}/src/*.hpp
        ${CMAKE_SOURCE_DIR}/src/*.cpp
)

add_executable(${PROJECT_NAME}
        ${PURCHASE_HDRS}
        ${PURCHASE_SRCS}
        main.cpp
)

target_include_directories(${PROJECT_NAME}
        PUBLIC
            ${CMAKE_SOURCE_DIR}/include/
)

