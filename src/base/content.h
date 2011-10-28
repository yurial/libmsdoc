#ifndef CCONTENTTYPEH
#define CCONTENTTYPEH

#include <map>
#include <list>

#include "ext/string.h"
#include "ext/zip.h"

namespace base
{
using namespace ext;

struct content
{
enum type
{
workbook,                           //12.3.23
worksheet,                          //12.3.24
shared_string_table,                //12.3.15
styles,                             //12.3.20
drawings,                           //12.3.8
chartsheet,                         //12.3.2
external_workbook_reference,        //12.3.9
calculation_chain,                  //12.3.1
comments,                           //12.3.3
connections,                        //12.3.4
custom_property,                    //12.4.5
custom_xml_mappings,                //12.3.6
dialogsheet,                        //12.3.7
metadata,                           //12.3.10
query_table,                        //12.3.14
pivot_table,                        //12.3.11
pivot_table_cache_definition,       //12.3.12
pivot_table_cache_reords,           //12.3.13
shared_workbook_user_data,          //12.3.18
shared_workbook_revision_headers,   //12.3.16
shared_workbook_revision_log,       //12.3.17
single_cell_table_definitions,      //12.3.19
table_definition,                   //12.3.21
volatile_dependencies,              //12.3.22
};
};

struct SContentType
{
content::type   m_id;
string          m_type;
string          m_namespace;
string          m_relationship;
};

typedef std::map<content::type,SContentType> TContentTypes;
extern TContentTypes g_contenttypes;

struct SContentObject
{
string          m_filename;
content::type   m_type;
                SContentObject(const string& filename, content::type type);
};

class CContent:
    protected std::list<SContentObject>
{
protected:
typedef std::list<SContentObject> base;

public:
void    insert(const string& filename, content::type type);
int     save(zip& archive) const;
};

}//namespace base

#endif

