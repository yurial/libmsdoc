namespace ext
{
namespace ref
{
//set::template_iterator

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

//set

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

