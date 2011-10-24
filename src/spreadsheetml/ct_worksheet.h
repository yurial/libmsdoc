#ifndef CT_WORKSHEETH
#define CT_WORKSHEETH

namespace spreadsheetml
{

struct CT_Worksheet
{
//childs
//TODO:CT_AutoFilter               autoFilter;             //$18.3.1.2  (AutoFilter Settings)
//TODO:CT_CellWatches              cellWatches;            //$18.3.1.9  (Cell Watch Items)
//TODO:CT_PageBreak                colBreaks;              //$18.3.1.14 (Vertical Page Breaks)
//TODO:CT_Cols                     cols;                   //$18.3.1.17 (Column Information)
//TODO:CT_ConditionalFormatting    conditionalFormatting;  //$18.3.1.18 (Conditional Formatting)
//TODO:CT_Controls                 controls;               //$18.3.1.21 (Embedded Controls)
//TODO:CT_CustomProperties         customProperties;       //$18.3.1.23 (Custom Properties)
//TODO:CT_CustomSheetViews         customSheetViews;       //$18.3.1.27 (Custom Sheet Views)
//TODO:CT_DataConsolidate          dataConsolidate;        //$18.3.1.29 (Data Consolidate)
//TODO:CT_DataValidation           dataValidations;        //$18.3.1.33 (Data Validations)
//TODO:CT_SheetDimension           dimension;              //$18.3.1.35 (Worksheet Dimensions)
//TODO:CT_Drawing                  drawing;                //$18.3.1.36 (Drawing)
//TODO:CT_DrawingHF                drawingHF;              //$18.3.1.37 (Drawing Reference in Header Footer)
//TODO:CT_ExtensionList            extLst;                 //$18.2.10   (Future Feature Data Storage Area)
//TODO:CT_HEaderFooter             headerFooter;           //$18.3.1.46 (Header Footer Settings)
//TODO:CT_Hyperlink                hyperlinks;             //$18.3.1.48 (Hyperlinks)
//TODO:CT_IgnoredErrors            ignoredErrors;          //$18.3.1.51 (Ignored Errors)
//TODO:CT_MergeCells               mergeCells;             //$18.3.1.55 (Merge Cells)
//TODO:CT_OleObjects               oleObjects;             //$18.3.1.60 (Embedded Objects)
//TODO:CT_PageMargins              pageMargins;            //$18.3.1.61 (Page Margins)
pageSetup (Page Setup Settings)§18.3.1.63
phoneticPr (Phonetic Properties)§18.4.3
picture (Background Image)§18.3.1.67
printOptions (Print Options)§18.3.1.70
protectedRanges (Protected Ranges)§18.3.1.72
rowBreaks (Horizontal Page Breaks (Row))§18.3.1.74
scenarios (Scenarios)§18.3.1.76
sheetCalcPr (Sheet Calculation Properties)§18.3.1.79
sheetData (Sheet Data)§18.3.1.80
sheetFormatPr (Sheet Format Properties)§18.3.1.81
sheetPr (Sheet Properties)§18.3.1.82
sheetProtection (Sheet Protection Options)§18.3.1.85
sheetViews (Sheet Views)§18.3.1.88
smartTags (Smart Tags)§18.3.1.90
sortState (Sort State)§18.3.1.92
tableParts (Table Parts)§18.3.1.95
webPublishItems (Web Publishing Items) §18.3.1.98
};

}//namespace spreadsheetml

#endif

