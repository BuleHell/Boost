cmake_minimum_required(VERSION 3.11.2)
project(boost)
message(STATUS "------------------------------------")
message(STATUS "---   Coding Everything!          --")
message(STATUS "------------------------------------")

set(CMAKE_CXX_STANDARD 11)


### 添加include文件[是指去这些目录去找]
include_directories(${PROJECT_SOURCE_DIR}/include)

### 添加lib文件
MESSAGE(STATUS "请编译相应的文件lib")

IF (WIN32)
    MESSAGE(STATUS "当前系统是：windows")
    LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/lib/win/gtest)
    LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/lib/win/boost)
ELSEIF (APPLE)
    MESSAGE(STATUS "当前系统是：Apple Mac")
    LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/lib/mac/gtest)
    LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/lib/mac/boost)
ELSEIF (UNIX)
    LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/lib/linux/gtest)
    LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/lib/linux/boost)
    MESSAGE(STATUS "当前系统是：UNIX-like OS's. Including aPPLE os x  and CygWin")
ENDIF ()


SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH    ${PROJECT_BINARY_DIR}/lib)


# 直接把相应的子目录加进来就行了
add_subdirectory(src/PropertyTree)
add_subdirectory(src/StandardLibrary)
