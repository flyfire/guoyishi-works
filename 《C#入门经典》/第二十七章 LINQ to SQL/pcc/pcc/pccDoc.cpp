// pccDoc.cpp : implementation of the CpccDoc class
//

#include "stdafx.h"
#include "pcc.h"

#include "pccDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CpccDoc

IMPLEMENT_DYNCREATE(CpccDoc, CDocument)

BEGIN_MESSAGE_MAP(CpccDoc, CDocument)
END_MESSAGE_MAP()


// CpccDoc construction/destruction

CpccDoc::CpccDoc()
{
	// TODO: add one-time construction code here

}

CpccDoc::~CpccDoc()
{
}

BOOL CpccDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CpccDoc serialization

void CpccDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}


// CpccDoc diagnostics

#ifdef _DEBUG
void CpccDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CpccDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CpccDoc commands
