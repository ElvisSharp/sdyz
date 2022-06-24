#include <sdyz/exception/base_exception.hpp>

namespace sdyz
{
	std::ostream& operator<<(std::ostream& _Oerr,
		const base_exception& _Exception)
	{
		_Oerr << _Exception.what();
		return _Oerr;
	}
}