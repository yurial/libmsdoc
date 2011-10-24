#ifndef CREFH
#define CREFH


namespace libmsdoc
{
    namespace internal
    {
    class CRef;
    }

typedef internal::CRef TRef;
}

#include "crefit.h"

namespace libmsdoc
{
    namespace internal
    {

    class CRef
    {
    protected:
    CRefObjBase*    m_refobj;
    void            Link();
    void            UnLink();

    public:
    typedef CRef    self;

                    CRef();
                    template <class base>
                    CRef(CRefIterator<base>& it);
                    ~CRef();

    bool            empty() const;
    int             id() const;

    self&           operator =  (const self& rvalue);
    bool            operator == (const self& rvalue) const;
    };

    CRef::CRef():
        m_refobj( NULL )
    {
    }

    template <class base>
    CRef::CRef(CRefIterator<base>& it):
        m_refobj( it.RefObj() )
    {
    Link();
    }

    CRef::~CRef()
    {
    UnLink();
    }

    bool CRef::empty() const
    {
    return NULL == m_refobj;
    }

    void CRef::Link()
    {
    if ( !empty() )
        {
        m_refobj->Link();
        }
    }

    void CRef::UnLink()
    {
    if ( !empty() )
        {
        m_refobj->UnLink();
        }
    }

    int CRef::id() const
    {
    return ( empty() )? -1 : m_refobj->GetId();
    }

    CRef& CRef::operator =  (const CRef& rvalue)
    {
    CRefObjBase* newrefobj = rvalue.m_refobj;
    if ( NULL != newrefobj )
        {
        newrefobj->Link();
        }
    UnLink();
    m_refobj = newrefobj;
    return *this;
    }

    bool CRef::operator == (const self& rvalue) const
    {
    return rvalue.m_refobj == m_refobj;
    }

    }
}

#endif

