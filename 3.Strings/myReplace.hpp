#ifndef MY_REPLACE
#define MY_REPLACE

#include <iostream>

template <typename T, typename S>
void myReplace(T&, T const&, T const&);


template <typename T>
void myReplace(T& source, T const& from, T const& to)
{
	std::size_t pos;
	std::size_t old_pos = 0;
	std::size_t toLength = to.length();
	std::size_t fromLength = from.length();

	while((pos = source.find(from, old_pos)) != T::npos)
	{
		old_pos =  pos + toLength;
		source.replace(pos, fromLength, to);
	};
}

#endif
