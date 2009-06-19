// pccView.h : interface of the CpccView class
//


#pragma once


class CpccView : public CView
{
protected: // create from serialization only
	CpccView();
	DECLARE_DYNCREATE(CpccView)

// Attributes
public:
	CpccDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CpccView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in pccView.cpp
inline CpccDoc* CpccView::GetDocument() const
   { return reinterpret_cast<CpccDoc*>(m_pDocument); }
#endif

