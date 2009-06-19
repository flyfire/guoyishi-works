// pccView.cpp : implementation of the CpccView class
//

#include "stdafx.h"
#include "pcc.h"

#include "pccDoc.h"
#include "pccView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CpccView

IMPLEMENT_DYNCREATE(CpccView, CView)

BEGIN_MESSAGE_MAP(CpccView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CpccView construction/destruction

CpccView::CpccView()
{
	// TODO: add construction code here

}

CpccView::~CpccView()
{
}

BOOL CpccView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CpccView drawing

void CpccView::OnDraw(CDC* /*pDC*/)
{
	CpccDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CpccView printing

BOOL CpccView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CpccView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CpccView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CpccView diagnostics

#ifdef _DEBUG
void CpccView::AssertValid() const
{
	CView::AssertValid();
}

void CpccView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CpccDoc* CpccView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CpccDoc)));
	return (CpccDoc*)m_pDocument;
}
#endif //_DEBUG


// CpccView message handlers
