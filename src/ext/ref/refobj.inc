namespace ext
{
namespace ref
{

baseobj::baseobj(icontainer* container):
    m_id( 0 ), m_refs( 0 ), m_container( container )
{
}

int& baseobj::id()
{
return m_id;
}

const int& baseobj::id() const
{
return m_id;
}

void baseobj::link()
{
++m_refs;
}

void baseobj::unlink()
{
--m_refs;
if ( 0 == m_refs )
    {
    m_container->erase( m_id );
    }
}

template <class Container>
refobj<Container>::refobj(Container* container):
    base( container )
{
}

template <class Container>
void refobj<Container>::unlink(const iterator& it)
{
--m_refs;
if ( 0 == m_refs )
    {
    static_cast<Container*>( m_container )->erase( it );
    }
}

}//namespace ref
}//namespace ext

