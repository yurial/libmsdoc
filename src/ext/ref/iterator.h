#ifndef EXT_REF_ITERATORH
#define EXT_REF_ITERATORH

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

}//namespace ref
}//namespace ext

#include "iterator.inc"

#endif

