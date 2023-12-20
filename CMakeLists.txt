cmake_minimum_required(VERSION 3.18)
project(RaspClock)

set(CMAKE_CXX_STANDARD 20)

include(${CMAKE_SOURCE_DIR}/ext/CMakeLists.txt)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

set(UIS
    ${CMAKE_SOURCE_DIR}/ui/mainwindow.ui
    ${CMAKE_SOURCE_DIR}/ui/clock.ui)

QT5_WRAP_UI(UI_HEADERS ${UIS})

add_executable(RaspClock
    ${UI_HEADERS}
    src/main.cpp
    src/ui/mainwindow.cpp
    src/ui/mainwindow.hpp
    src/ui/mainwindow.ui
    src/ui/clock.cpp
    src/ui/clock.hpp
    src/ui/clock.ui
        src/ui/settings.cpp
        src/ui/settings.hpp
        src/ui/settings.ui
        src/widgets/SwitchButton.cpp
        src/widgets/SwitchButton.hpp)

target_compile_features(${CMAKE_PROJECT_NAME} PRIVATE cxx_std_20)

target_link_libraries(RaspClock
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
    fmt::fmt
    pthread)

if (${CMAKE_BUILD_TYPE} MATCHES "Debug")
    target_compile_definitions(RaspClock PRIVATE DEBUG)
endif()