#pragma once
#include <sdyz/exception/base_exception.hpp>

class Invalid_Arguments : public sdyz::base_exception
{
public:
#define SDYZ_INVALID_ARGUMENTS_CODE 2020
#define SDYZ_INVALID_ARGUMENTS_MESSAGE "非法的命令行参数"

    Invalid_Arguments() : base_exception(SDYZ_INVALID_ARGUMENTS_CODE, SDYZ_INVALID_ARGUMENTS_MESSAGE)
    {
    }

    Invalid_Arguments (const char* _Position) : base_exception(SDYZ_INVALID_ARGUMENTS_CODE, SDYZ_INVALID_ARGUMENTS_MESSAGE, _Position)
    {
    }

    ~Invalid_Arguments()
    {
    }

};

class Invalid_Default_Cmd_Start_Index : public sdyz::base_exception
{
public:
#define SDYZ_INVALID_DEFAULT_CMD_START_INDEX_CODE 2021
#define SDYZ_INVALID_DEFAULT_CMD_START_INDEX_MESSAGE "非法的或未设置默认的命令开始下标"

    Invalid_Default_Cmd_Start_Index() : base_exception(SDYZ_INVALID_DEFAULT_CMD_START_INDEX_CODE, SDYZ_INVALID_DEFAULT_CMD_START_INDEX_MESSAGE)
    {
    }

    Invalid_Default_Cmd_Start_Index (const char* _Position) : base_exception(SDYZ_INVALID_DEFAULT_CMD_START_INDEX_CODE, SDYZ_INVALID_DEFAULT_CMD_START_INDEX_MESSAGE, _Position)
    {
    }

    ~Invalid_Default_Cmd_Start_Index()
    {
    }

};

