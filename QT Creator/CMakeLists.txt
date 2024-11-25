cmake_minimum_required(VERSION 3.16)

project(LR3_Ilichev VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)            # Установите стандарт C++20
set(CMAKE_CXX_STANDARD_REQUIRED ON)   # Обязательный стандарт
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
    Main.cpp
        MainWindowIlichev.cpp
        MainWindowIlichev.h
        MainWindowIlichev.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(LR3_Ilichev
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        Serialize.h
        Sportsman.h
        Footballer.h
        SportsmansGroup.h
        SportsmanWidget.cpp SportsmanWidget.h
        SportsmansGroup.cpp
        Sportsman.cpp
        Footballer.cpp
        Addition.h
        Addition.cpp
        DialogIlichev.h DialogIlichev.cpp DialogIlichev.ui
        AddDialog.h AddDialog.cpp AddDialog.ui
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET LR3_Ilichev APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(LR3_Ilichev SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(LR3_Ilichev
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(LR3_Ilichev PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.LR3_Ilichev)
endif()
set_target_properties(LR3_Ilichev PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS LR3_Ilichev
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(LR3_Ilichev)
endif()


set(BOOST_ROOT "C:/QT/boost_1_86_0")
find_package(Boost 1.86 REQUIRED COMPONENTS serialization)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    link_directories(${Boost_LIBRARY_DIRS})
    target_link_libraries(LR3_Ilichev PRIVATE ${Boost_LIBRARIES})
endif()

set(CMAKE_SOURCE_FILE_ENCODING "UTF-8")
