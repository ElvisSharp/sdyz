#include <sdyz/crypter/crypter.hpp>
#include <sdyz/algorithm/hash/sha1.hpp>
#include <sdyz/algorithm/cryptography/aes/aes.hpp>
#include <sdyz/exception/exception_pack.hpp>
#include <sdyz/vector/byte_vector.hpp>
#include <sdyz/tools/encoding.hpp>

namespace sdyz
{
    // 随机字节数组
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

    string crypter_factory::aes_crypter::encrypt(const std::string& _Plain, const std::string& _Key)
    {
        // 生成随机nonce
        sdyz::byte_vector nonce = sdyz::rand_byte_vector(16);
        // 将密码进行两次sha1
        sdyz::byte_vector sha1_x2_key;
        sha1_x2_key = sdyz::sha1(_Key);
        sha1_x2_key = sdyz::sha1(sha1_x2_key.to_hex_string());
        // 将明文转为字节数组
        sdyz::aes plain(sdyz::to_byte_vector(_Plain));
        plain = sha1_x2_key + plain;
        // 将密码标准化为16个字节的密钥
        sdyz::byte_vector key;
        key = sdyz::sha1(_Key);
        key.resize(16);
        // 对明文进行OFB加密
        plain.OFB_encrypt(nonce, key);
        return nonce.to_hex_string() + plain.to_hex_string();
    }

    string crypter_factory::aes_crypter::decrypt(const std::string& _Cipher, const std::string& _Key)
    {
        // 计算密钥
        sdyz::byte_vector key;
        // 对密码sha1，取前16个字节
        key = sdyz::sha1(_Key);
        key.resize(16);
        // 将密码进行两次sha1
        sdyz::byte_vector sha1_x2_key;
        sha1_x2_key = sdyz::sha1(_Key);
        sha1_x2_key = sdyz::sha1(sha1_x2_key.to_hex_string());
        // 输入的字符串转为byte_vector
        sdyz::byte_vector input_vector(_Cipher);
        // 取前16个字节为nonce，后为密文
        sdyz::byte_vector nonce(16);
        std::copy(input_vector.begin(), input_vector.begin() + 16, nonce.begin());
        sdyz::byte_vector input(input_vector.size() - 16);
        std::copy(input_vector.begin() + 16, input_vector.end(), input.begin());
        sdyz::aes cipher(input);
        cipher.OFB_decrypt(nonce, key);
        // 对比两次sha1的结果
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

    bool crypter_factory::aes_crypter::check_key(const std::string& _Cipher, const std::string& _Key)
    {
        // 计算密钥
        sdyz::byte_vector key;
        // 对密码sha1，取前16个字节
        key = sdyz::sha1(_Key);
        key.resize(16);
        // 将密码进行两次sha1
        sdyz::byte_vector sha1_x2_key;
        sha1_x2_key = sdyz::sha1(_Key);
        sha1_x2_key = sdyz::sha1(sha1_x2_key.to_hex_string());
        // 输入的字符串转为byte_vector
        sdyz::byte_vector input_vector(_Cipher);
        // 取前16个字节为nonce，后为密文
        sdyz::byte_vector nonce(16);
        std::copy(input_vector.begin(), input_vector.begin() + 16, nonce.begin());
        sdyz::byte_vector input(input_vector.size() - 16);
        std::copy(input_vector.begin() + 16, input_vector.end(), input.begin());
        sdyz::aes cipher(input);
        cipher.OFB_decrypt(nonce, key);
        // 对比两次sha1的结果
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
    crypter_ptr crypter_factory::create_crypter(crypter_option _Crypter_Option)
    {
        crypter_ptr res_crypter_ptr = nullptr;
        switch (_Crypter_Option)
        {
        case crypter_factory::crypter_option::AES:
            res_crypter_ptr = new crypter_factory::aes_crypter();
            break;
        case crypter_factory::crypter_option::DES:
            break;
        default:
            break;
        }
        return res_crypter_ptr;
    }

    void crypter_factory::destroy_crypter(crypter_ptr _Crypter)
    {
        delete _Crypter;
    }
}