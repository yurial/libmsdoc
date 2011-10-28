namespace ext
{
namespace ref
{

template <class base>
iterator<base>::iterator()
{
}

template <class base>
iterator<base>::iterator(const base& it):
    base( it )
{
link();
}

template <class base>
iterator<base>::iterator(const self& origin):
    base( origin )
{
link();
}

template <class base>
iterator<base>::~iterator()
{
unlink();
}

template <class base>
void iterator<base>::link() const
{
if ( !empty() )
    {
    obj()->link();
    }
}

template <class base>
void iterator<base>::unlink() const
{
if ( !empty() )
    {
    obj()->unlink( *this );
    }
}

template <class base>
int iterator<base>::id() const
{
return ( empty() )? -1 : obj()->id();
}

template <class base>
iterator<base> iterator<base>::operator ++ (int)
{
self result( *this );
unlink();
base::operator ++ ();
link();
return result;
}

template <class base>
iterator<base> iterator<base>::operator -- (int)
{
self result( *this );
unlink();
base::operator -- ();
link();
return result;
}

template <class base>
iterator<base>& iterator<base>::operator ++ ()
{
base next = *this;
++next;
unlink();
base::operator = ( next );
link();
return *this;
}

template <class base>
iterator<base>& iterator<base>::operator -- ()
{
base previous = *this;
--previous;
unlink();
base::operator = ( previous );
link();
return *this;
}

template <class base>
iterator<base>& iterator<base>::operator =  (const iterator<base>& rvalue)
{
rvalue.link();
unlink();
base::operator = ( rvalue );
return *this;
}

template <class base>
bool iterator<base>::operator == (const self& rvalue) const
{
bool allempty = empty() && rvalue.empty();
return allempty || base::operator == ( rvalue );
}

}//namespace ref
}//namespace ext
