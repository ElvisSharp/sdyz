#include <vector>
#include <string>
#include <iostream>
#include <bitset>
#include <sdyz/vector/exception.hpp>
#include <sdyz/vector/byte_vector.hpp>
#include <sdyz/tools/numeration.hpp>

namespace sdyz
{
	//空参构造
	byte_vector::byte_vector() :
		std_byte_vec()
	{
	}

	//初始化长度的字节容器，默认内容为0x0
	byte_vector::byte_vector(size_t _Size) :
		std_byte_vec(_Size)
	{
	}

	//初始化长度以及固定内容的字节容器
	byte_vector::byte_vector(size_t _Size, byte _Byte) :
		std_byte_vec(_Size, _Byte)
	{
	}

	//用16进制字符串构造字节容器
	byte_vector::byte_vector(const std::string& _HexS) :
		std_byte_vec()
	{
		set_by_hex_string(_HexS);
	}

	//用字节数组构造字节容器
	byte_vector::byte_vector(const byte* _Byte_Arr, size_t _Size) :
		std_byte_vec(_Size)
	{
		set_by_byte_arr(_Byte_Arr, _Size);
	}

	//拷贝构造函数
	byte_vector::byte_vector(const byte_vector& _Byte_Vec)
	{
		operator=(_Byte_Vec);
	}

	//析构函数
	byte_vector::~byte_vector()
	{
	}

	//+号表示连接两个字节容器
	byte_vector byte_vector::operator+(const byte_vector& _Byte_Vec) const
	{
		size_t l_size = this->size();
		size_t r_size = _Byte_Vec.size();
		size_t total_size = l_size + r_size;
		byte_vector byte_vec(total_size);
		for (size_t i = 0; i < l_size; ++i)
		{
			byte_vec[i] = (*this)[i];
		}
		for (size_t i = l_size; i < l_size + r_size; ++i)
		{
			byte_vec[i] = _Byte_Vec[i - l_size];
		}
		return byte_vec;
	}

	//与运算，结果的长度取短的
	byte_vector byte_vector::operator&(const byte_vector& _Byte_Vec) const
	{
		size_t vec_size = size() < _Byte_Vec.size() ? size() : _Byte_Vec.size();
		byte_vector byte_vec(vec_size);
		for (size_t i = 0; i < vec_size; ++i)
		{
			byte_vec[i] = (*this)[i] & _Byte_Vec[i];
		}
		return byte_vec;
	}

	//或运算，结果的长度取短的
	byte_vector byte_vector::operator|(const byte_vector& _Byte_Vec) const
	{
		size_t vec_size = size() < _Byte_Vec.size() ? size() : _Byte_Vec.size();
		byte_vector byte_vec(vec_size);
		for (size_t i = 0; i < vec_size; ++i)
		{
			byte_vec[i] = (*this)[i] | _Byte_Vec[i];
		}
		return byte_vec;
	}

	//异或运算，结果的长度取短的
	byte_vector byte_vector::operator^(const byte_vector& _Byte_Vec) const
	{
		size_t vec_size = size() < _Byte_Vec.size() ? size() : _Byte_Vec.size();
		byte_vector byte_vec(vec_size);
		for (size_t i = 0; i < vec_size; ++i)
		{
			byte_vec[i] = (*this)[i] ^ _Byte_Vec[i];
		}
		return byte_vec;
	}

	//赋值
	void byte_vector::operator=(const byte_vector& _Byte_Vec)
	{
		std_byte_vec::operator=(_Byte_Vec);
		return;
	}

	//判断是否相等
	bool byte_vector::operator==(const byte_vector& _Byte_Vec) const
	{
		size_t l_size = this->size();
		size_t r_size = _Byte_Vec.size();
		if (l_size != r_size)
		{
			return false;
		}
		for (size_t i = 0; i < l_size; ++i)
		{
			if ((*this)[i] != _Byte_Vec[i])
			{
				return false;
			}
		}
		return true;
	}

	bool byte_vector::operator!=(const byte_vector& _Byte_Vec) const
	{
		return !(operator==(_Byte_Vec));
	}

	//转换成16进制字符串
	std::string byte_vector::to_hex_string() const
	{
		size_t vec_size = size();
		std::string s;
		//逐字节转换连接
		for (size_t i = 0; i < vec_size; ++i)
		{
			numeration num(at(i));
			std::string tmp_str = num.to_string(16);
			size_t tmp_str_size = tmp_str.size();
			tmp_str.insert(0, 2 - tmp_str_size, '0');
			s += tmp_str;
		}
		return s;
	}

	//转换成2进制字符串
	std::string byte_vector::to_bin_string() const
	{
		size_t vec_size = size();
		std::string s;
		//逐字节转换连接
		for (size_t i = 0; i < vec_size; ++i)
		{
			numeration num(at(i));
			std::string tmp_str = num.to_string(2);
			size_t tmp_str_size = tmp_str.size();
			tmp_str.insert(0, 8 - tmp_str_size, '0');
			s += tmp_str;
		}
		return s;
	}

	//用16进制字符串赋值
	void byte_vector::set_by_hex_string(const std::string& _HexS)
	{
		//字节字符串长度不能为奇数
		if (_HexS.size() & 0x1)
		{
			throw Invalid_Hex_String(__func__);
		}
		size_t vec_size = (size_t)(_HexS.size() / 2);
		byte_vector byte_vec(vec_size);
		for (size_t i = 0; i < vec_size; ++i)
		{
			std::string tmp_str = _HexS.substr(2 * i, 2);
			numeration num(16, tmp_str);
			byte_vec[i] = num.to_uint32();
		}
		*this = byte_vec;
	}

	//用2进制字符串赋值
	void byte_vector::set_by_bin_string(const std::string& _BinS)
	{
		//二进制字符串长度一定是8的倍数
		if ((_BinS.size() & 0x7))
		{
			throw Invalid_Bin_String(__func__);
		}
		size_t vec_size = (size_t)(_BinS.size() >> 3);
		byte_vector byte_vec(vec_size);
		for (size_t i = 0; i < vec_size; ++i)
		{
			std::string tmp_str = _BinS.substr(8 * i, 8);
			numeration num(2, tmp_str);
			byte_vec[i] = num.to_uint32();
		}
		*this = byte_vec;
	}

	//用字节数组赋值字节容器
	void byte_vector::set_by_byte_arr(const byte* _Source, size_t _Size)
	{
		byte_vector tmp_vec(_Size);
		for (int i = 0; i < _Size; ++i)
		{
			tmp_vec[i] = _Source[i];
		}
		operator=(tmp_vec);
		return;
	}

	//用字节数组赋值字节容器
	void byte_vector::set_by_byte_arr(const std_byte* _Source, size_t _Size)
	{
		byte_vector tmp_vec(_Size);
		for (int i = 0; i < _Size; ++i)
		{
			tmp_vec[i] = _Source[i].to_ulong();
		}
		operator=(tmp_vec);
		return;
	}

	//复制一份数据到一块内存
	void byte_vector::copy_to_byte_arr(byte* _Destination, size_t _Size) const
	{
		size_t copy_size = size() < _Size ? size() : _Size;
		for (int i = 0; i < copy_size; ++i)
		{
			_Destination[i] = (*this)[i];
		}
	}

	void byte_vector::copy_to_byte_arr(std_byte* _Destination, size_t _Size) const
	{
		size_t copy_size = size() < _Size ? size() : _Size;
		for (int i = 0; i < copy_size; ++i)
		{
			_Destination[i] = std_byte((*this)[i]);
		}
	}

	byte_vector to_byte_vector(const std::string& _S)
	{
		byte_vector tmp_vec(_S.size());
		for (int i = 0; i < _S.size(); ++i)
		{
			tmp_vec[i] = (byte)_S[i];
		}
		return tmp_vec;
	}

	std::string to_string(const byte_vector& _B)
	{
		char* s = new char[_B.size() + 1];
		for (int i = 0; i < _B.size(); ++i)
		{
			s[i] = (char)_B[i];
		}
		s[_B.size()] = '\0';
		std::string tmp_str = s;
		delete[] s;
		return tmp_str;
	}

	std::ifstream& operator>>(std::ifstream& _In, byte_vector& _Vec)
	{
		//先获取文件大小
		size_t current_offset = _In.tellg();
		_In.seekg(0, std::ios::end);
		size_t stream_size = _In.tellg();
		//复原文件流位置
		_In.seekg(current_offset, std::ios::beg);
		_Vec.resize(stream_size);
		//由于byte_vector是连续分配容器，可以直接写到其内存中
		_In.read((char*)_Vec.data(), stream_size);
		return _In;
	}

	std::ofstream& operator<<(std::ofstream& _Out, const byte_vector& _Vec)
	{
		size_t stream_size = _Vec.size();
		_Out.write((char*)_Vec.data(), stream_size);
		return _Out;
	}

};