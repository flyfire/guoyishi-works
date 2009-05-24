// zxcdasView.cpp : implementation of the CzxcdasView class
//

#include "stdafx.h"
#include "zxcdas.h"

#include "zxcdasDoc.h"
#include "zxcdasView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CzxcdasView

IMPLEMENT_DYNCREATE(CzxcdasView, CView)

BEGIN_MESSAGE_MAP(CzxcdasView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CzxcdasView construction/destruction

CzxcdasView::CzxcdasView()
{
	// TODO: add construction code here

}

CzxcdasView::~CzxcdasView()
{
}

BOOL CzxcdasView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CzxcdasView drawing

void CzxcdasView::OnDraw(CDC* /*pDC*/)
{
	CzxcdasDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CzxcdasView printing

BOOL CzxcdasView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CzxcdasView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CzxcdasView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CzxcdasView diagnostics

#ifdef _DEBUG
void CzxcdasView::AssertValid() const
{
	CView::AssertValid();
}

void CzxcdasView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CzxcdasDoc* CzxcdasView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CzxcdasDoc)));
	return (CzxcdasDoc*)m_pDocument;
}
#endif //_DEBUG


// CzxcdasView message handlers
