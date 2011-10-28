#ifndef EXCEL_DOCH
#define EXCEL_DOCH

#include "ext/string.h"
#include "ext/exception.h"
//#include "spreadsheetml/ct_workbook.h"

namespace excel
{
using namespace ext;
//using namespace spreadsheetml;

class doc
{
protected:
//CT_Workbook    m_workbook;

public:
        doc();
int     save(const string& filename) const throw(exception);
};

}//namespace excel

#endif

