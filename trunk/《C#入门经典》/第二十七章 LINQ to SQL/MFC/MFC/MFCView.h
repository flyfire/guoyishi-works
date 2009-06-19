// MFCView.h : CMFCView ��Ľӿ�
//


#pragma once


class CMFCView : public CView
{
protected: // �������л�����
	CMFCView();
	DECLARE_DYNCREATE(CMFCView)

// ����
public:
	CMFCDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CMFCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFCView.cpp �еĵ��԰汾
inline CMFCDoc* CMFCView::GetDocument() const
   { return reinterpret_cast<CMFCDoc*>(m_pDocument); }
#endif

