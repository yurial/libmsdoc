#ifndef CT_WORKBOOKH
#define CT_WORKBOOKH

#include "ct_sheets.h"

namespace spreadsheetml
{

struct CT_Workbook    //$18.2.27 (Workbook)
{
//attrs
//TODO:ST_ConformanceClass         conformance;               //$22.9.2.2 (Document Conformance Class)
//childs
//TODO:CT_BookViews                bookViews;                 //$18.2.1  (Workbook Views)
//TODO:CT_CalcPr                   calcPr;                    //$18.2.2  (Calculation Properties)
//TODO:CT_CustomWorkbookViews      customWorkbookViews;       //$18.2.4  (Custom Workbook Views)
//TODO:CT_DefinedNames             definedNames;              //$18.2.6  (Defined Names)
//TODO:CT_ExtensionList            externalReferences         //$18.2.9  (External References)
//TODO:CT_ExtensionList            extLst;                    //$18.2.10 (Future Feature Data Storage Area)
//TODO:CT_FileRecoveryPr           fileRecoveryPr;            //$18.2.11 (File Recovery Properties)
//TODO:CT_FileSharing              fileSharing;               //$18.2.12 (File Sharing)
//TODO:CT_FileVersion              fileVersion;               //$18.2.13 (File Version)
//TODO:CT_FunctionGroups           functionGroups;            //$18.2.15 (Function Groups)
//TODO:ST_Ref                      oleSize;                   //$18.2.16 (Embedded Object Size)
//TODO:CT_PivotCaches              pivotCaches;               //$18.2.18 (PivotCaches)
CT_Sheets                   sheets;                    //$18.2.20 (Sheets)
//TODO:CT_SmartTagPr               smartTagPr;                //$18.2.21 (Smart Tag Properties)
//TODO:CT_SmartTagTypes            smartTagTypes;             //$18.2.23 (Smart Tag Types)
//TODO:CT_WebPublishing            webPublishing;             //$18.2.24 (Web Publishing Properties)
//TODO:CT_WebpublishingObjects     webPublishObjects;         //$18.2.26 (Web Publish Objects)
//TODO:CT_WorkbookPr               workbookPr;                //$18.2.28 (Workbook Properties)
//TODO:CT_workBookProtection       workbookProtection;        //$18.2.29 (Workbook Protection)
};

}//namespace spreasheetml

#endif

