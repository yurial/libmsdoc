#ifndef CREFITH
#define CREFITH

#include "cref.h"

namespace libmsdoc
{
    namespace internal
    {
    template <class base>
    class CRefIterator:
        public base
    {
    public:
    typedef CRefIterator<base>                      self;

    typedef typename base::value_type::first_type   value_type;
    typedef typename base::difference_type          difference_type;
    typedef typename base::iterator_category        iterator_category;
    typedef const value_type*                       pointer;
    typedef pointer                                 const_pointer;
    typedef const value_type&                       reference;
    typedef reference                               const_reference;

    protected:
    friend class CRef;
    typedef typename base::value_type::second_type  refobj;

    refobj*     RefObj() const;

    void        Link();
    void        UnLink();


    public:
                CRefIterator();
                CRefIterator(const base& it);
                CRefIterator(const self& origin);
                ~CRefIterator();

    bool        empty() const;
    int         id() const;

    pointer     operator -> () const;
    reference   operator *  () const;

    self        operator ++ (int);
    self        operator -- (int);
    self&       operator ++ ();
    self&       operator -- ();

    self&       operator =  (const self& rvalue);
    bool        operator == (const self& rvalue) const;
    };

    template <class base>
    CRefIterator<base>::CRefIterator()
    {
    }

    template <class base>
    CRefIterator<base>::CRefIterator(const base& it):
        base( it )
    {
    Link();
    }
    
    template <class base>
    CRefIterator<base>::CRefIterator(const self& origin):
        base( origin )
    {
    Link();
    }

    template <class base>
    CRefIterator<base>::~CRefIterator()
    {
    UnLink();
    }

    template <class base>
    bool CRefIterator<base>::empty() const
    {
    return (NULL == base::_M_node) || (NULL == base::_M_node->_M_parent) || (base::_M_node != base::_M_node->_M_parent->_M_right && base::_M_node != base::_M_node->_M_parent->_M_left);
    }

    template <class base>
    typename CRefIterator<base>::refobj* CRefIterator<base>::RefObj() const
    {
    return &base::operator *().second;
    }

    template <class base>
    void CRefIterator<base>::Link()
    {
    if ( !empty() )
        {
        base::operator ->()->second.Link();
        }
    }

    template <class base>
    void CRefIterator<base>::UnLink()
    {
    if ( !empty() )
        {
        base::operator ->()->second.UnLink( *this );
        }
    }

    template <class base>
    int CRefIterator<base>::id() const
    {
    return base::operator -> () ->second.GetId();
    }

    template <class base>
    typename CRefIterator<base>::pointer CRefIterator<base>::operator -> () const
    {
    return &base::operator -> ()->first;
    }

    template <class base>
    typename CRefIterator<base>::reference CRefIterator<base>::operator * () const
    {
    return base::operator -> ()->first;
    }

    template <class base>
    CRefIterator<base> CRefIterator<base>::operator ++ (int)
    {
    self result( *this );
    UnLink();
    base::operator ++ ();
    Link();
    return result;
    }

    template <class base>
    CRefIterator<base> CRefIterator<base>::operator -- (int)
    {
    self result( *this );
    UnLink();
    base::operator -- ();
    Link();
    return result;
    }

    template <class base>
    CRefIterator<base>& CRefIterator<base>::operator ++ ()
    {
    base next = *this;
    ++next;
    UnLink();
    base::operator = ( next );
    Link();
    return *this;
    }

    template <class base>
    CRefIterator<base>& CRefIterator<base>::operator -- ()
    {
    base previous = *this;
    --previous;
    UnLink();
    base::operator = ( previous );
    Link();
    return *this;
    }

    template <class base>
    CRefIterator<base>& CRefIterator<base>::operator =  (const CRefIterator<base>& rvalue)
    {
    rvalue.Link();
    UnLink();
    base::operator = ( rvalue );
    return *this;
    }

    template <class base>
    bool CRefIterator<base>::operator == (const self& rvalue) const
    {
    bool allempty = empty() && rvalue.empty();
    return allempty || base::operator == ( rvalue );
    }

    }
}

#endif

