cmake_minimum_required(VERSION 3.16)
project(TinyBar)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Network)
find_package(LayerShellQt REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(SOURCES
    src/main.cpp
    src/BarManager.cpp
    src/widgets/Clock.cpp
    src/widgets/Slider.cpp 
    src/sockets/HyprListener.cpp
)

set(HEADERS
    src/BarManager.h
    src/widgets/Clock.h
    src/widgets/Slider.h
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
