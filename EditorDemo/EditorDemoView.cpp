
// EditorDemoView.cpp : implementation of the CEditorDemoView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "EditorDemo.h"
#endif

#include "EditorDemoDoc.h"
#include "EditorDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEditorDemoView

IMPLEMENT_DYNCREATE(CEditorDemoView, CEditView)

BEGIN_MESSAGE_MAP(CEditorDemoView, CEditView)
END_MESSAGE_MAP()

// CEditorDemoView construction/destruction

CEditorDemoView::CEditorDemoView()
{
	// TODO: add construction code here

}

CEditorDemoView::~CEditorDemoView()
{
}

BOOL CEditorDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// Enable word-wrapping

	return bPreCreated;
}


// CEditorDemoView diagnostics

#ifdef _DEBUG
void CEditorDemoView::AssertValid() const
{
	CEditView::AssertValid();
}

void CEditorDemoView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

CEditorDemoDoc* CEditorDemoView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEditorDemoDoc)));
	return (CEditorDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CEditorDemoView message handlers
