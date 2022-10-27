cmake_minimum_required(VERSION 3.1)
project(mdes)

#测试的源文件
file(GLOB MDES_CPP *.cpp)
file(GLOB MDES_HPP *.hpp)

#编译测试文件
add_executable(${PROJECT_NAME} ${MDES_CPP} ${MDES_HPP})

#链接sdyz库
target_link_libraries(${PROJECT_NAME} sdyz)
