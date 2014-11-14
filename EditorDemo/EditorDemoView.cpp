#include "stdafx.h"
#include "EditorDemo.h"
#include "EditorDemoDoc.h"
#include "EditorDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CEditorDemoView, CEditView)

BEGIN_MESSAGE_MAP(CEditorDemoView, CEditView)
END_MESSAGE_MAP()

CEditorDemoView::CEditorDemoView()
{
}

CEditorDemoView::~CEditorDemoView()
{
}

BOOL CEditorDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL | WS_HSCROLL);
	return bPreCreated;
}
