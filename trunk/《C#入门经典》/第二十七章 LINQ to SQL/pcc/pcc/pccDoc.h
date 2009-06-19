// pccDoc.h : interface of the CpccDoc class
//


#pragma once


class CpccDoc : public CDocument
{
protected: // create from serialization only
	CpccDoc();
	DECLARE_DYNCREATE(CpccDoc)

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
	virtual ~CpccDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};


