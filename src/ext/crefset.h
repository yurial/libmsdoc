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

#include "irefcontainer.h"
#include "cref.h"
#include "crefit.h"

namespace libmsdoc
{
    namespace internal
    {
    using std::pair;

    template <class Key, class Compare, class Allocator>
    class CRefSet:
        protected IRefContainer,
        protected std::map<Key, CRefObj< CRefSet< Key, Compare, Allocator > >, Compare, Allocator>
    {
    public:
    typedef CRefSet<Key,Compare,Allocator>          self;

    protected:
    typedef CRefObj<self>                           refobj;
    typedef std::map<Key,refobj,Compare,Allocator>  base;
    typedef typename base::iterator                 base_iterator;
    typedef typename base::const_iterator           base_const_iterator;

    public:
    typedef Key                                     key_type;
    typedef Key                                     value_type;
    typedef typename base::key_compare              key_compare;
    typedef typename base::key_compare              value_compare;
    typedef typename base::allocator_type           allocator_type;
    typedef CRef                                    ref;
    typedef CRefIterator<base_iterator>             iterator;
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
    pair<iterator,bool> insert(const Key& obj);
    iterator            find(const Key& obj) const;
    iterator            lower_bound(const Key& obj) const;
    iterator            upper_bound(const Key& obj) const;
    pair<iterator,iterator> equal_range(const Key& obj) const;

    protected:
    friend class CRefObj<self>;

    void                erase(base_iterator& it);
    void                erase(int id);
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
    pair<typename CRefSet<Key,Compare,Allocator>::iterator,bool> CRefSet<Key,Compare,Allocator>::insert(const Key& obj)
    {
    std::pair<base_iterator,bool> result = base::insert( std::make_pair( obj, refobj( this ) ) );
    base_iterator it = result.first;
    if ( result.second ) //new element
        {   
        it->second.SetId( distance( base::begin(), it ) );
        base_iterator pos = it;
        base_iterator endpos = base::end();
        while( ++pos != endpos )
            {   
            pos->second.IncId();
            }   
        }   
    return pair<iterator,bool>( it, result.second );
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
        pos->second.DecId();
        }
    base::erase( it );
    }

    template <class Key, class Compare, class Allocator>
    void CRefSet<Key,Compare,Allocator>::erase(int id)
    {
    base_iterator it = base::begin();
    advance( it, id );
    erase( it );
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
    pair<typename CRefSet<Key,Compare,Allocator>::iterator, typename CRefSet<Key,Compare,Allocator>::iterator> CRefSet<Key,Compare,Allocator>::equal_range(const Key& obj) const
    {
    self* pthis = const_cast<self*>( this );
    const base* pbase = this;
    pair<base_iterator,base_iterator> result = const_cast<base*>( pbase )->equal_range( obj );
    return std::make_pair( iterator( pthis, result.first ), iterator( pthis, result.second ) );
    }

    }
}

#endif

