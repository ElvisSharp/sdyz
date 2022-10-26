#pragma once
#include <string>
#include <sdyz/vector/byte_vector.hpp>

namespace sdyz
{
    using std::string;

    // 随机数组生成
    sdyz::byte_vector rand_byte_vector(size_t _Size);

    class crypter
    {
    public:
        /*************************************************
         * encrypt：加密函数
         * _Plain: 明文
         * _Key: 密码
         * return: 16进制密文
         *************************************************/
        virtual string encrypt(const string& _Plain, const string& _Key) = 0;

        /**************************************************
         * decrypt：解密函数
         * _Cipher: 字符串密文
         * _Key: 密码
         * return: 明文
         ***************************************************/
        virtual string decrypt(const string& _Cipher, const string& _Key) = 0;

        /**************************************************
         * check_key：判断密钥是否正确函数
         * _Cipher: 字符串密文
         * _Key: 密码
         * return: 是/否
         ***************************************************/
        virtual bool check_key(const string& _Cipher, const string& _Key) = 0;
    };

    // |-------plain hex text-----------|-------------------------------decrypted content by aes------------------|
    // |------rnd nonce 16bits----------|-------key double sha1 20bits-----------|------<your content...>---------|
    class aes_crypter : protected crypter
    {
    public:
        virtual string encrypt(const string& _Plain, const string& _Key);

        virtual string decrypt(const string& _Cipher, const string& _Key);

        virtual bool check_key(const string& _Cipher, const string& _Key);

    };
};