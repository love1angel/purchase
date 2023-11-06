cmake_minimum_required(VERSION 3.26)
project(purchase)

set(CMAKE_CXX_COMPILER /opt/homebrew/bin/g++-13)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB PURCHASE_HDRS
        ${CMAKE_SOURCE_DIR}/include/purchase/*.hpp
        ${CMAKE_SOURCE_DIR}/include/purchase/*.cpp
)

file(GLOB PURCHASE_SRCS
        ${CMAKE_SOURCE_DIR}/src/*.hpp
        ${CMAKE_SOURCE_DIR}/src/*.cpp
)

set(BOOST_ROOT "/opt/homebrew/opt/")

find_package(Boost REQUIRED)

add_executable(${PROJECT_NAME}
        ${PURCHASE_HDRS}
        ${PURCHASE_SRCS}
        main.cpp
)

target_include_directories(${PROJECT_NAME}
        PUBLIC
        ${CMAKE_SOURCE_DIR}/include/
        PRIVATE
        ${Boost_INCLUDE_DIRS}
)
