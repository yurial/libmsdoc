#ifndef CREFMAPH
#define CREFMAPH

#include <map>

namespace libmsdoc
{
    namespace internal
    {
    template < class Key, class Compare = std::less<Key>, class Allocator = std::allocator<Key> > class CRefSet;
    }
}

#include "cref.h"

namespace libmsdoc
{
    namespace internal
    {
    template <class T>
    struct SRefObj
    {
    protected:
    int     m_refs;
    T*      m_container;

    public:
    typedef typename T::iterator iterator;
    int     m_id;

            SRefObj(T* container);
    void    Link();
    void    UnLink(iterator& it);
    };

    template <class T>
    SRefObj<T>::SRefObj(T* container):
            m_id( 0 ), m_refs( 0 ), m_container( container )
    {
    }

    template <class T>
    void SRefObj<T>::Link()
    {
    ++m_refs;
    }

    template <class T>
    void SRefObj<T>::UnLink(iterator& it)
    {
    --m_refs;
    if ( 0 == m_refs )
        {
        m_container->erase( it );
        }
    }

    template <class Key, class Compare, class Allocator>
    class CRefSet:
        protected std::map<Key, SRefObj< CRefSet< Key > >, Compare, Allocator>
    {
    public:
    typedef CRefSet<Key,Compare,Allocator>          self;

    protected:
    typedef SRefObj<self>                           refobj;
    typedef std::map<Key,refobj,Compare,Allocator>  base;
    typedef typename base::iterator                 base_iterator;
    typedef typename base::const_iterator           base_const_iterator;

    public:
    typedef Key                                     key_type;
    typedef Key                                     value_type;
    typedef typename base::key_compare              key_compare;
    typedef typename base::key_compare              value_compare;
    typedef typename base::allocator_type           allocator_type;
    typedef CRef<base_iterator>                     iterator;
    typedef iterator                                const_iterator;
    typedef typename iterator::reference            reference;
    typedef typename iterator::const_reference      const_reference;
    typedef typename iterator::pointer              pointer;
    typedef typename iterator::const_pointer        const_pointer;
    typedef typename base::size_type                size_type;
    typedef typename iterator::difference_type      difference_type;

    using base::key_comp;
    using base::value_comp;

    using base::empty;
    using base::size;
    using base::max_size;
    using base::clear;
    using base::count;

    iterator            begin() const;
    iterator            end() const;
    iterator            insert(const Key& obj);
    iterator            find(const Key& obj) const;
    iterator            lower_bound(const Key& obj) const;
    iterator            upper_bound(const Key& obj) const;
    std::pair<iterator,iterator> equal_range(const Key& obj) const;

    protected:
    friend class SRefObj<self>;
    void                erase(base_iterator& it);
    };

    template <class Key, class Compare, class Allocator>
    typename CRefSet<Key,Compare,Allocator>::iterator CRefSet<Key,Compare,Allocator>::begin() const
    {
    const base* pbase = this;
    return iterator( const_cast<base*>( pbase )->begin() );
    }

    template <class Key, class Compare, class Allocator>
    typename CRefSet<Key,Compare,Allocator>::iterator CRefSet<Key,Compare,Allocator>::end() const
    {
    const base* pbase = this;
    return iterator( const_cast<base*>( pbase )->end() ); 
    }

    template <class Key, class Compare, class Allocator>
    typename CRefSet<Key,Compare,Allocator>::iterator CRefSet<Key,Compare,Allocator>::insert(const Key& obj)
    {
    std::pair<base_iterator,bool> result = base::insert( std::make_pair( obj, refobj( this ) ) );
    base_iterator it = result.first;
    if ( result.second ) //new element
        {   
        it->second.m_id = distance( base::begin(), it );
        base_iterator pos = it;
        base_iterator endpos = base::end();
        while( ++pos != endpos )
            {   
            ++(pos->second.m_id);
            }   
        }   
    return iterator( it );
    }

    template <class Key, class Compare, class Allocator>
    void CRefSet<Key,Compare,Allocator>::erase(base_iterator& it)
    {
    if ( base::begin() == it )
        {   
        return;
        }
    base_iterator pos = it;
    base_iterator endpos = base::end();
    while ( ++pos != endpos )
        {
        --(pos->second.m_id);
        }
    base::erase( it );
    }

    template <class Key, class Compare, class Allocator>
    typename CRefSet<Key,Compare,Allocator>::iterator CRefSet<Key,Compare,Allocator>::find(const Key& obj) const
    {
    const base* pbase = this;
    return iterator( const_cast<self*>(this), const_cast<base*>(pbase)->find( obj ) );
    }

    template <class Key, class Compare, class Allocator>
    typename CRefSet<Key,Compare,Allocator>::iterator CRefSet<Key,Compare,Allocator>::lower_bound(const Key& obj) const
    {
    const base* pbase = this;
    return iterator( const_cast<self*>(this), const_cast<base*>(pbase)->lower_bound( obj ) );
    }

    template <class Key, class Compare, class Allocator>
    typename CRefSet<Key,Compare,Allocator>::iterator CRefSet<Key,Compare,Allocator>::upper_bound(const Key& obj) const
    {
    const base* pbase = this;
    return iterator( const_cast<self*>(this), const_cast<base*>(pbase)->upper_bound( obj ) );
    }

    template <class Key, class Compare, class Allocator>
    std::pair<typename CRefSet<Key,Compare,Allocator>::iterator, typename CRefSet<Key,Compare,Allocator>::iterator> CRefSet<Key,Compare,Allocator>::equal_range(const Key& obj) const
    {
    self* pthis = const_cast<self*>( this );
    const base* pbase = this;
    std::pair<base_iterator,base_iterator> result = const_cast<base*>( pbase )->equal_range( obj );
    return std::make_pair( iterator( pthis, result.first ), iterator( pthis, result.second ) );
    }

    }
}

#endif

