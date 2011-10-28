#include "excel/doc.h"

int main()
{
using namespace excel;
doc mydoc;
mydoc.save( "test.xlsx" );
return 0;
}

