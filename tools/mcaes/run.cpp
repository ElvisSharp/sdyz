#include <iostream>
#include <cstdlib>
#include <ctime>

#include <sdyz/vector/byte_vector.hpp>
#include <sdyz/exception/exception_pack.hpp>
#include <sdyz/algorithm/cryptography/aes/aes.hpp>
#include <sdyz/algorithm/hash/sha1.hpp>
#include <sdyz/arg_parser/arg_parser.hpp>
#include <sdyz/crypter/crypter.hpp>
#include <sdyz/tools/encoding.hpp>

#include "run.hpp"
#include "exception.hpp"

using namespace sdyz;
using namespace std;

const opt_map opt_set{
		{ "-h",        (size_t)OPT::HELP },
		{ "--help",    (size_t)OPT::HELP },
		{ "-e",        (size_t)OPT::EN },
		{ "--en",      (size_t)OPT::EN },
		{ "-d",        (size_t)OPT::DE },
		{ "--de",      (size_t)OPT::DE },
		{ "-i",        (size_t)OPT::INPUT },
		{ "--input",   (size_t)OPT::INPUT },
		{ "-k",        (size_t)OPT::KEY },
		{ "--key",     (size_t)OPT::KEY }
};

void run(int _Argc, char** _Argv)
{
	if (_Argc < 2)
	{
		return;
	}
	arg_parser parser(OPT_TOTAL_AMOUNT, &opt_set, (size_t)OPT::INPUT);
	parser.process_command(_Argc, _Argv);
	std::string key;
	//打印帮助信息
	if (parser[(size_t)OPT::HELP].cmd_exists())
	{
		printHelpInfo();
		return;
	}
	crypter_ptr aes_crypter = crypter_factory::create_crypter(crypter_factory::crypter_option::AES);
	//判断是否同时存在加密解密
	if (parser[(size_t)OPT::DE].cmd_exists() && (parser[(size_t)OPT::EN].cmd_exists()))
	{
		throw Encryption_And_Decryption_Contradiction(__func__);
	}
	//判断是否不存在加密解密
	if (!(parser[(size_t)OPT::DE].cmd_exists()) && !(parser[(size_t)OPT::EN].cmd_exists()))
	{
		throw Unspecified_Encryption_Or_Decryption(__func__);
	}
	//获取Key
	if (parser[(size_t)OPT::KEY].cmd_exists())
	{
		key = parser[(size_t)OPT::KEY][0];
	}
	else
	{
		throw Unspecified_Cryption_Key(__func__);
	}

	//加密
	if (parser[(size_t)OPT::EN].cmd_exists())
	{
		cout << aes_crypter->encrypt(parser[(size_t)OPT::INPUT][0], key) << endl;
	}
	//解密
	else if (parser[(size_t)OPT::DE].cmd_exists())
	{
		if (aes_crypter->check_key(parser[(size_t)OPT::INPUT][0], key))
		{
			cout << aes_crypter->decrypt(parser[(size_t)OPT::INPUT][0], key) << endl;
		}
		else
		{
			cerr << "Wrong Password!" << endl;
		}
	}
	crypter_factory::destroy_crypter(aes_crypter);
}

void printHelpInfo()
{
	string s = "This program is developed by 三点一洲（三点一洲工作室）\n"
		"Copyright (c) 三点一洲（三点一洲工作室） All copyright reserved\n"
		"The simple help for mcaes:\n"
		"-h, --help\t显示帮助信息\n"
		"-e, --en\t对明文进行加密\n"
		"-d, --de\t对密文进行解密\n"
		"-i, --input\t输入明文或密文\n"
		"-k, --key\t密码\n";
#ifdef _WIN32
	cout << utf8_to_gbk(s.c_str());
#else
	cout << s;
#endif
}

