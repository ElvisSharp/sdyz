#pragma once
#include <sdyz/exception/base_exception.hpp>

class Different_ByteVector_Size : public sdyz::base_exception
{
public:
#define SDYZ_DIFFERENT_BYTEVECTOR_SIZE_CODE 2010
#define SDYZ_DIFFERENT_BYTEVECTOR_SIZE_MESSAGE "字节数组长度不一致"

    Different_ByteVector_Size() : base_exception(SDYZ_DIFFERENT_BYTEVECTOR_SIZE_CODE, SDYZ_DIFFERENT_BYTEVECTOR_SIZE_MESSAGE)
    {
    }

    Different_ByteVector_Size (const char* _Position) : base_exception(SDYZ_DIFFERENT_BYTEVECTOR_SIZE_CODE, SDYZ_DIFFERENT_BYTEVECTOR_SIZE_MESSAGE, _Position)
    {
    }

    ~Different_ByteVector_Size()
    {
    }

};

class Invalid_Hex_String : public sdyz::base_exception
{
public:
#define SDYZ_INVALID_HEX_STRING_CODE 2011
#define SDYZ_INVALID_HEX_STRING_MESSAGE "不合法的十六进制字符串"

    Invalid_Hex_String() : base_exception(SDYZ_INVALID_HEX_STRING_CODE, SDYZ_INVALID_HEX_STRING_MESSAGE)
    {
    }

    Invalid_Hex_String (const char* _Position) : base_exception(SDYZ_INVALID_HEX_STRING_CODE, SDYZ_INVALID_HEX_STRING_MESSAGE, _Position)
    {
    }

    ~Invalid_Hex_String()
    {
    }

};

class Invalid_Bin_String : public sdyz::base_exception
{
public:
#define SDYZ_INVALID_BIN_STRING_CODE 2012
#define SDYZ_INVALID_BIN_STRING_MESSAGE "不合法的二进制字符串"

    Invalid_Bin_String() : base_exception(SDYZ_INVALID_BIN_STRING_CODE, SDYZ_INVALID_BIN_STRING_MESSAGE)
    {
    }

    Invalid_Bin_String (const char* _Position) : base_exception(SDYZ_INVALID_BIN_STRING_CODE, SDYZ_INVALID_BIN_STRING_MESSAGE, _Position)
    {
    }

    ~Invalid_Bin_String()
    {
    }

};

