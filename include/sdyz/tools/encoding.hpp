/*********************************************************
*"encoding"用于处理字符串编码
*作者：三点一洲
* Copyright (c) 三点一洲工作室
***********************************************************/
#pragma once
#include <string>

namespace sdyz
{
#ifdef _WIN32
#include <windows.h>
    // GBK编码转UTF-8
    std::string gbk_to_utf8(const char* _Src_Str);

    // UTF-8编码转GBK
    std::string utf8_to_gbk(const char* _Src_Str);
    
#else
#include <iconv.h>
    // GBK编码转UTF-8
    int gbk_to_utf8(char* str_str, size_t src_len, char* dst_str, size_t dst_len);
    
    // UTF-8编码转GBK
    int utf8_to_gbk(char* src_str, size_t src_len, char* dst_str, size_t dst_len);
   
#endif
};