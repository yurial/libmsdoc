#ifndef EXT_INITIALIZERH
#define EXT_INITIALIZERH

namespace ext
{

class initializer
{
public:
typedef void (*func_type)();
inline initializer(func_type func)
    {
    func();
    }
};

}//namespace ext

#endif

