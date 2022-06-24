#pragma once

#include <sdyz/exception/base_exception.hpp>

class Encryption_And_Decryption_Contradiction : public sdyz::base_exception
{
public:
#define SDYZ_ENCRYPTION_AND_DECRYPTION_CONTRADICTION_CODE 3000
#define SDYZ_ENCRYPTION_AND_DECRYPTION_CONTRADICTION_MESSAGE "加密解密方式矛盾"

    Encryption_And_Decryption_Contradiction() : base_exception(SDYZ_ENCRYPTION_AND_DECRYPTION_CONTRADICTION_CODE, SDYZ_ENCRYPTION_AND_DECRYPTION_CONTRADICTION_MESSAGE)
    {
    }

    Encryption_And_Decryption_Contradiction(const char* _Position) : base_exception(SDYZ_ENCRYPTION_AND_DECRYPTION_CONTRADICTION_CODE, SDYZ_ENCRYPTION_AND_DECRYPTION_CONTRADICTION_MESSAGE, _Position)
    {
    }

    ~Encryption_And_Decryption_Contradiction()
    {
    }

};

class Unspecified_Encryption_Or_Decryption : public sdyz::base_exception
{
public:
#define SDYZ_UNSPECIFIED_ENCRYPTION_OR_DECRYPTION_CODE 3001
#define SDYZ_UNSPECIFIED_ENCRYPTION_OR_DECRYPTION_MESSAGE "未指定加密或解密"

    Unspecified_Encryption_Or_Decryption() : base_exception(SDYZ_UNSPECIFIED_ENCRYPTION_OR_DECRYPTION_CODE, SDYZ_UNSPECIFIED_ENCRYPTION_OR_DECRYPTION_MESSAGE)
    {
    }

    Unspecified_Encryption_Or_Decryption(const char* _Position) : base_exception(SDYZ_UNSPECIFIED_ENCRYPTION_OR_DECRYPTION_CODE, SDYZ_UNSPECIFIED_ENCRYPTION_OR_DECRYPTION_MESSAGE, _Position)
    {
    }

    ~Unspecified_Encryption_Or_Decryption()
    {
    }

};

class Unspecified_Cryption_Key : public sdyz::base_exception
{
public:
#define SDYZ_UNSPECIFIED_CRYPTION_KEY_CODE 3002
#define SDYZ_UNSPECIFIED_CRYPTION_KEY_MESSAGE "未指定密钥"

    Unspecified_Cryption_Key() : base_exception(SDYZ_UNSPECIFIED_CRYPTION_KEY_CODE, SDYZ_UNSPECIFIED_CRYPTION_KEY_MESSAGE)
    {
    }

    Unspecified_Cryption_Key(const char* _Position) : base_exception(SDYZ_UNSPECIFIED_CRYPTION_KEY_CODE, SDYZ_UNSPECIFIED_CRYPTION_KEY_MESSAGE, _Position)
    {
    }

    ~Unspecified_Cryption_Key()
    {
    }

};

