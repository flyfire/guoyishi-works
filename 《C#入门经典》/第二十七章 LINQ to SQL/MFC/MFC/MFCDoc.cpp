// MFCDoc.cpp : CMFCDoc ���ʵ��
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


// CMFCDoc ����/����

CMFCDoc::CMFCDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CMFCDoc::~CMFCDoc()
{
}

BOOL CMFCDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CMFCDoc ���л�

void CMFCDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}


// CMFCDoc ���

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


// CMFCDoc ����
