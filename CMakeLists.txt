cmake_minimum_required(VERSION 2.8.12)

project(qt5OpenGL)

# Qt library
find_package(Qt5Widgets)
find_package(Qt5OpenGL)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# OpenGL & GLEW library
find_package(OpenGL REQUIRED)

FILE(GLOB_RECURSE sources ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cc)
FILE(GLOB_RECURSE includes ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# executable
add_executable(qt5OpenGL ${sources} ${includes})
qt5_use_modules(qt5OpenGL Widgets OpenGL)
target_link_libraries(qt5OpenGL ${QT_LIBRARIES} ${OPENGL_LIBRARIES})
