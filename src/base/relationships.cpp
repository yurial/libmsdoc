#include "crelationship.h"

namespace base
{

irelationship::iralationship(relationships* rels):
    m_reationship( rels->insert( this ) )
{
}

int irelationship::rid() const
{
return m_relationship.id();
}

void relationships::save(zip& archive, const string& filename) const throw(exception)
{
std::stringstream content;
content << "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\"?>\n";
content << "<Relationships xmlns=\"http://schemas.openxmlformats.org/package/2006/relationships\">\n";
base::const_iterator it = base::begin();
base::const_iterator end = base::end();
for (;it != end; ++it)
    {   
    content << "<Relationship Id=\"rId" << it->rid() << "\" Type=\"" << g_contenttypes[it->type()].m_relationship << "\" Target=\"/" << it->filename() << "\"/>\n";
    }   
content << "</Relationships>";
archive.add_file( filename, content.str() );
//TODO:ret exception
}

}//namespace base

