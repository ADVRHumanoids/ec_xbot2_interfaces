cmake_minimum_required(VERSION 3.16)
project(ec_xbot2_interfaces VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 20)

include(cmake/ExportProject.cmake)

# find dependencies
find_package(xbot2 REQUIRED)


# add main target
add_library(ec_xbot2_interfaces
    INTERFACE
)

target_include_directories(ec_xbot2_interfaces
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include/${PROJECT_NAME}>
)

target_link_libraries(ec_xbot2_interfaces
    INTERFACE
    xbot2::xbot2
)


# a dummy target, just to make sure headers do compile
add_library(dummy STATIC src/dummy.cpp)

target_link_libraries(dummy ec_xbot2_interfaces)


# install and export
install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/
    DESTINATION include/${PROJECT_NAME}
    FILES_MATCHING PATTERN "*.h*"
)

install(TARGETS ec_xbot2_interfaces
    EXPORT ${PROJECT_NAME}Targets
)

export_project()
