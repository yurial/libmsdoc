#ifndef CDOCXLSX
#define CDOCXLSX

namespace libmsdoc
{
    namespace internal
    {
    class CDocXLSX;
    }
typedef internal::CDocXLSX TDocXLSX;
}

#include "cworkbook.h"

namespace libmsdoc
{
namespace internal
{
class CDocXLSX
{
public:
TWorkBook   m_workbook;

public:
        CDocXLSX();
int     save(const TString& filename) const;
};

}
}

#endif

