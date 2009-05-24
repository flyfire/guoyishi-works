// zxcdasDoc.h : interface of the CzxcdasDoc class
//


#pragma once


class CzxcdasDoc : public CDocument
{
protected: // create from serialization only
	CzxcdasDoc();
	DECLARE_DYNCREATE(CzxcdasDoc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// Implementation
public:
	virtual ~CzxcdasDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};


