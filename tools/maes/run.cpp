#include <iostream>
#include <cstdlib>
#include <ctime>

#include <sdyz/vector/byte_vector.hpp>
#include <sdyz/exception/exception_pack.hpp>
#include <sdyz/aes/aes.hpp>
#include <sdyz/hash/sha1.hpp>
#include <sdyz/arg_parser/arg_parser.hpp>

#include "run.h"
#include "exception.hpp"

using namespace sdyz;
using namespace std;

const opt_map opt_set{
		{ "-h",        HELP },
		{ "--help",    HELP },
		{ "-e",        EN },
		{ "--en",      EN },
		{ "-d",        DE },
		{ "--de",      DE },
		{ "-i",        INPUT },
		{ "--input",   INPUT },
		{ "-k",        KEY },
		{ "--key",     KEY }
};

byte_vector rand_byte_vector(size_t _Size)
{
	size_t i = 0;
	srand(time(NULL));
	byte_vector res(_Size);
	while (i++ < _Size)
	{
		res[i - 1] = rand() % 0x100;
	}
	return res;
}

void run(int _Argc, char** _Argv)
{
	if (_Argc < 2)
	{
		return;
	}
	arg_parser parser(OPT_TOTAL_AMOUNT, &opt_set, INPUT);
	parser.process_command(_Argc, _Argv);
	sdyz::byte_vector key;
	//打印帮助信息
	if (parser[HELP].cmd_exists())
	{
		printHelpInfo();
		return;
	}
	//判断是否同时存在加密解密
	if (parser[DE].cmd_exists() && (parser[EN].cmd_exists()))
	{
		throw Encryption_And_Decryption_Contradiction(__func__);
	}
	//判断是否不存在加密解密
	if (!(parser[DE].cmd_exists()) && !(parser[EN].cmd_exists()))
	{
		throw Unspecified_Encryption_Or_Decryption(__func__);
	}
	//获取Key
	if (parser[KEY].cmd_exists())
	{
		key = sha1(parser[KEY][0]);
		key.resize(16);
	}
	else
	{
		throw Unspecified_Cryption_Key(__func__);
	}

	//加密
	if (parser[EN].cmd_exists())
	{
		aes p(to_byte_vector(parser[INPUT][0]));
		byte_vector nonce = rand_byte_vector(16);
		p.OFB_encrypt(nonce, key);
		cout << nonce.to_hex_string() << p.to_hex_string() << endl;
	}
	//解密
	else if (parser[DE].cmd_exists())
	{
		byte_vector input_vector(parser[INPUT][0]);
		byte_vector nonce(16);
		byte_vector input(input_vector.size() - 16);
		std::copy(input_vector.begin(), input_vector.begin() + 16, nonce.begin());
		std::copy(input_vector.begin() + 16, input_vector.end(), input.begin());
		aes c(input);
		c.OFB_decrypt(nonce, key);
		cout << to_string(c) << endl;
	}
}

void printHelpInfo()
{
	string s = "This program is developed by 三点一洲（三点一洲工作室）\n"
		"Copyright (c) 三点一洲（三点一洲工作室） All copyright reserved\n"
		"The simple help for AES:\n";
	cout << s;
	cout << "-h, --help\t显示帮助信息" << endl;
	cout << "-e, --en\t对明文进行加密" << endl;
	cout << "-d, --de\t对密文进行解密" << endl;
	cout << "-i, --input\t输入明文或密文" << endl;
	cout << "-k, --key\tAES的密钥" << endl;
}

