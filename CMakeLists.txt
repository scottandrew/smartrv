cmake_minimum_required(VERSION 3.0.0)
project(smartrv VERSION 0.1.0)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

if(APPLE)
  set(CMAKE_C_COMPILER clang)
  set(CMAKE_CPP_COMPILER clang)
  set(CMAKE_CXX_COMPILER clang)
  set(DRIVER -D WINDOW_DRIVER=1)
else()
  set(CMAKE_C_COMPILER gcc10.1)
  set(CMAKE_CPP_COMPILER g++10.1)
  set(DRIVER -D TOUCHDRIVER=1)
  set(EXTRALIBS -lpigpio)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR})

file(GLOB_RECURSE INCLUDES "lv_drivers/*.h" "lv_lib_png/*.h" "lvgl/*.h" "src/*.h" "lv_conf.h" "lv_drv_conf.h" "lv_ex_conf.h" "main.cpp" "mouse_cursor_icon.c")
file(GLOB_RECURSE SOURCES "lv_drivers/*.c" "lv_lib_png/*.c" "lvgl/examples/*.c"  "lvgl/src/*.c" "src/*.cpp" "src/*.c")

# Create the source groups for source tree with root at CMAKE_CURRENT_SOURCE_DIR.
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCES})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${INCLUDES})

add_definitions("-D SIMULATOR=1" ${DRIVER})
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/bin)

add_executable(${PROJECT_NAME} ${SOURCES} ${INCLUDES})
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

include(CTest)
enable_testing()

# add SDL
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# link
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARY} stdc++ ${EXTRALIBS})

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
