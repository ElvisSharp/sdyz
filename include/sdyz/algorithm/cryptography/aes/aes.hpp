/*********************************************************
*"aes"是AES加密算法的类
*作者：三点一洲
* Copyright (c) 三点一洲工作室
***********************************************************/

#pragma once
#include <sdyz/algorithm/cryptography/aes/aes_core.hpp>
#include <sdyz/vector/byte_vector.hpp>

namespace sdyz
{
	//aes类需要先用128bits的明文/密文初始化，然后选择加密模式，
	//最后都会将结果保存在aes类中
	//这里的变量basekey，指的是OFB模式的nonce
	class aes : public byte_vector
	{
		static const int AES_STD_BLOCK_SIZE;
	public:
		//空参构造
		aes();
		//初始化长度的字节容器，默认内容为0x0
		aes(size_t _Size);
		//初始化长度以及固定内容的字节容器
		aes(size_t _Size, byte _Byte);
		//用16进制字符串构造字节容器
		aes(const std::string& _HexS);
		//用字节数组构造字节容器
		aes(const byte* _ByteArr, size_t _Size);
		//拷贝构造函数
		aes(const aes& _AES);
		//整型构造函数
		aes(const byte_vector& _ByteVec);
		//析构函数
		~aes();

	public:
		//循环加密basekey，生成basekey
		static const byte_vector OFB_stream_producer(
			const byte_vector& _BaseKey,
			const byte_vector& _Key,
			size_t _Round_Count);

	public:
		//标准的AES加密
		void encrypt(const byte_vector& _Key);

		//标准的AES解密
		void decrypt(const byte_vector& _Key);

		//OFB模式AES加密
		void OFB_encrypt(const byte_vector& _BaseKey, const byte_vector& _Key);

		//OFB模式AES解密
		void OFB_decrypt(const byte_vector& _BaseKey, const byte_vector& _Key);

	public:
		const aes& operator=(const aes& _AES);

	};
}