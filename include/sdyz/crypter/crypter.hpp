#pragma once
#include <string>
#include <sdyz/vector/byte_vector.hpp>

namespace sdyz
{
    using std::string;

    // �����������
    sdyz::byte_vector rand_byte_vector(size_t _Size);

    class crypter
    {
    public:
        /*************************************************
         * encrypt�����ܺ���
         * _Plain: ����
         * _Key: ����
         * return: 16��������
         *************************************************/
        virtual string encrypt(const string& _Plain, const string& _Key) = 0;

        /**************************************************
         * decrypt�����ܺ���
         * _Cipher: �ַ�������
         * _Key: ����
         * return: ����
         ***************************************************/
        virtual string decrypt(const string& _Cipher, const string& _Key) = 0;

        /**************************************************
         * check_key���ж���Կ�Ƿ���ȷ����
         * _Cipher: �ַ�������
         * _Key: ����
         * return: ��/��
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