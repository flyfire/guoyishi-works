// zxcdasView.h : interface of the CzxcdasView class
//


#pragma once


class CzxcdasView : public CView
{
protected: // create from serialization only
	CzxcdasView();
	DECLARE_DYNCREATE(CzxcdasView)

// Attributes
public:
	CzxcdasDoc* GetDocument() const;

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
	virtual ~CzxcdasView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in zxcdasView.cpp
inline CzxcdasDoc* CzxcdasView::GetDocument() const
   { return reinterpret_cast<CzxcdasDoc*>(m_pDocument); }
#endif

