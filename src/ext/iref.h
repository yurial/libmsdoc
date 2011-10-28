#ifndef EXT_IREFH
#define EXT_IREFH

namespace ext
{
namespace ref
{
template <class Container> class refobj;

class icontainer
{
public:
virtual void    erase(int id) = 0;
};

class baseobj
{
protected:
int                 m_id;
int                 m_refs;
icontainer*         m_container;

public:
                    baseobj(icontainer* container);

inline  int&        id();
inline  const int&  id() const;

inline  void        link();
inline  void        unlink();
};

baseobj::baseobj(icontainer* container):
    m_id( 0 ), m_refs( 0 ), m_container( container )
{
}

int& baseobj::id()
{
return m_id;
}

const int& baseobj::id() const
{
return m_id;
}

void baseobj::link()
{
++m_refs;
}

void baseobj::unlink()
{
--m_refs;
if ( 0 == m_refs )
    {
    m_container->erase( m_id );
    }
}

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

template <class Container>
refobj<Container>::refobj(Container* container):
    base( container )
{
}

template <class Container>
void refobj<Container>::unlink(const iterator& it)
{
--m_refs;
if ( 0 == m_refs )
    {
    static_cast<Container*>( m_container )->erase( it );
    }
}

}//namespace ref
}//namespace ext

#endif

