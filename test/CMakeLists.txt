cmake_minimum_required(VERSION 2.8)
#工程名
project(HELLOWORLD)
#包含原程序,即把给定目录下的源程序复制给变量DIR_SRC
#将指定路径下的源文件储存在指定的变量中
#下面这句话，有些博客中写错了，需要注意
aux_source_directory(./ DIR_SRC )
#生成程序
add_executable(HELLOWORLD  ${DIR_SRC})