#include "doc.h"
#include "base/content.h"
#include "base/relationships.h"

namespace excel
{

doc::doc()//:
    //m_workbook( "xl", base::m_relationships )
{
}

int doc::save(const string& filename) const throw(exception)
{
/*
ext::zip archive( filename );
TContent content;
m_workbook.save( archive, content );
content.save( archive );
archive.add_dir( "_rels" );
m_relationships.save( archive, "_rels/.rels" );
return ret;
*/
}

}//namespace excel

