# 输出一些信息
message(STATUS "------------------------------------")
message(STATUS "---        DateTime               --")
message(STATUS "------------------------------------")


# 查找库
include_directories(main/Header)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(main/Source DIR_SRCS1)
aux_source_directory(test DIR_SRCS1)
set(SRC_LIST ${DIR_SRCS1} )
message(STATUS "当前的source文件:" ${SRC_LIST})


message(STATUS "------<拷贝文件>-------")
file(GLOB ConfigFiles resource/*.xml resource/*.ini)
MESSAGE(STATUS "config:${ConfigFiles}")

FOREACH(config ${ConfigFiles})
     message( STATUS "预拷贝--->" ${config})
     STRING( REGEX REPLACE   ".+/(.+)$" "\\1"  prjName ${config} )
     message( STATUS "文件名字--->" ${prjName})
     file(COPY ${config}  DESTINATION ${CMAKE_BINARY_DIR}/resource)
endforeach()




# 编译为中间库
ADD_EXECUTABLE(DateTimeUnit ${SRC_LIST})

# 链接为可以运行的文件
TARGET_LINK_LIBRARIES(DateTimeUnit gtest gtest_main)


