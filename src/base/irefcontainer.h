#ifndef IREFCONTAINERH
#define IREFCONTAINERH

namespace libmsdoc
{
    namespace internal
    {

    class IRefContainer;
    class CRefObjBase;
    template <class Container> class CRefObj;

    class IRefContainer
    {
    public:
    virtual void    erase(int id) = 0;
    };

    class CRefObjBase
    {
    protected:
    int             m_id;
    int             m_refs;
    IRefContainer*  m_container;

    public:

                    CRefObjBase(IRefContainer* container);

    inline  void    SetId(int id);
    inline  int     GetId() const;

    inline  void    IncId();
    inline  void    DecId();

    inline  void    Link();
    inline  void    UnLink();
    };

    CRefObjBase::CRefObjBase(IRefContainer* container):
        m_id( 0 ), m_refs( 0 ), m_container( container )
    {
    }

    void CRefObjBase::SetId(int id)
    {
    m_id = id;
    }

    int CRefObjBase::GetId() const
    {
    return m_id;
    }

    void CRefObjBase::IncId()
    {
    ++m_id;
    }

    void CRefObjBase::DecId()
    {
    --m_id;
    }

    void CRefObjBase::Link()
    {
    ++m_refs;
    }

    void CRefObjBase::UnLink()
    {
    --m_refs;
    if ( 0 == m_refs )
        {
        m_container->erase( m_id );
        }
    }

    template <class Container>
    class CRefObj:
        public CRefObjBase
    {
    protected:
    typedef CRefObjBase base;
    typedef typename Container::iterator iterator;

    using   base::m_refs;

    public:
            CRefObj(Container* container);
    using   base::SetId;
    using   base::GetId;
    using   base::IncId;
    using   base::DecId;
    using   base::Link;
    using   base::UnLink;

    void    UnLink(iterator& it);
    };
    
    template <class Container>
    CRefObj<Container>::CRefObj(Container* container):
        base( container )
    {
    }

    template <class Container>
    void CRefObj<Container>::UnLink(iterator& it)
    {
    --m_refs;
    if ( 0 == m_refs )
        {
        ((Container*)m_container)->erase( it );
        }
    }

    }
}

#endif

