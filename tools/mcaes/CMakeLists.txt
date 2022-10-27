cmake_minimum_required(VERSION 3.1)
project(mcaes)

#测试的源文件
file(GLOB MCAES_CPP *.cpp)
file(GLOB MCAES_HPP *.hpp)

#编译测试文件
add_executable(${PROJECT_NAME} ${MCAES_CPP} ${MCAES_HPP})

#链接sdyz库
target_link_libraries(${PROJECT_NAME} sdyz)
