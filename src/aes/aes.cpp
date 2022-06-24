#include <sdyz/aes/aes_core.hpp>
#include <sdyz/aes/aes.hpp>
#include <sdyz/vector/byte_vector.hpp>

namespace sdyz
{
	//将AES分组长度16字节，即128bit
	const int aes::AES_STD_BLOCK_SIZE = 16;
	aes::aes()
	{

	}

	aes::aes(size_t _Size) :
		byte_vector(_Size)
	{

	}

	aes::aes(size_t _Size, byte _Byte) :
		byte_vector(_Size, _Byte)
	{

	}

	aes::aes(const std::string& _HexS) :
		byte_vector(_HexS)
	{

	}

	aes::aes(const byte* _ByteArr, size_t _Size) :
		byte_vector(_ByteArr, _Size)
	{

	}

	aes::aes(const aes& _AES)
	{
		operator=(_AES);
	}
	
	aes::aes(const byte_vector& _ByteVec) : byte_vector(_ByteVec)
	{

	}

	aes::~aes()
	{

	}

	void aes::encrypt(const byte_vector& _Key)
	{
		std_byte key[AES_STD_BLOCK_SIZE];
		_Key.copy_to_byte_arr(key, AES_STD_BLOCK_SIZE);
		std_byte plain[AES_STD_BLOCK_SIZE];
		copy_to_byte_arr(plain, AES_STD_BLOCK_SIZE);
		std_dword* w = new std_dword[4 * (aes_core::Nr + 1)];
		aes_core::KeyExpansion(key, w);
		aes_core::encrypt(plain, w);
		set_by_byte_arr(plain, AES_STD_BLOCK_SIZE);
		delete w;
	}

	void aes::decrypt(const byte_vector& _Key)
	{
		std_byte key[AES_STD_BLOCK_SIZE];
		_Key.copy_to_byte_arr(key, AES_STD_BLOCK_SIZE);
		std_byte cipher[AES_STD_BLOCK_SIZE];
		copy_to_byte_arr(cipher, AES_STD_BLOCK_SIZE);
		std_dword* w = new std_dword[4 * (aes_core::Nr + 1)];
		aes_core::KeyExpansion(key, w);
		aes_core::decrypt(cipher, w);
		set_by_byte_arr(cipher, AES_STD_BLOCK_SIZE);
		delete w;
	}

	const byte_vector aes::OFB_stream_producer(const byte_vector& _BaseKey,
		const byte_vector& _Key,
		size_t _Round_Count)
	{
		byte_vector res;
		//basekey是标准的128bits
		aes base_key(_BaseKey);
		byte_vector key(_Key);
		for (int i = 0; i < _Round_Count; ++i)
		{
			//循环加密
			base_key.encrypt(key);
			res = res + base_key;
		}
		return res;
	}

	void aes::OFB_encrypt(const byte_vector& _BaseKey,
		const byte_vector& _Key)
	{
		byte_vector OFB_stream = aes::OFB_stream_producer(_BaseKey,
			_Key, size() / _Key.size() + 1);
		*this = (*this) ^ OFB_stream;
		return;
	}

	void aes::OFB_decrypt(const byte_vector& _BaseKey,
		const byte_vector& _Key)
	{
		byte_vector OFB_Stream = aes::OFB_stream_producer(_BaseKey,
			_Key, size() / _Key.size() + 1);
		*this = (*this) ^ OFB_Stream;
		return;
	}

	const aes& aes::operator=(const aes& _AES)
	{
		byte_vector::operator=(_AES);
		return *this;
	}
}