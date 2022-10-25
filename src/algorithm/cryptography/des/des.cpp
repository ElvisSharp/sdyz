#include <sdyz/des/des_core.hpp>
#include <sdyz/des/des.hpp>
#include <sdyz/vector/byte_vector.hpp>

namespace sdyz
{
	//将DES分组长度8字节，即64bit
	const int des::DES_STD_BLOCK_SIZE = 8;
	des::des()
	{

	}

	des::des(size_t _Size) :
		byte_vector(_Size)
	{

	}

	des::des(size_t _Size, byte _Byte) :
		byte_vector(_Size, _Byte)
	{

	}

	des::des(const std::string& _HexS) :
		byte_vector(_HexS)
	{

	}

	des::des(const byte* _ByteArr, size_t _Size) :
		byte_vector(_ByteArr, _Size)
	{

	}

	des::des(const des& _DES)
	{
		operator=(_DES);
	}

	des::des(const byte_vector& _ByteVec) : byte_vector(_ByteVec)
	{

	}

	des::~des()
	{

	}

	void des::encrypt(const byte_vector& _Key)
	{
		des_core::Block block(this->to_bin_string());
		des_core::Block key(_Key.to_bin_string());
		des_core::des(block, key, des_core::e);
		this->set_by_bin_string(block.to_string());
	}

	void des::decrypt(const byte_vector& _Key)
	{
		des_core::Block block(this->to_bin_string());
		des_core::Block key(_Key.to_bin_string());
		des_core::des(block, key, des_core::d);
		this->set_by_bin_string(block.to_string());
	}

	const byte_vector des::OFB_stream_producer(const byte_vector& _Nonce,
		const byte_vector& _Key,
		size_t _Round_Count)
	{
		byte_vector res;
		//nonce是标准的64bits
		des nonce(_Nonce);
		byte_vector key(_Key);
		for (int i = 0; i < _Round_Count; ++i)
		{
			//循环加密
			nonce.encrypt(key);
			res = res + nonce;
		}
		return res;
	}

	void des::OFB_encrypt(const byte_vector& _Nonce,
		const byte_vector& _Key)
	{
		byte_vector OFB_stream = des::OFB_stream_producer(_Nonce,
			_Key, size() / _Key.size() + 1);
		*this = (*this) ^ OFB_stream;
		return;
	}

	void des::OFB_decrypt(const byte_vector& _Nonce,
		const byte_vector& _Key)
	{
		byte_vector OFB_Stream = des::OFB_stream_producer(_Nonce,
			_Key, size() / _Key.size() + 1);
		*this = (*this) ^ OFB_Stream;
		return;
	}

	const des& des::operator=(const des& _DES)
	{
		byte_vector::operator=(_DES);
		return *this;
	}
}