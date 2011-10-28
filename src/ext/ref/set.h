#ifndef EXT_REF_SETH
#define EXT_REF_SETH

#include <map>

namespace ext
{
namespace ref
{
template < class Key, class Compare = std::less<Key>, class Allocator = std::allocator<Key> > class set;
}
}

#include "interface.h"
#include "iterator.h"
#include "reference.h"
#include "refobj.h"

namespace ext
{
namespace ref
{

template <class Key, class Compare, class Allocator>
class set:
    protected icontainer,
    protected std::map<Key, refobj< set< Key, Compare, Allocator > >, Compare, Allocator>
{
protected:
typedef set<Key,Compare,Allocator>          self;
typedef refobj<self>                            refobj_type;
typedef std::map<Key,refobj_type,Compare,Allocator>  base;
typedef typename base::iterator                 base_iterator;
typedef typename base::const_iterator           base_const_iterator;

public:
typedef Key                                     key_type;
typedef Key                                     value_type;
typedef typename base::key_compare              key_compare;
typedef typename base::key_compare              value_compare;
typedef typename base::allocator_type           allocator_type;
typedef typename base_iterator::difference_type difference_type;
typedef value_type&                             reference;
typedef const value_type&                       const_reference;
typedef value_type*                             pointer;
typedef const value_type*                       const_pointer;
typedef typename base::size_type                size_type;

template <class T>
class template_iterator:
    public T
{
protected:
typedef typename T::value_type          pair_type;
typedef typename pair_type::second_type refobj_type;
using T::_M_node;
refobj_type*                            obj() const;

public:
typedef typename T::difference_type     difference_type;
typedef typename pair_type::first_type  value_type;
typedef const value_type&               const_reference;
typedef const_reference                 reference;
typedef const value_type*               const_pointer;
typedef const_pointer                   pointer;

            template_iterator();
            template_iterator(const T& origin);
            template_iterator(const template_iterator& origin);
bool        empty() const;
reference   operator *  () const;
pointer     operator -> () const;
};

typedef template_iterator<base_iterator>         iterator;
typedef template_iterator<base_const_iterator>   const_iterator;

typedef ref::iterator<iterator>         refit;

using base::key_comp;
using base::value_comp;

using base::empty;
using base::size;
using base::max_size;
using base::clear;
using base::count;

iterator                                    begin();
iterator                                    end();
const_iterator                              begin() const;
const_iterator                              end() const;
std::pair<iterator,bool>                    insert(const Key& obj);
iterator                                    find(const Key& obj);
iterator                                    lower_bound(const Key& obj);
iterator                                    upper_bound(const Key& obj);
std::pair<iterator,iterator>                equal_range(const Key& obj);
const_iterator                              find(const Key& obj) const;
const_iterator                              lower_bound(const Key& obj) const;
const_iterator                              upper_bound(const Key& obj) const;
std::pair<const_iterator,const_iterator>    equal_range(const Key& obj) const;

protected:
friend class refobj<self>;

void                erase(const base_iterator& it);
void                erase(int id);
};

}//namespace ref
}//namespace ext

#include "set.inc"

#endif

