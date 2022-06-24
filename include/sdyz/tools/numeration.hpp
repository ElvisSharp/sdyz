/*********************************************************
*"numeration"是用于进制转换的类
*作者：三点一洲
* Copyright (c) 三点一洲工作室
***********************************************************/
#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <assert.h>

namespace sdyz
{

	class numeration
	{
	private:
		uint32_t number_;

	public:

		numeration();

		numeration(const uint32_t& _N);

		numeration(const numeration& _N);

		numeration(uint32_t _Radix,
			const std::string& _S);

		~numeration();

		const numeration& operator =(const numeration& _N);

		const numeration& operator =(const uint32_t& _N);

		void operator +=(const numeration& _N);

		void operator -=(const numeration& _N);

		void operator *=(const numeration& _N);

		void operator /=(const numeration& _N);

		numeration operator +(const numeration& _N)const;

		numeration operator -(const numeration& _N)const;

		numeration operator *(const numeration& _N)const;

		numeration operator /(const numeration& _N)const;

		bool operator ==(const numeration& _N)const;

		bool operator !=(const numeration& _N)const;

		bool operator<=(const numeration& _N)const;

		bool operator>=(const numeration& _N)const;

		bool operator <(const numeration& _N)const;

		bool operator >(const numeration& _N)const;

		std::string to_string(uint32_t _Radix)const;

		uint32_t to_uint32();

		bool set(uint32_t _N);

		bool set(uint32_t _Radix,
			const std::string& _S);

	};

}