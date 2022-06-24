#include <sdyz/tools/numeration.hpp>

namespace sdyz
{

	numeration::numeration() :
		number_(0L)
	{
	}

	numeration::numeration(const uint32_t& _N) :
		number_(_N)
	{
	}

	numeration::numeration(const numeration& _N) :
		number_(_N.number_)
	{
	}

	numeration::numeration(uint32_t _Radix,
		const std::string& _S) :
		number_(0L)
	{
		set(_Radix, _S);
	}

	numeration::~numeration()
	{
	}

	const numeration& numeration::operator=(const numeration& _N)
	{
		number_ = _N.number_;
		return *this;
	}

	const numeration& numeration::operator=(const uint32_t& _N)
	{
		number_ = _N;
		return *this;
	}

	void numeration::operator+=(const numeration& _N)
	{
		number_ += _N.number_;
		return;
	}

	void numeration::operator-=(const numeration& _N)
	{
		number_ -= _N.number_;
		return;
	}

	void numeration::operator*=(const numeration& _N)
	{
		number_ *= _N.number_;
		return;
	}

	void numeration::operator/=(const numeration& _N)
	{
		number_ /= _N.number_;
		return;
	}

	numeration numeration::operator+(const numeration& _N)const
	{
		numeration n(number_ + _N.number_);
		return n;
	}

	numeration numeration::operator-(const numeration& _N)const
	{
		numeration n(number_ - _N.number_);
		return n;
	}

	numeration numeration::operator*(const numeration& _N)const
	{
		numeration n(number_ * _N.number_);
		return n;
	}

	numeration numeration::operator/(const numeration& _N)const
	{
		numeration n(number_ / _N.number_);
		return n;
	}

	bool numeration::operator==(const numeration& _N)const
	{
		return _N.number_ == number_;
	}

	bool numeration::operator!=(const numeration& _N)const
	{
		return !operator==(_N);
	}

	bool numeration::operator<=(const numeration& _N)const
	{
		return !operator>(_N);
	}

	bool numeration::operator>=(const numeration& _N)const
	{
		return !operator<(_N);
	}

	bool numeration::operator<(const numeration& _N)const
	{
		return _N.number_ < number_;
	}

	bool numeration::operator>(const numeration& _N)const
	{
		return _N.number_ > number_;
	}

	std::string numeration::to_string(uint32_t _Radix)const
	{
		if (!number_)
		{
			return "0";
		}
		std::string res;
		if (_Radix < 2 || _Radix > 36)
		{
			return res;
		}
		else if (_Radix >= 2 && _Radix <= 10)
		{
			uint32_t num = number_;
			while (num)
			{
				res.insert(0, 1, (char)('0' + num % _Radix));
				num /= _Radix;
			}
		}
		else
		{
			uint32_t num = number_;
			while (num)
			{
				uint32_t tmp_num = num % _Radix;
				uint8_t tmp_char =
					tmp_num < 10 ? '0' + tmp_num : 'A' + tmp_num - 10;
				res.insert(0, 1, (char)tmp_char);
				num /= _Radix;
			}
		}
		return res;
	}

	uint32_t numeration::to_uint32()
	{
		return number_;
	}

	bool numeration::set(uint32_t _N)
	{
		number_ = _N;
		return true;
	}

	bool numeration::set(uint32_t _Radix, const std::string& _S)
	{
		auto char_2_num = [=](char _C) ->int
		{
			if (_C >= '0' && _C <= '9')
			{
				return _C - '0';
			}
			else if (_C >= 'a' && _C <= 'z')
			{
				return _C - 'a' + 10;
			}
			else if (_C >= 'A' && _C <= 'Z')
			{
				return _C - 'A' + 10;
			}
			else
			{
				return -1;
			}
		};
		uint32_t res = 0;
		for (size_t i = 0; i < _S.size(); i++)
		{
			uint32_t tmp_num = char_2_num(_S.at(i));
			if (tmp_num == -1)
			{
				return false;
			}
			res = res * _Radix + tmp_num;
		}
		number_ = res;
		return true;
	}

}