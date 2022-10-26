#include <sdyz/crypter/crypter.hpp>
#include <sdyz/algorithm/hash/sha1.hpp>
#include <sdyz/algorithm/cryptography/aes/aes.hpp>
#include <sdyz/exception/exception_pack.hpp>
#include <sdyz/vector/byte_vector.hpp>
#include <sdyz/tools/encoding.hpp>

namespace sdyz
{
    // ����ֽ�����
    sdyz::byte_vector rand_byte_vector(size_t _Size) 
    {
        size_t i = 0;
        srand(time(NULL));
        sdyz::byte_vector res(_Size);
        while (i++ < _Size) {
            res[i - 1] = rand() % 0x100;
        }
        return res;
    }

    string aes_crypter::encrypt(const std::string& _Plain, const std::string& _Key)
    {
        // �������nonce
        sdyz::byte_vector nonce = sdyz::rand_byte_vector(16);
        // �������������sha1
        sdyz::byte_vector sha1_x2_key;
        sha1_x2_key = sdyz::sha1(_Key);
        sha1_x2_key = sdyz::sha1(sha1_x2_key.to_hex_string());
        // ������תΪ�ֽ�����
        sdyz::aes plain(sdyz::to_byte_vector(_Plain));
        plain = sha1_x2_key + plain;
        // �������׼��Ϊ16���ֽڵ���Կ
        sdyz::byte_vector key;
        key = sdyz::sha1(_Key);
        key.resize(16);
        // �����Ľ���OFB����
        plain.OFB_encrypt(nonce, key);
        return nonce.to_hex_string() + plain.to_hex_string();
    }

    string aes_crypter::decrypt(const std::string& _Cipher, const std::string& _Key)
    {
        // ������Կ
        sdyz::byte_vector key;
        // ������sha1��ȡǰ16���ֽ�
        key = sdyz::sha1(_Key);
        key.resize(16);
        // �������������sha1
        sdyz::byte_vector sha1_x2_key;
        sha1_x2_key = sdyz::sha1(_Key);
        sha1_x2_key = sdyz::sha1(sha1_x2_key.to_hex_string());
        // ������ַ���תΪbyte_vector
        sdyz::byte_vector input_vector(_Cipher);
        // ȡǰ16���ֽ�Ϊnonce����Ϊ����
        sdyz::byte_vector nonce(16);
        std::copy(input_vector.begin(), input_vector.begin() + 16, nonce.begin());
        sdyz::byte_vector input(input_vector.size() - 16);
        std::copy(input_vector.begin() + 16, input_vector.end(), input.begin());
        sdyz::aes cipher(input);
        cipher.OFB_decrypt(nonce, key);
        // �Ա�����sha1�Ľ��
        sdyz::byte_vector input_sha1_x2_key(20);
        std::copy(cipher.begin(), cipher.begin() + 20, input_sha1_x2_key.begin());
        if (input_sha1_x2_key != sha1_x2_key)
        {
            return "";
        }
        sdyz::byte_vector res(cipher.size() - 20);
        std::copy(cipher.begin() + 20, cipher.end(), res.begin());
        return to_string(res);
    }

    bool aes_crypter::check_key(const std::string& _Cipher, const std::string& _Key)
    {
        // ������Կ
        sdyz::byte_vector key;
        // ������sha1��ȡǰ16���ֽ�
        key = sdyz::sha1(_Key);
        key.resize(16);
        // �������������sha1
        sdyz::byte_vector sha1_x2_key;
        sha1_x2_key = sdyz::sha1(_Key);
        sha1_x2_key = sdyz::sha1(sha1_x2_key.to_hex_string());
        // ������ַ���תΪbyte_vector
        sdyz::byte_vector input_vector(_Cipher);
        // ȡǰ16���ֽ�Ϊnonce����Ϊ����
        sdyz::byte_vector nonce(16);
        std::copy(input_vector.begin(), input_vector.begin() + 16, nonce.begin());
        sdyz::byte_vector input(input_vector.size() - 16);
        std::copy(input_vector.begin() + 16, input_vector.end(), input.begin());
        sdyz::aes cipher(input);
        cipher.OFB_decrypt(nonce, key);
        // �Ա�����sha1�Ľ��
        sdyz::byte_vector input_sha1_x2_key(20);
        std::copy(cipher.begin(), cipher.begin() + 20, input_sha1_x2_key.begin());
        if (input_sha1_x2_key != sha1_x2_key)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}