#ifndef EXT_REFITH
#define EXT_REFITH

#include "ref.h"

namespace ext
{
namespace ref
{

template <class base>
class iterator:
    public base
{
public:
typedef iterator<base>                          self;

typedef typename base::value_type               value_type;
typedef typename base::difference_type          difference_type;
typedef typename base::iterator_category        iterator_category;
typedef const value_type*                       pointer;
typedef pointer                                 const_pointer;
typedef const value_type&                       reference;
typedef reference                               const_reference;

protected:
friend class ref;

using base::obj;
void        link() const;
void        unlink() const;

public:
using base::empty;
            iterator();
            iterator(const base& it);
            iterator(const self& origin);
            ~iterator();

int         id() const;

self        operator ++ (int);
self        operator -- (int);
self&       operator ++ ();
self&       operator -- ();

self&       operator =  (const self& rvalue);
bool        operator == (const self& rvalue) const;
};

template <class base>
iterator<base>::iterator()
{
}

template <class base>
iterator<base>::iterator(const base& it):
    base( it )
{
link();
}

template <class base>
iterator<base>::iterator(const self& origin):
    base( origin )
{
link();
}

template <class base>
iterator<base>::~iterator()
{
unlink();
}

template <class base>
void iterator<base>::link() const
{
if ( !empty() )
    {
    obj()->link();
    }
}

template <class base>
void iterator<base>::unlink() const
{
if ( !empty() )
    {
    obj()->unlink( *this );
    }
}

template <class base>
int iterator<base>::id() const
{
return ( empty() )? -1 : obj()->id();
}

template <class base>
iterator<base> iterator<base>::operator ++ (int)
{
self result( *this );
unlink();
base::operator ++ ();
link();
return result;
}

template <class base>
iterator<base> iterator<base>::operator -- (int)
{
self result( *this );
unlink();
base::operator -- ();
link();
return result;
}

template <class base>
iterator<base>& iterator<base>::operator ++ ()
{
base next = *this;
++next;
unlink();
base::operator = ( next );
link();
return *this;
}

template <class base>
iterator<base>& iterator<base>::operator -- ()
{
base previous = *this;
--previous;
unlink();
base::operator = ( previous );
link();
return *this;
}

template <class base>
iterator<base>& iterator<base>::operator =  (const iterator<base>& rvalue)
{
rvalue.link();
unlink();
base::operator = ( rvalue );
return *this;
}

template <class base>
bool iterator<base>::operator == (const self& rvalue) const
{
bool allempty = empty() && rvalue.empty();
return allempty || base::operator == ( rvalue );
}

}//namespace ref
}//namespace ext

#endif

