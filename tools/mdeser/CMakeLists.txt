cmake_minimum_required(VERSION 3.1)
project(mdeser)

#测试的源文件
file(GLOB MDESER_CPP *.cpp)

#编译测试文件
add_executable(${PROJECT_NAME} ${MDESER_CPP})

#链接sdyz库
target_link_libraries(${PROJECT_NAME} sdyz)
