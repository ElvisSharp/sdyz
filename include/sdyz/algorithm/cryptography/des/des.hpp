/*********************************************************
*"des"是DES加密算法的类
*作者：三点一洲
* Copyright (c) 三点一洲工作室
***********************************************************/

#pragma once
#include <sdyz/algorithm/cryptography/des/des_core.hpp>
#include <sdyz/vector/byte_vector.hpp>

namespace sdyz
{
	//des类需要先用128bits的明文/密文初始化，然后选择加密模式，
	//最后都会将结果保存在des类中
	//这里的变量basekey，指的是OFB模式的nonce
	class des : public byte_vector
	{
		static const int DES_STD_BLOCK_SIZE;
	public:
		//空参构造
		des();
		//初始化长度的字节容器，默认内容为0x0
		des(size_t _Size);
		//初始化长度以及固定内容的字节容器
		des(size_t _Size, byte _Byte);
		//用16进制字符串构造字节容器
		des(const std::string& _HexS);
		//用字节数组构造字节容器
		des(const byte* _ByteArr, size_t _Size);
		//拷贝构造函数
		des(const des& _DES);
		//整型构造函数
		des(const byte_vector& _ByteVec);
		//析构函数
		~des();

	public:
		//循环加密basekey，生成basekey
		static const byte_vector OFB_stream_producer(
			const byte_vector& _BaseKey,
			const byte_vector& _Key,
			size_t _Round_Count);

	public:
		//标准的DES加密
		void encrypt(const byte_vector& _Key);

		//标准的DES解密
		void decrypt(const byte_vector& _Key);

		//OFB模式DES加密
		void OFB_encrypt(const byte_vector& _BaseKey, const byte_vector& _Key);

		//OFB模式DES解密
		void OFB_decrypt(const byte_vector& _BaseKey, const byte_vector& _Key);

	public:
		const des& operator=(const des& _DES);

	};
}