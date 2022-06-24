/*********************************************************
*"byte_vector"是字节串容器类
*作者：三点一洲
* Copyright (c) 三点一洲工作室
***********************************************************/

#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <bitset>
#include <sdyz/vector/exception.hpp>

namespace sdyz
{
	typedef uint8_t byte;
	typedef uint16_t word;
	typedef std::bitset<8> std_byte;
	typedef std::bitset<32> std_dword;
	typedef std::vector<byte> std_byte_vec;

#define SDYZ_HEX_BASE_CHARACTER "0123456789ABCDEF"

	class byte_vector :
		public std_byte_vec
	{
	public:
		//空参构造
		byte_vector();

		//初始化长度的字节容器，默认内容为0x0
		byte_vector(size_t _Size);

		//初始化长度以及固定内容的字节容器
		byte_vector(size_t _Size, byte _Byte);

		//用16进制字符串构造字节容器
		byte_vector(const std::string& _HexS);

		//用字节数组构造字节容器
		byte_vector(const byte* _Byte_Arr, size_t _Size);

		//拷贝构造函数
		byte_vector(const byte_vector& _Byte_Vec);

		//析构函数
		~byte_vector();

	public:
		//+号表示连接两个字节容器
		byte_vector operator+(const byte_vector& _Byte_Vec) const;

		//与运算，结果的长度取短的
		byte_vector operator&(const byte_vector& _Byte_Vec) const;

		//或运算，结果的长度取短的
		byte_vector operator|(const byte_vector& _Byte_Vec) const;

		//异或运算，结果的长度取短的
		byte_vector operator^(const byte_vector& _Byte_Vec) const;

		//赋值
		void operator=(const byte_vector& _Byte_Vec);

		//判断是否相等
		bool operator==(const byte_vector& _Byte_Vec) const;

		bool operator!=(const byte_vector& _Byte_Vec) const;

	public:
		//转换成16进制字符串
		std::string to_hex_string() const;

		//转换成2进制字符串
		std::string to_bin_string() const;
		
		//用16进制字符串赋值
		void set_by_hex_string(const std::string& _HexS);

		//用2进制字符串赋值
		void set_by_bin_string(const std::string& _BinS);

		//用字节数组赋值字节容器
		void set_by_byte_arr(const byte* _Source, size_t _Size);

		//用字节数组赋值字节容器
		void set_by_byte_arr(const std_byte* _Source, size_t _Size);

		//复制一份数据到一块内存
		void copy_to_byte_arr(byte* _Destination, size_t _Size) const;

		void copy_to_byte_arr(std_byte* _Destination, size_t _Size) const;

	};
	//将普通字符串转成字节数组
	byte_vector to_byte_vector(const std::string& _S);

	//将字节数组转成普通字符串
	std::string to_string(const byte_vector& _B);

	//重载对std::istream流的支持
	std::ifstream& operator>>(std::ifstream& _In, byte_vector& _Vec);

	//重载对std::ostream流的支持
	std::ofstream& operator<<(std::ofstream& _Out, const byte_vector& _Vec);

};