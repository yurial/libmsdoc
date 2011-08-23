#ifndef CREFH
#define CREFH

namespace libmsdoc
{
    namespace internal
    {
    template <class base>
    class CRef:
        public base
    {
    protected:
    void        Link();
    void        UnLink();

    public:
    typedef CRef<base>                              self;

    typedef typename base::value_type::first_type   value_type;
    typedef typename base::difference_type          difference_type;
    typedef typename base::iterator_category        iterator_category;
    typedef const value_type*                       pointer;
    typedef pointer                                 const_pointer;
    typedef const value_type&                       reference;
    typedef reference                               const_reference;

                CRef();
                CRef(const base& it);
                CRef(const self& origin);
                ~CRef();

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
    CRef<base>::CRef()
    {
    }

    template <class base>
    CRef<base>::CRef(const base& it):
        base( it )
    {
    Link();
    }
    
    template <class base>
    CRef<base>::CRef(const self& origin):
        base( origin )
    {
    Link();
    }

    template <class base>
    CRef<base>::~CRef()
    {
    UnLink();
    }

    template <class base>
    bool CRef<base>::empty() const
    {
    return (NULL == base::_M_node) || (NULL == base::_M_node->_M_parent) || (base::_M_node != base::_M_node->_M_parent->_M_right && base::_M_node != base::_M_node->_M_parent->_M_left);
    }

    template <class base>
    void CRef<base>::Link()
    {
    if ( !empty() )
        {
        base::operator ->()->second.Link();
        }
    }

    template <class base>
    void CRef<base>::UnLink()
    {
    if ( !empty() )
        {
        base::operator ->()->second.UnLink( *this );
        }
    }

    template <class base>
    int CRef<base>::id() const
    {
    return base::operator -> () ->second.m_id;
    }

    template <class base>
    typename CRef<base>::pointer CRef<base>::operator -> () const
    {
    return &base::operator -> ()->first;
    }

    template <class base>
    typename CRef<base>::reference CRef<base>::operator * () const
    {
    return base::operator -> ()->first;
    }

    template <class base>
    CRef<base> CRef<base>::operator ++ (int)
    {
    self result( *this );
    UnLink();
    base::operator ++ ();
    Link();
    return result;
    }

    template <class base>
    CRef<base> CRef<base>::operator -- (int)
    {
    self result( *this );
    UnLink();
    base::operator -- ();
    Link();
    return result;
    }

    template <class base>
    CRef<base>& CRef<base>::operator ++ ()
    {
    base next = *this;
    ++next;
    UnLink();
    base::operator = ( next );
    Link();
    return *this;
    }

    template <class base>
    CRef<base>& CRef<base>::operator -- ()
    {
    base previous = *this;
    --previous;
    UnLink();
    base::operator = ( previous );
    Link();
    return *this;
    }

    template <class base>
    CRef<base>& CRef<base>::operator =  (const CRef<base>& rvalue)
    {
    rvalue.Link();
    UnLink();
    base::operator = ( rvalue );
    return *this;
    }

    template <class base>
    bool CRef<base>::operator == (const self& rvalue) const
    {
    bool allempty = empty() && rvalue.empty();
    return allempty || base::operator == ( rvalue );
    }

    }
}

#endif

