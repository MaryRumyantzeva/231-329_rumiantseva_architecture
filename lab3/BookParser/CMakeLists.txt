cmake_minimum_required(VERSION 3.14)

project(BookParser LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Ищем необходимые компоненты Qt
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets Network)

# Создание исполняемого файла
add_executable(BookParser
  main.cpp
  mainwindow.cpp
  mainwindow.h
  networkmanager.cpp
  networkmanager.h
  book.h

  networkmanageradapter.h
  inetworkadapter.h
)

# Линковка с необходимыми библиотеками
target_link_libraries(
    BookParser
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Network
    Qt${QT_VERSION_MAJOR}::Widgets
)

include(GNUInstallDirs)
install(TARGETS BookParser
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION
)

