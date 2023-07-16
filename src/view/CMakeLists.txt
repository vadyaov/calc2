cmake_minimum_required(VERSION 3.5)

project(SmartCalc_v2 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

# set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
# find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
find_package(Qt6 CONFIG REQUIRED COMPONENTS Widgets PrintSupport)

add_compile_options(-Wall -Werror -Wextra -Wpedantic)
add_compile_options(-fsanitize=address)
add_link_options(-fsanitize=address)

set(PROJECT_INCLUDES
  includes/smartcalc.h
  includes/creditcalc.h
  includes/depositcalc.h
  includes/button.h
)

set(PROJECT_SOURCES
        ../model/sources/deposit.cc
        ../model/sources/credit.cc
        ../model/sources/calcul.cc
        ../controller/controller.cc

        main.cc
        sources/smartcalc.cc
        sources/creditcalc.cc
        sources/depositcalc.cc
        qcustomplot/qcustomplot.cpp
        sources/button.cc
)

add_executable(smartcalc
        # MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        ${PROJECT_INCLUDES}
)

target_link_libraries(smartcalc Qt6::Widgets Qt6::PrintSupport)

# if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
#   qt_add_executable(SmartCalc_v2
#         MANUAL_FINALIZATION
#         ${PROJECT_SOURCES}
#     )
# # Define target properties for Android with Qt 6 as:
# #    set_property(TARGET calctest APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
# #                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# # For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
# else()
#     if(ANDROID)
#         add_library(SmartCalc_v2 SHARED
#             ${PROJECT_SOURCES}
#         )
# # Define properties for Android with Qt 5 after find_package() calls as:
# #    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#     else()
#         add_executable(SmartCalc_v2
#             ${PROJECT_SOURCES}
#         )
#     endif()
# endif()

# target_link_libraries(SmartCalc_v2 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# set_target_properties(SmartCalc_v2 PROPERTIES
#     MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
#     MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
#     MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
#     MACOSX_BUNDLE TRUE
#     WIN32_EXECUTABLE TRUE
# )

# if(QT_VERSION_MAJOR EQUAL 6)
#     qt_finalize_executable(SmartCalc_v2)
# endif()
