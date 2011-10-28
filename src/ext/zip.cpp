#include <string.h>
#include "zip.h"
/*
namespace ext
{

zip::zip() throw():
    m_archive( NULL )
{
}

zip::zip(const string& filename) throw(exception)
{
open( filename );
}

zip::~zip() throw(exception)
{
if ( NULL != m_archive )
    {
    int ret = libzip::zip_close( m_archive );
    if ( -1 == ret )
        {
        throw exception( "can't close archive" );
        }
    }
}

void zip::open(const string& filename) throw(exception)
{
int ret = 0;
m_archive = libzip::zip_open( filename.c_str(), ZIP_CREATE, &ret );
if (NULL == m_archive)
    {
    throw exception( "can't create archive" );
    }
}

void zip::add_dir(const string& dir) throw(exception)
{
int ret = libzip::zip_add_dir( m_archive, dir.c_str() );
if ( -1 == ret )
    {
    throw exception( "can't add dir" );
    }
}

void zip::add_file(const string& filename, const string& buff) throw(exception)
{
char* dynamic_buff = new char [ buff.size() ];
memcpy( dynamic_buff, buff.c_str(), buff.size() );
libzip::zip_source* source = libzip::zip_source_buffer( m_archive, dynamic_buff, buff.size(), 1 );
if ( NULL == source )
    {
    delete []dynamic_buff;
    throw exception( "can't allocate zip buffer" );
    }
int ret = libzip::zip_add( m_archive, filename.c_str(), source );
if ( -1 == ret )
    {
    libzip::zip_source_free( source );
    throw exception( "can't add file" );
    }
}

}//namespace ext
*/
