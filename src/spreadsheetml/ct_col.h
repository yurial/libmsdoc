#ifndef CT_COLH
#define CT_COLH

namespace spreadsceetml
{

struct CT_Col           //$18.3.1.13 (Column Width & Formatting) 
{
//attr
bool    bestFit;        // (Best Fit Column Width) 
bool    collapsed;      // (Collapsed) 
bool    customWidth;    // (Custom Width)
bool    hidden;         // (Hidden Columns) 
uint    max;            // (Maximum Column) 
uint    min;            // (Minimum Column) 
uchar   outlineLevel;   // (Outline Level) 
bool    phonetic;       // (Show Phonetic Information)
uint    style;          // (Style) 
double  width;          // (Column Width)
};

}//namespeace spreasheetml

#endif

