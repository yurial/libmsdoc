#ifndef CT_SHEETVIEWH
#define CT_SHEETVIEWH

namespace spreadsheetml
{

struct CT_SheetView //$18.3.1.87 (Worksheet View)
{
//attrs
uint        colorId;                    //(Color Id)
bool        defaultGridColor;           //(Default Grid Color)
bool        rightToLeft;                //(Right To Left)
bool        showFormulas;               //(Show Formulas)
bool        showGridLines;              //(Show Grid Lines)
bool        showOutlineSymbols;         //(Show Outline Symbols)
bool        showRowColHeaders;          //(Show Headers)
bool        showRuler;                  //(ShowRuler)
bool        showWhiteSpace;             //(Show White Space)
bool        showZeros;                  //(Show Zero Values)
bool        tabSelected;                //(Sheet Tab Selected)
//TODO:ST_CellRef  topLeftCell;                //(Top Left Visible Cell)
//TODO:ST_SheetViewType    view;               //(View Type)
bool        windowProtection;           //(WindowProtection)
uint        workbookViewId;             //(Workbook View Index)
uint        zoomScale;                  //(Zoom Scale)
uint        zoomScaleNormal;            //(Zoom Scale Normal View)
uint        zoomScalePageLayoutView;    //(Zoom Scale Page Layout View)
uint        zoomScaleSheetLayoutView;   //(Zoom Scale Page Break Preview)

//childs
CT_ExtensionList    extLst;         //$18.2.10   (Future Feature Data Storage Area)
CT_Pane             pane;           //$18.3.1.66 (View Pane)
CT_PivotSelection   pivotSelection; //$18.3.1.69 (PivotTable Selection)
CT_Selection        selection;      //$18.3.1.78 (Selection)
};

}//namespace spresheetml

#endif

