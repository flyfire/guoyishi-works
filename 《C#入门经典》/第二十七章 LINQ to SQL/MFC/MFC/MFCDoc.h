// MFCDoc.h : CMFCDoc ��Ľӿ�
//


#pragma once


class CMFCDoc : public CDocument
{
protected: // �������л�����
	CMFCDoc();
	DECLARE_DYNCREATE(CMFCDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ʵ��
public:
	virtual ~CMFCDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


