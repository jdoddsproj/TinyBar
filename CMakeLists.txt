cmake_minimum_required(VERSION 3.16)
project(TinyBar)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Network)
find_package(LayerShellQt 6.5.0 REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(SOURCES
    src/main.cpp
    src/Taskbar.cpp
    src/widgets/Clock.cpp
    src/sockets/HyprListener.cpp
)

set(HEADERS
    src/Taskbar.h
    src/widgets/Clock.h
    src/sockets/HyprListener.h
)

add_executable(TinyBar 
    ${SOURCES}
    ${HEADERS}
)

target_link_libraries(TinyBar
    PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::Network
    LayerShellQt::Interface
)
