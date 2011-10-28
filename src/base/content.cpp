#include <sstream>

#include "content.h"
#include "ext/initializer.h"

namespace base
{

SContentType CONTENT_TYPES[] = {
    { workbook,                         "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet.main+xml",   "http://schemas.openxmlformats.org/spreadsheetml/2006/main", "http://schemas.openxmlformats.org/officeDocument/2006/relationships/officeDocument" },
    { worksheet,                        "application/vnd.openxmlformats-officedocument.spreadsheetml.worksheet+xml", "http://schemas.openxmlformats.org/spreadsheetml/2006/main", "http://schemas.openxmlformats.org/officeDocument/2006/relationships/worksheet" },
    { shared_string_table,              "application/vnd.openxmlformats-officedocument.spreadsheetml.sharedStrings+xml", "http://schemas.openxmlformats.org/spreadsheetml/2006/main", "http://schemas.openxmlformats.org/officeDocument/2006/relationships/sharedStrings" },
    { styles,                           "application/vnd.openxmlformats-officedocument.spreadsheetml.styles+xml", "http://schemas.openxmlformats.org/spreadsheetml/2006/main", "http://schemas.openxmlformats.org/officeDocument/2006/relationships/styles" },
    { drawings,                         "application/vnd.openxmlformats-officedocument.drawing+xml", "http://schemas.openxmlformats.org/drawingml/2006/spreadsheetDrawing", "http://schemas.openxmlformats.org/officeDocument/2006/relationships/drawing" },
    { chartsheet,                       "application/vnd.openxmlformats-officedocument.spreadsheetml.chartsheet+xml", "http://schemas.openxmlformats.org/spreadsheetml/2006/main", "http://schemas.openxmlformats.org/officeDocument/2006/relationships/chartsheet" },
    { external_workbook_reference,      "application/vnd.openxmlformats-officedocument.spreadsheetml.externalLink+xml", "http://schemas.openxmlformats.org/spreadsheetml/2006/main", "http://schemas.openxmlformats.org/officeDocument/2006/relationships/externalLink" },
    { calculation_chain,                "application/vnd.openxmlformats-officedocument.spreadsheetml.calcChain+xml", "http://schemas.openxmlformats.org/spreadsheetml/2006/main", "http://schemas.openxmlformats.org/officeDocument/2006/relationships/calcChain" },
    { comments,                         "application/vnd.openxmlformats-officedocument.spreadsheetml.comments+xml", "http://schemas.openxmlformats.org/spreadsheetml/2006/main", "http://schemas.openxmlformats.org/officeDocument/2006/relationships/comments" },
    { connections,                      "application/vnd.openxmlformats-officedocument.spreadsheetml.connections+xml", "http://schemas.openxmlformats.org/spreadsheetml/2006/main", "http://schemas.openxmlformats.org/officeDocument/2006/relationships/connections" },
    { custom_property,                  "application/xml", "", "http://schemas.openxmlformats.org/officeDocument/2006/relationships/customProperty" },
    { custom_xml_mappings,              "application/xml", "http://schemas.openxmlformats.org/spreadsheetml/2006/main", "http://schemas.openxmlformats.org/officeDocument/2006/relationships/xmlMaps" },
    { dialogsheet,                      "application/vnd.openxmlformats-officedocument.spreadsheetml.dialogsheet+xml", "http://schemas.openxmlformats.org/spreadsheetml/2006/main", "http://schemas.openxmlformats.org/officeDocument/2006/relationships/dialogsheet" },
    { metadata,                         "application/vnd.openxmlformats-officedocument.spreadsheetml.sheetMetadata+xml", "http://schemas.openxmlformats.org/spreadsheetml/2006/main", "http://schemas.openxmlformats.org/officeDocument/2006/relationships/sheetMetadata" },
    { query_table,                      "application/vnd.openxmlformats-officedocument.spreadsheetml.queryTable+xml", "http://schemas.openxmlformats.org/spreadsheetml/2006/main", "http://schemas.openxmlformats.org/officeDocument/2006/relationships/queryTable" },
    { pivot_table,                      "application/vnd.openxmlformats-officedocument.spreadsheetml.pivotTable+xml", "http://schemas.openxmlformats.org/spreadsheetml/2006/main", "http://schemas.openxmlformats.org/officeDocument/2006/relationships/pivotTable" },
    { pivot_table_cache_definition,     "application/vnd.openxmlformats-officedocument.spreadsheetml.pivotCacheDefinition+xml", "http://schemas.openxmlformats.org/spreadsheetml/2006/main", "http://schemas.openxmlformats.org/officeDocument/2006/relationships/pivotCacheDefinition" },
    { pivot_table_cache_reords,         "application/vnd.openxmlformats-officedocument.spreadsheetml.pivotCacheRecords+xml", "http://schemas.openxmlformats.org/spreadsheetml/2006/main", "http://schemas.openxmlformats.org/officeDocument/2006/relationships/pivotCacheRecords" },
    { shared_workbook_user_data,        "application/vnd.openxmlformats-officedocument.spreadsheetml.userNames+xml", "http://schemas.openxmlformats.org/spreadsheetml/2006/main", "http://schemas.openxmlformats.org/officeDocument/2006/relationships/usernames" },
    { shared_workbook_revision_headers, "application/vnd.openxmlformats-officedocument.spreadsheetml.revisionHeaders+xml", "http://schemas.openxmlformats.org/spreadsheetml/2006/main", "http://schemas.openxmlformats.org/officeDocument/2006/relationships/revisionHeaders" },
    { shared_workbook_revision_log,     "application/vnd.openxmlformats-officedocument.spreadsheetml.revisionLog+xml", "http://schemas.openxmlformats.org/spreadsheetml/2006/main", "http://schemas.openxmlformats.org/officeDocument/2006/relationships/revisionLog" },
    { single_cell_table_definitions,    "application/vnd.openxmlformats-officedocument.spreadsheetml.tableSingleCells+xml", "http://schemas.openxmlformats.org/spreadsheetml/2006/main", "http://schemas.openxmlformats.org/officeDocument/2006/relationships/tableSingleCells" },
    { table_definition,                 "application/vnd.openxmlformats-officedocument.spreadsheetml.table+xml", "http://schemas.openxmlformats.org/spreadsheetml/2006/main", "http://schemas.openxmlformats.org/officeDocument/2006/relationships/table" },
    { volatile_dependencies,            "application/vnd.openxmlformats-officedocument.spreadsheetml.volatileDependencies+xml", "http://schemas.openxmlformats.org/spreadsheetml/2006/main", "http://schemas.openxmlformats.org/officeDocument/2006/relationships/volatileDependencies" },
};

TContentTypes g_contenttypes;

static void content_init_f()
{
for (unsigned int index = 0; index < sizeof(CONTENT_TYPES)/sizeof(SContentType); ++index)
    {
    g_contenttypes.insert( std::make_pair( CONTENT_TYPES[index].m_id, CONTENT_TYPES[index] ) );
    }
}

static ext::initializer content_init( content_init_f );

SContentObject::SContentObject(const TString& filename, ECONTENTTYPE type):
    m_filename( filename ), m_type( type )
{
}

void CContent::insert(const sring& filename, content::type type)
{
base::push_back( SContentObject( filename, type ) );
}

int CContent::save(TZip& archive) const
{
std::stringstream content;
content << "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\"?>\n";
content << "<Types xmlns=\"http://schemas.openxmlformats.org/package/2006/content-types\">\n";
content << "<Default Extension=\"rels\" ContentType=\"application/vnd.openxmlformats-package.relationships+xml\"/>\n";
content << "<Default Extension=\"xml\" ContentType=\"application/xml\"/>\n";
base::const_iterator it = base::begin();
base::const_iterator end = base::end();
for (; it != end; ++it)
    {
    content << "<Override PartName=\"/" << it->m_filename << '"';
    content << " ContentType=\"" << g_contenttypes[it->m_type].m_type << "\"/>\n";
    }
content << "</Types>\n";
int ret = archive.add_file( "[Content_Types].xml", content.str() );
return ret;
}

}//namespace base

