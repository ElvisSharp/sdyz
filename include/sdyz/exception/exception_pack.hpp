#pragma once
#include <sdyz/exception/base_exception.hpp>
namespace sdyz {
	class Arithmetic_Execption : public base_exception
	{
	public:
#define SDYZ_ARITHMETIC_EXECPTION_CODE 1001
#define SDYZ_ARITHMETIC_EXECPTION_MESSAGE "算数异常"

		Arithmetic_Execption() : base_exception(SDYZ_ARITHMETIC_EXECPTION_CODE, SDYZ_ARITHMETIC_EXECPTION_MESSAGE)
		{
		}

		Arithmetic_Execption(const char* _Position) : base_exception(SDYZ_ARITHMETIC_EXECPTION_CODE, SDYZ_ARITHMETIC_EXECPTION_MESSAGE, _Position)
		{
		}

		~Arithmetic_Execption()
		{
		}

	};

	class NullPointer_Exception : public base_exception
	{
	public:
#define SDYZ_NULLPOINTER_EXCEPTION_CODE 1002
#define SDYZ_NULLPOINTER_EXCEPTION_MESSAGE "空指针异常"

		NullPointer_Exception() : base_exception(SDYZ_NULLPOINTER_EXCEPTION_CODE, SDYZ_NULLPOINTER_EXCEPTION_MESSAGE)
		{
		}

		NullPointer_Exception(const char* _Position) : base_exception(SDYZ_NULLPOINTER_EXCEPTION_CODE, SDYZ_NULLPOINTER_EXCEPTION_MESSAGE, _Position)
		{
		}

		~NullPointer_Exception()
		{
		}

	};

	class Class_Cast_Exception : public base_exception
	{
	public:
#define SDYZ_CLASS_CAST_EXCEPTION_CODE 1003
#define SDYZ_CLASS_CAST_EXCEPTION_MESSAGE "类型强制转换异常"

		Class_Cast_Exception() : base_exception(SDYZ_CLASS_CAST_EXCEPTION_CODE, SDYZ_CLASS_CAST_EXCEPTION_MESSAGE)
		{
		}

		Class_Cast_Exception(const char* _Position) : base_exception(SDYZ_CLASS_CAST_EXCEPTION_CODE, SDYZ_CLASS_CAST_EXCEPTION_MESSAGE, _Position)
		{
		}

		~Class_Cast_Exception()
		{
		}

	};

	class Negative_Array_Exception : public base_exception
	{
	public:
#define SDYZ_NEGATIVE_ARRAY_EXCEPTION_CODE 1004
#define SDYZ_NEGATIVE_ARRAY_EXCEPTION_MESSAGE "数组负下标异常"

		Negative_Array_Exception() : base_exception(SDYZ_NEGATIVE_ARRAY_EXCEPTION_CODE, SDYZ_NEGATIVE_ARRAY_EXCEPTION_MESSAGE)
		{
		}

		Negative_Array_Exception(const char* _Position) : base_exception(SDYZ_NEGATIVE_ARRAY_EXCEPTION_CODE, SDYZ_NEGATIVE_ARRAY_EXCEPTION_MESSAGE, _Position)
		{
		}

		~Negative_Array_Exception()
		{
		}

	};

	class Array_Index_Out_Of_Bounds_Exception : public base_exception
	{
	public:
#define SDYZ_ARRAY_INDEX_OUT_OF_BOUNDS_EXCEPTION_CODE 1005
#define SDYZ_ARRAY_INDEX_OUT_OF_BOUNDS_EXCEPTION_MESSAGE "数组下标越界异常"

		Array_Index_Out_Of_Bounds_Exception() : base_exception(SDYZ_ARRAY_INDEX_OUT_OF_BOUNDS_EXCEPTION_CODE, SDYZ_ARRAY_INDEX_OUT_OF_BOUNDS_EXCEPTION_MESSAGE)
		{
		}

		Array_Index_Out_Of_Bounds_Exception(const char* _Position) : base_exception(SDYZ_ARRAY_INDEX_OUT_OF_BOUNDS_EXCEPTION_CODE, SDYZ_ARRAY_INDEX_OUT_OF_BOUNDS_EXCEPTION_MESSAGE, _Position)
		{
		}

		~Array_Index_Out_Of_Bounds_Exception()
		{
		}

	};

	class Negative_Array_Size_Exception : public base_exception
	{
	public:
#define SDYZ_NEGATIVE_ARRAY_SIZE_EXCEPTION_CODE 1006
#define SDYZ_NEGATIVE_ARRAY_SIZE_EXCEPTION_MESSAGE "创建一个大小为负数的数组错误异常"

		Negative_Array_Size_Exception() : base_exception(SDYZ_NEGATIVE_ARRAY_SIZE_EXCEPTION_CODE, SDYZ_NEGATIVE_ARRAY_SIZE_EXCEPTION_MESSAGE)
		{
		}

		Negative_Array_Size_Exception(const char* _Position) : base_exception(SDYZ_NEGATIVE_ARRAY_SIZE_EXCEPTION_CODE, SDYZ_NEGATIVE_ARRAY_SIZE_EXCEPTION_MESSAGE, _Position)
		{
		}

		~Negative_Array_Size_Exception()
		{
		}

	};

	class EOF_Exception : public base_exception
	{
	public:
#define SDYZ_EOF_EXCEPTION_CODE 1007
#define SDYZ_EOF_EXCEPTION_MESSAGE "文件已结束异常"

		EOF_Exception() : base_exception(SDYZ_EOF_EXCEPTION_CODE, SDYZ_EOF_EXCEPTION_MESSAGE)
		{
		}

		EOF_Exception(const char* _Position) : base_exception(SDYZ_EOF_EXCEPTION_CODE, SDYZ_EOF_EXCEPTION_MESSAGE, _Position)
		{
		}

		~EOF_Exception()
		{
		}

	};

	class File_Not_Found_Exception : public base_exception
	{
	public:
#define SDYZ_FILE_NOT_FOUND_EXCEPTION_CODE 1008
#define SDYZ_FILE_NOT_FOUND_EXCEPTION_MESSAGE "文件未找到异常"

		File_Not_Found_Exception() : base_exception(SDYZ_FILE_NOT_FOUND_EXCEPTION_CODE, SDYZ_FILE_NOT_FOUND_EXCEPTION_MESSAGE)
		{
		}

		File_Not_Found_Exception(const char* _Position) : base_exception(SDYZ_FILE_NOT_FOUND_EXCEPTION_CODE, SDYZ_FILE_NOT_FOUND_EXCEPTION_MESSAGE, _Position)
		{
		}

		~File_Not_Found_Exception()
		{
		}

	};

	class IO_Exception : public base_exception
	{
	public:
#define SDYZ_IO_EXCEPTION_CODE 1009
#define SDYZ_IO_EXCEPTION_MESSAGE "输入输出异常"

		IO_Exception() : base_exception(SDYZ_IO_EXCEPTION_CODE, SDYZ_IO_EXCEPTION_MESSAGE)
		{
		}

		IO_Exception(const char* _Position) : base_exception(SDYZ_IO_EXCEPTION_CODE, SDYZ_IO_EXCEPTION_MESSAGE, _Position)
		{
		}

		~IO_Exception()
		{
		}

	};

	class Number_Format_Exception : public base_exception
	{
	public:
#define SDYZ_NUMBER_FORMAT_EXCEPTION_CODE 1010
#define SDYZ_NUMBER_FORMAT_EXCEPTION_MESSAGE "数据格式异常"

		Number_Format_Exception() : base_exception(SDYZ_NUMBER_FORMAT_EXCEPTION_CODE, SDYZ_NUMBER_FORMAT_EXCEPTION_MESSAGE)
		{
		}

		Number_Format_Exception(const char* _Position) : base_exception(SDYZ_NUMBER_FORMAT_EXCEPTION_CODE, SDYZ_NUMBER_FORMAT_EXCEPTION_MESSAGE, _Position)
		{
		}

		~Number_Format_Exception()
		{
		}

	};

	class Illegal_Argument_Exception : public base_exception
	{
	public:
#define SDYZ_ILLEGAL_ARGUMENT_EXCEPTION_CODE 1011
#define SDYZ_ILLEGAL_ARGUMENT_EXCEPTION_MESSAGE "非法参数异常"

		Illegal_Argument_Exception() : base_exception(SDYZ_ILLEGAL_ARGUMENT_EXCEPTION_CODE, SDYZ_ILLEGAL_ARGUMENT_EXCEPTION_MESSAGE)
		{
		}

		Illegal_Argument_Exception(const char* _Position) : base_exception(SDYZ_ILLEGAL_ARGUMENT_EXCEPTION_CODE, SDYZ_ILLEGAL_ARGUMENT_EXCEPTION_MESSAGE, _Position)
		{
		}

		~Illegal_Argument_Exception()
		{
		}

	};

	class System_Exception : public base_exception
	{
	public:
#define SDYZ_SYSTEM_EXCEPTION_CODE 1012
#define SDYZ_SYSTEM_EXCEPTION_MESSAGE "系统异常"

		System_Exception() : base_exception(SDYZ_SYSTEM_EXCEPTION_CODE, SDYZ_SYSTEM_EXCEPTION_MESSAGE)
		{
		}

		System_Exception(const char* _Position) : base_exception(SDYZ_SYSTEM_EXCEPTION_CODE, SDYZ_SYSTEM_EXCEPTION_MESSAGE, _Position)
		{
		}

		~System_Exception()
		{
		}

	};

	class Secturity_Exception : public base_exception
	{
	public:
#define SDYZ_SECTURITY_EXCEPTION_CODE 1013
#define SDYZ_SECTURITY_EXCEPTION_MESSAGE "违背安全原则异常"

		Secturity_Exception() : base_exception(SDYZ_SECTURITY_EXCEPTION_CODE, SDYZ_SECTURITY_EXCEPTION_MESSAGE)
		{
		}

		Secturity_Exception(const char* _Position) : base_exception(SDYZ_SECTURITY_EXCEPTION_CODE, SDYZ_SECTURITY_EXCEPTION_MESSAGE, _Position)
		{
		}

		~Secturity_Exception()
		{
		}

	};

	class Security_Exception : public base_exception
	{
	public:
#define SDYZ_SECURITY_EXCEPTION_CODE 1014
#define SDYZ_SECURITY_EXCEPTION_MESSAGE "安全异常"

		Security_Exception() : base_exception(SDYZ_SECURITY_EXCEPTION_CODE, SDYZ_SECURITY_EXCEPTION_MESSAGE)
		{
		}

		Security_Exception(const char* _Position) : base_exception(SDYZ_SECURITY_EXCEPTION_CODE, SDYZ_SECURITY_EXCEPTION_MESSAGE, _Position)
		{
		}

		~Security_Exception()
		{
		}

	};

	class Unsupported_Operation_Exception : public base_exception
	{
	public:
#define SDYZ_UNSUPPORTED_OPERATION_EXCEPTION_CODE 1015
#define SDYZ_UNSUPPORTED_OPERATION_EXCEPTION_MESSAGE "不支持的操作异常"

		Unsupported_Operation_Exception() : base_exception(SDYZ_UNSUPPORTED_OPERATION_EXCEPTION_CODE, SDYZ_UNSUPPORTED_OPERATION_EXCEPTION_MESSAGE)
		{
		}

		Unsupported_Operation_Exception(const char* _Position) : base_exception(SDYZ_UNSUPPORTED_OPERATION_EXCEPTION_CODE, SDYZ_UNSUPPORTED_OPERATION_EXCEPTION_MESSAGE, _Position)
		{
		}

		~Unsupported_Operation_Exception()
		{
		}

	};
}