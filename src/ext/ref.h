#ifndef EXT_REFH
#define EXT_REFH

#include "refit.h"

namespace ext
{
namespace ref
{

class reference
{
protected:
baseobj*        m_refobj;
void            link();
void            unlink();

public:
typedef reference   self;

inline              reference();
                    template <class base>
inline              reference(iterator<base>& it);
inline              ~reference();

inline  bool        empty() const;
inline  int         id() const;

        self&       operator =  (const self& rvalue);
inline  bool        operator == (const self& rvalue) const;
};

reference::reference():
    m_refobj( NULL )
{
}

template <class base>
reference::reference(iterator<base>& it):
    m_refobj( it.refobj() )
{
link();
}

reference::~reference()
{
unlink();
}

bool reference::empty() const
{
return NULL == m_refobj;
}

void reference::link()
{
if ( !empty() )
    {
    m_refobj->link();
    }
}

void reference::unlink()
{
if ( !empty() )
    {
    m_refobj->unlink();
    }
}

int reference::id() const
{
return ( empty() )? -1 : m_refobj->id();
}

reference& reference::operator =  (const reference& rvalue)
{
baseobj* newrefobj = rvalue.m_refobj;
if ( NULL != newrefobj )
    {
    newrefobj->link();
    }
unlink();
m_refobj = newrefobj;
return *this;
}

bool reference::operator == (const self& rvalue) const
{
return rvalue.m_refobj == m_refobj;
}

}//namespace ref
}//namespace ext

#endif

