cmake_minimum_required(VERSION 3.16)

project(example-qtgllogger LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(example-qtgllogger
  main.cpp
)
target_link_libraries(example-qtgllogger PUBLIC Qt${QT_VERSION_MAJOR}::Core)

include(GNUInstallDirs)
install(TARGETS example-qtgllogger
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)


# =============================================
set(library_name "qtgllogger")
if (WIN32)
    set(${library_name}_include ${CMAKE_CURRENT_SOURCE_DIR}/../${library_name}/output/include)
    include_directories(${${library_name}_include})
    set(${library_name}_platform "win32msvc")
    set(${library_name}_lib_dir ${CMAKE_CURRENT_SOURCE_DIR}/../${library_name}/output/lib/${${library_name}_platform}/${library_name})
    set(${library_name}_lib1 ${${library_name}_lib_dir}/${library_name}.lib)
    target_link_directories(${PROJECT_NAME} PUBLIC ${${library_name}_lib_dir})
    target_link_libraries(${PROJECT_NAME} PUBLIC ${${library_name}_lib1})
elseif (UNIX AND NOT APPLE AND NOT WIN32 AND NOT ANDROID)
    set(${library_name}_include ${CMAKE_CURRENT_SOURCE_DIR}/../${library_name}/output/include)
    include_directories(${${library_name}_include})
    set(${library_name}_platform "linux64")
    set(${library_name}_lib_dir ${CMAKE_CURRENT_SOURCE_DIR}/../${library_name}/output/lib/${${library_name}_platform}/${library_name})
    set(${library_name}_lib1 ${${library_name}_lib_dir}/lib${library_name}.so)
    target_link_directories(${PROJECT_NAME} PUBLIC ${${library_name}_lib_dir})
    target_link_libraries(${PROJECT_NAME} PUBLIC ${${library_name}_lib1})
endif()
# =============================================




