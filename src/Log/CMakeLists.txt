# 输出一些信息
message(STATUS "------------------------------------")
message(STATUS "---   LogLibrary                --")
message(STATUS "------------------------------------")


# 查找库
include_directories(main/Header)
#include_directories(${PROJECT_SOURCE_DIR}/include)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(main/Source DIR_SRCS1)
aux_source_directory(test DIR_SRCS1)
set(SRC_LIST ${DIR_SRCS1} )
message(STATUS "当前的source文件:" ${SRC_LIST})

###########################################################
##  我们暂且不用静态库
#############################################################
# 将生成的形成一个lib
# 动态库
#ADD_LIBRARY(property SHARED ${SRC_LIST})

# static library
# 静态库
#ADD_LIBRARY(property_static STATIC ${SRC_LIST})
#SET_TARGET_PROPERTIES(property_static PROPERTIES OUTPUT_NAME "property")
#
#SET_TARGET_PROPERTIES(property        PROPERTIES CLEAN_DIRECT_OUTPUT 1)
#SET_TARGET_PROPERTIES(property_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)
#############################################################
## 直接生成运行文件，运行对应的信息即可
#link_directories(${PROJECT_SOURCE_DIR}/lib/mac/gtest)
#link_directories(${PROJECT_SOURCE_DIR}/lib/mac/boost)
#
#link_libraries(gtest)
#link_libraries(gtest_main)



file(GLOB ConfigFiles resource/*.xml resource/*.ini)
MESSAGE(STATUS "config:${ConfigFiles}")

FOREACH(config ${ConfigFiles})
    message( STATUS "--->" ${config})
    STRING( REGEX REPLACE   ".+/(.+)$" "\\1"  prjName ${config} )
    message( STATUS "22--->" ${prjName})
    message( STATUS "start --->" ${config})
    #     configure_file(${config} ${CMAKE_BINARY_DIR}/resource/${prjName})

    file(COPY ${config}  DESTINATION ${CMAKE_BINARY_DIR}/resource)
    #     add_custom_command(OUTPUT copy  COMMAND ${CMAKE_COMMAND} -E copy_directory  resource  ${EXECUTABLE_OUTPUT_PATH}/resource)


endforeach()

#add_custom_target(copy)
#foreach(ConfigFile ${ConfigFiles})
#    add_custom_command(TARGET copy PRE_BUILD
#            COMMAND ${CMAKE_COMMAND} -E
#            copy ${ConfigFile} ${PROJECT_BINARY_DIR})
#endforeach()


ADD_EXECUTABLE(LogUnit ${SRC_LIST})
TARGET_LINK_LIBRARIES(LogUnit gtest gtest_main)


