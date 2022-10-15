#ifndef CIPHER_H
#define CIPHER_H
#include <string>
#include <sdyz/vector/byte_vector.hpp>

namespace sdyz
{
    using std::string;

    // 随机数组生成
    sdyz::byte_vector rand_byte_vector(size_t _Size);

    // |-------plain hex text-----------|-------------------------------decrypted content by aes------------------|
    // |------rnd nonce 16bits----------|-------key double sha1 20bits-----------|------<your content...>---------|
    class mcaes
    {
    public:
        virtual string encrypt(const string& _Plain, const string& _Key);

        virtual string decrypt(const string& _Cipher, const string& _Key);

        virtual bool check_key(const string& _Cipher, const string& _Key);
    };
};
#endif // CIPHER_H
