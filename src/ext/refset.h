#ifndef EXT_REFMAPH
#define EXT_REFMAPH

#include <map>

namespace ext
{
namespace ref
{
template < class Key, class Compare = std::less<Key>, class Allocator = std::allocator<Key> > class set;
}
}

#include "iref.h"
#include "ref.h"
#include "refit.h"

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

template <class Key, class Compare, class Allocator>
template <class T>
set<Key,Compare,Allocator>::template_iterator<T>::template_iterator()
{
}

template <class Key, class Compare, class Allocator>
template <class T>
set<Key,Compare,Allocator>::template_iterator<T>::template_iterator(const template_iterator& origin):
    T( origin )
{
}

template <class Key, class Compare, class Allocator>
template <class T>
set<Key,Compare,Allocator>::template_iterator<T>::template_iterator(const T& origin):
    T( origin )
{
}

template <class Key, class Compare, class Allocator>
template <class T>
typename set<Key,Compare,Allocator>::template template_iterator<T>::refobj_type* set<Key,Compare,Allocator>::template_iterator<T>::obj () const
{
return &((T::operator *()).second);
}

template <class Key, class Compare, class Allocator>
template <class T>
bool set<Key,Compare,Allocator>::template_iterator<T>::empty() const
{
bool node = (NULL != _M_node);
bool parent = node && (NULL != _M_node->_M_parent);
bool left = node && (NULL != _M_node->_M_left);
bool right = node && (NULL != _M_node->_M_right);
bool parent_pointed = parent && (_M_node == _M_node->_M_parent->_M_left || _M_node == _M_node->_M_parent->_M_right);
bool childs_pointed = (left && _M_node == _M_node->_M_left->_M_parent) || (right && _M_node == _M_node->_M_right->_M_parent);
return !node || !parent || !(parent_pointed || childs_pointed);
}

template <class Key, class Compare, class Allocator>
template <class T>
typename set<Key,Compare,Allocator>::template template_iterator<T>::reference set<Key,Compare,Allocator>::template_iterator<T>::operator *  () const
{
return (T::operator *().first);
}

template <class Key, class Compare, class Allocator>
template <class T>
typename set<Key,Compare,Allocator>::template template_iterator<T>::pointer set<Key,Compare,Allocator>::template_iterator<T>::operator -> () const
{
return &(T::operator *().first);
}

template <class Key, class Compare, class Allocator>
typename set<Key,Compare,Allocator>::iterator set<Key,Compare,Allocator>::begin()
{
return base::begin();
}

template <class Key, class Compare, class Allocator>
typename set<Key,Compare,Allocator>::iterator set<Key,Compare,Allocator>::end()
{
return base::end();
}

template <class Key, class Compare, class Allocator>
typename set<Key,Compare,Allocator>::const_iterator set<Key,Compare,Allocator>::begin() const
{
return base::begin();
}

template <class Key, class Compare, class Allocator>
typename set<Key,Compare,Allocator>::const_iterator set<Key,Compare,Allocator>::end() const
{
return base::end();
}

template <class Key, class Compare, class Allocator>
std::pair<typename set<Key,Compare,Allocator>::iterator,bool> set<Key,Compare,Allocator>::insert(const Key& obj)
{
std::pair<base_iterator,bool> result = base::insert( std::make_pair( obj, refobj<self>( this ) ) );
base_iterator it = result.first;
if ( result.second ) //new element
    {   
    it->second.id() = distance( base::begin(), it );
    base_iterator pos = it;
    base_iterator endpos = base::end();
    while( ++pos != endpos )
        {   
        ++( pos->second.id() );
        }   
    }   
return std::pair<iterator,bool>( it, result.second );
}

template <class Key, class Compare, class Allocator>
void set<Key,Compare,Allocator>::erase(const base_iterator& it)
{
if ( base::begin() == it )
    {   
    return;
    }
base_iterator pos = it;
base_iterator endpos = base::end();
while ( ++pos != endpos )
    {
    --( pos->second.id() );
    }
base::erase( it );
}

template <class Key, class Compare, class Allocator>
void set<Key,Compare,Allocator>::erase(int id)
{
base_iterator it = base::begin();
advance( it, id );
erase( it );
}

template <class Key, class Compare, class Allocator>
typename set<Key,Compare,Allocator>::iterator set<Key,Compare,Allocator>::find(const Key& obj)
{
return base::find( obj );
}

template <class Key, class Compare, class Allocator>
typename set<Key,Compare,Allocator>::iterator set<Key,Compare,Allocator>::lower_bound(const Key& obj)
{
return base::lower_bound( obj );
}

template <class Key, class Compare, class Allocator>
typename set<Key,Compare,Allocator>::iterator set<Key,Compare,Allocator>::upper_bound(const Key& obj)
{
return base::upper_bound( obj );
}

template <class Key, class Compare, class Allocator>
std::pair<typename set<Key,Compare,Allocator>::iterator, typename set<Key,Compare,Allocator>::iterator> set<Key,Compare,Allocator>::equal_range(const Key& obj)
{
std::pair<base_iterator,base_iterator> result = base::equal_range( obj );
return std::pair<iterator,bool>( result.first, result.second );
}

template <class Key, class Compare, class Allocator>
typename set<Key,Compare,Allocator>::const_iterator set<Key,Compare,Allocator>::find(const Key& obj) const
{
return base::find( obj );
}

template <class Key, class Compare, class Allocator>
typename set<Key,Compare,Allocator>::const_iterator set<Key,Compare,Allocator>::lower_bound(const Key& obj) const
{
return base::lower_bound( obj );
}

template <class Key, class Compare, class Allocator>
typename set<Key,Compare,Allocator>::const_iterator set<Key,Compare,Allocator>::upper_bound(const Key& obj) const
{
return base::upper_bound( obj );
}

template <class Key, class Compare, class Allocator>
std::pair<typename set<Key,Compare,Allocator>::const_iterator, typename set<Key,Compare,Allocator>::const_iterator> set<Key,Compare,Allocator>::equal_range(const Key& obj) const
{
std::pair<base_iterator,base_iterator> result = base::equal_range( obj );
return std::pair<const_iterator,bool>( result.first, result.second );
}

}//namespace ref
}//namespace ext

#endif

