// zxcdasDoc.cpp : implementation of the CzxcdasDoc class
//

#include "stdafx.h"
#include "zxcdas.h"

#include "zxcdasDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CzxcdasDoc

IMPLEMENT_DYNCREATE(CzxcdasDoc, CDocument)

BEGIN_MESSAGE_MAP(CzxcdasDoc, CDocument)
END_MESSAGE_MAP()


// CzxcdasDoc construction/destruction

CzxcdasDoc::CzxcdasDoc()
{
	// TODO: add one-time construction code here

}

CzxcdasDoc::~CzxcdasDoc()
{
}

BOOL CzxcdasDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CzxcdasDoc serialization

void CzxcdasDoc::Serialize(CArchive& ar)
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


// CzxcdasDoc diagnostics

#ifdef _DEBUG
void CzxcdasDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CzxcdasDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CzxcdasDoc commands
