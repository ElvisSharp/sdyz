cmake_minimum_required(VERSION 3.1)
project(sdyz VERSION 4.0.4)

#       Vesion                  Description
#       v4.0.1                  1.更新CMakeLists.txt，对源文件进行分类；2.修改部分注释；3.修改basekey为nonce
#       v4.0.2                  1.更新CMakeLists.txt，对头文件进行分类
#       v4.0.3                  1.新增编码转换encoding
#       v4.0.4                  1.修改进度条progress_bar为单线程的模式

set(CMAKE_CXX_STANDARD 11)

set(GCC_OR_CLANG ((CMAKE_CXX_COMPILER_ID MATCHES "Clang") OR CMAKE_COMPILER_IS_GNUCXX))

# 对于MSVC需要支持utf-8
if(MSVC_VERSION)
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /utf-8")
    set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /utf-8")
endif(MSVC_VERSION)

# 更换生成目录
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 源文件以及头文件的目录
set(SDYZ_SOURCE_PATH "${PROJECT_SOURCE_DIR}/src")
set(SDYZ_INCLUDE_PATH "${PROJECT_SOURCE_DIR}/include")

# 设定包含的目录
include_directories(${SDYZ_INCLUDE_PATH})

#加入头文件
file(GLOB SDYZ_ALGORITHM_CRYPTOGRAPHY_AES_HPP ${SDYZ_INCLUDE_PATH}/sdyz/algorithm/cryptography/aes/*.hpp)
file(GLOB SDYZ_ALGORITHM_CRYPTOGRAPHY_DES_HPP ${SDYZ_INCLUDE_PATH}/sdyz/algorithm/cryptography/des/*.hpp)
file(GLOB SDYZ_CAST_HPP ${SDYZ_INCLUDE_PATH}/sdyz/cast/*.hpp)
file(GLOB SDYZ_ARG_PARSER_HPP ${SDYZ_INCLUDE_PATH}/sdyz/arg_parser/*.hpp)
file(GLOB SDYZ_CRYPTER_HPP ${SDYZ_INCLUDE_PATH}/sdyz/crypter/*.hpp)
file(GLOB SDYZ_EXCEPTION_HPP ${SDYZ_INCLUDE_PATH}/sdyz/exception/*.hpp)
file(GLOB SDYZ_PLUS_HPP ${SDYZ_INCLUDE_PATH}/sdyz/plus/*.hpp)
file(GLOB SDYZ_CONSOLE_HPP ${SDYZ_INCLUDE_PATH}/sdyz/console/*.hpp)
file(GLOB SDYZ_TOOLS_HPP ${SDYZ_INCLUDE_PATH}/sdyz/tools/*.hpp)
file(GLOB SDYZ_VECTOR_HPP ${SDYZ_INCLUDE_PATH}/sdyz/vector/*.hpp)
file(GLOB SDYZ_ALGORITHM_HASH_HPP ${SDYZ_INCLUDE_PATH}/sdyz/algorithm/hash/*.hpp)

# 分组头文件
source_group("include\\algorithm\\cryptography\\aes" FILES ${SDYZ_ALGORITHM_CRYPTOGRAPHY_AES_HPP})
source_group("include\\algorithm\\cryptography\\des" FILES ${SDYZ_ALGORITHM_CRYPTOGRAPHY_DES_HPP})
source_group("include\\cast" FILES ${SDYZ_CAST_HPP})
source_group("include\\arg_parser" FILES ${SDYZ_ARG_PARSER_HPP})
source_group("include\\crypter" FILES ${SDYZ_CRYPTER_HPP})
source_group("include\\exception" FILES ${SDYZ_EXCEPTION_HPP})
source_group("include\\plus" FILES ${SDYZ_PLUS_HPP})
source_group("include\\console" FILES ${SDYZ_CONSOLE_HPP})
source_group("include\\tools" FILES ${SDYZ_TOOLS_HPP})
source_group("include\\vector" FILES ${SDYZ_VECTOR_HPP})
source_group("include\\algorithm\\hash" FILES ${SDYZ_ALGORITHM_HASH_HPP})

# 加入源文件
file(GLOB SDYZ_ALGORITHM_CRYPTOGRAPHY_AES_CPP ${SDYZ_SOURCE_PATH}/algorithm/cryptography/aes/*.cpp)
file(GLOB SDYZ_ALGORITHM_CRYPTOGRAPHY_DES_CPP ${SDYZ_SOURCE_PATH}/algorithm/cryptography/des/*.cpp)
file(GLOB SDYZ_ARG_PARSER_CPP ${SDYZ_SOURCE_PATH}/arg_parser/*.cpp)
file(GLOB SDYZ_CRYPTER_CPP ${SDYZ_SOURCE_PATH}/crypter/*.cpp)
file(GLOB SDYZ_EXCEPTION_CPP ${SDYZ_SOURCE_PATH}/exception/*.cpp)
file(GLOB SDYZ_PLUS_CPP ${SDYZ_SOURCE_PATH}/plus/*.cpp)
file(GLOB SDYZ_CONSOLE_CPP ${SDYZ_SOURCE_PATH}/console/*.cpp)
file(GLOB SDYZ_TOOLS_CPP ${SDYZ_SOURCE_PATH}/tools/*.cpp)
file(GLOB SDYZ_VECTOR_CPP ${SDYZ_SOURCE_PATH}/vector/*.cpp)
file(GLOB SDYZ_ALGORITHM_HASH_CPP ${SDYZ_SOURCE_PATH}/algorithm/hash/*.cpp)

# 分组源文件
source_group("src\\algorithm\\cryptography\\aes" FILES ${SDYZ_ALGORITHM_CRYPTOGRAPHY_AES_CPP})
source_group("src\\algorithm\\cryptography\\des" FILES ${SDYZ_ALGORITHM_CRYPTOGRAPHY_DES_CPP})
source_group("src\\arg_parser" FILES ${SDYZ_ARG_PARSER_CPP})
source_group("src\\crypter" FILES ${SDYZ_CRYPTER_CPP})
source_group("src\\exception" FILES ${SDYZ_EXCEPTION_CPP})
source_group("src\\plus" FILES ${SDYZ_PLUS_CPP})
source_group("src\\console" FILES ${SDYZ_CONSOLE_CPP})
source_group("src\\tools" FILES ${SDYZ_TOOLS_CPP})
source_group("src\\vector" FILES ${SDYZ_VECTOR_CPP})
source_group("src\\algorithm\\hash" FILES ${SDYZ_ALGORITHM_HASH_CPP})

# 导出的类
add_library(
    ${PROJECT_NAME} 
    # 加入头文件
    ${SDYZ_ALGORITHM_CRYPTOGRAPHY_AES_HPP}
    ${SDYZ_ALGORITHM_CRYPTOGRAPHY_DES_HPP}
    ${SDYZ_CAST_HPP}
    ${SDYZ_ARG_PARSER_HPP}
    ${SDYZ_CRYPTER_HPP}
    ${SDYZ_EXCEPTION_HPP}
    ${SDYZ_PLUS_HPP}
    ${SDYZ_CONSOLE_HPP}
    ${SDYZ_TOOLS_HPP}
    ${SDYZ_VECTOR_HPP}
    ${SDYZ_ALGORITHM_HASH_HPP}
    # 加入源文件
    ${SDYZ_ALGORITHM_CRYPTOGRAPHY_AES_CPP} 
    ${SDYZ_ALGORITHM_CRYPTOGRAPHY_DES_CPP} 
    ${SDYZ_ARG_PARSER_CPP}
    ${SDYZ_CRYPTER_CPP}
    ${SDYZ_EXCEPTION_CPP}
    ${SDYZ_PLUS_CPP}
    ${SDYZ_CONSOLE_CPP}
    ${SDYZ_TOOLS_CPP}
    ${SDYZ_VECTOR_CPP}
    ${SDYZ_ALGORITHM_HASH_CPP}
)

#需要编译的测试项目
#test_arg_parser
option(TEST_ARG_PARSER "Compile test_arg_parser" OFF)
if(TEST_ARG_PARSER)
    add_subdirectory(tests/arg_parser)
endif(TEST_ARG_PARSER)

#test_cast
option(TEST_CAST "Compile test_cast" OFF)
if(TEST_CAST)
    add_subdirectory(tests/cast)
endif(TEST_CAST)

#test_console
option(TEST_CONSOLE "Compile test_console" OFF)
if(TEST_CONSOLE)
    add_subdirectory(tests/console)
endif(TEST_CONSOLE)

#test_exception
option(TEST_EXCEPTION "Compile test_exception" OFF)
if(TEST_EXCEPTION)
    add_subdirectory(tests/exception)
endif(TEST_EXCEPTION)

#test_hash
option(TEST_HASH "Compile test_hash" OFF)
if(TEST_HASH)
    add_subdirectory(tests/hash)
endif(TEST_HASH)

#test_plus
option(TEST_PLUS "Compile test_plus" OFF)
if(TEST_PLUS)
    add_subdirectory(tests/plus)
endif(TEST_PLUS)

#test_tools
option(TEST_TOOLS "Compile test_tools" OFF)
if(TEST_TOOLS)
    add_subdirectory(tests/tools)
endif(TEST_TOOLS)

#test_vector
option(TEST_VECTOR "Compile test_vector" OFF)
if(TEST_VECTOR)
    add_subdirectory(tests/vector)
endif(TEST_VECTOR)

#需要编译的子项目
#mcaeser
option(MCAESER "Compile mcaeser" ON)
if(MCAESER)
    add_subdirectory(tools/mcaeser)
endif(MCAESER)

#maeser
option(MAESER "Compile maeser" ON)
if(MAESER)
    add_subdirectory(tools/maeser)
endif(MAESER)

#mdeser
option(MDESER "Compile mdeser" ON)
if(MDESER)
    add_subdirectory(tools/mdeser)
endif(MDESER)
