#ifndef EXT_REF_REFOBJH
#define EXT_REF_REFOBJH

namespace ext
{
namespace ref
{
class baseobj;
template <class Container> class refobj;
}//namespace ref
}//namespace ext

#include "interface.h"
#include "iterator.h"

namespace ext
{
namespace ref
{

class baseobj
{
protected:
int                 m_id;
int                 m_refs;
icontainer*         m_container;

public:
inline              baseobj(icontainer* container);

inline  int&        id();
inline  const int&  id() const;

inline  void        link();
inline  void        unlink();
};

template <class Container>
class refobj:
    public baseobj
{
protected:
typedef baseobj                         base;
typedef typename Container::iterator    iterator;

public:
        refobj(Container* container);

inline  void    unlink(const iterator& it);
};

}//namespace ref
}//namespace ext

#include "refobj.inc"

#endif

