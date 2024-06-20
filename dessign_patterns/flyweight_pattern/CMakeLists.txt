cmake_minimum_required(VERSION 2.8)
#工程名
project(flyweightPattern)
#包含原程序,即把给定目录下的源程序复制给变量DIR_SRC
#将指定路径下的源文件储存在指定的变量中
aux_source_directory(./ DIR_SRC )
#生成程序
add_executable(flyweightPattern  ${DIR_SRC})