// MFCDoc.cpp : CMFCDoc 类的实现
//

#include "stdafx.h"
#include "MFC.h"

#include "MFCDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCDoc

IMPLEMENT_DYNCREATE(CMFCDoc, CDocument)

BEGIN_MESSAGE_MAP(CMFCDoc, CDocument)
END_MESSAGE_MAP()


// CMFCDoc 构造/析构

CMFCDoc::CMFCDoc()
{
	// TODO: 在此添加一次性构造代码

}

CMFCDoc::~CMFCDoc()
{
}

BOOL CMFCDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CMFCDoc 序列化

void CMFCDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}


// CMFCDoc 诊断

#ifdef _DEBUG
void CMFCDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFCDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMFCDoc 命令
