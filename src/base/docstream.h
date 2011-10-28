#ifndef DOCSTREAMH
#define DOCSTREAMH

#include <sstream>

namespace base
{
class docstream:
    public std::stringstream
{
public:
template <class T>
docstream&  operator << (const T& obj);
};

}//namespace base

#endif

