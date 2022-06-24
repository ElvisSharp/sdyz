cmake_minimum_required(VERSION 3.1)
project(sdyz VERSION 4.0.0)

set(CMAKE_CXX_STANDARD 11)

set(GCC_OR_CLANG ((CMAKE_CXX_COMPILER_ID MATCHES "Clang") OR CMAKE_COMPILER_IS_GNUCXX))

#更换生成目录
set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)

#对于MSVC需要支持utf-8
if(MSVC_VERSION)
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /utf-8")
    set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /utf-8")
endif(MSVC_VERSION)

#包含的目录
include_directories("${PROJECT_SOURCE_DIR}/include")

#加入源文件
file(GLOB SDYZ_AES_CPP src/aes/*.cpp)
file(GLOB SDYZ_DES_CPP src/des/*.cpp)
file(GLOB SDYZ_ARG_PARSER_CPP src/arg_parser/*.cpp)
file(GLOB SDYZ_EXCEPTION_CPP src/exception/*.cpp)
file(GLOB SDYZ_PLUS_CPP src/plus/*.cpp)
file(GLOB SDYZ_CONSOLE_CPP src/console/*.cpp)
file(GLOB SDYZ_TOOLS_CPP src/tools/*.cpp)
file(GLOB SDYZ_VECTOR_CPP src/vector/*.cpp)
file(GLOB SDYZ_HASH_CPP src/hash/*.cpp)

#导出的类
add_library(
    ${PROJECT_NAME} 
    ${SDYZ_AES_CPP} 
    ${SDYZ_DES_CPP} 
    ${SDYZ_ARG_PARSER_CPP} 
    ${SDYZ_EXCEPTION_CPP}
    ${SDYZ_PLUS_CPP}
    ${SDYZ_CONSOLE_CPP}
    ${SDYZ_TOOLS_CPP}
    ${SDYZ_VECTOR_CPP}
    ${SDYZ_HASH_CPP}
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
#maes
option(MAES "Compile maes" ON)
if(MAES)
    add_subdirectory(tools/maes)
endif(MAES)

#mdes
option(MDES "Compile mdes" ON)
if(MDES)
    add_subdirectory(tools/mdes)
endif(MDES)
