#include "stdafx.h"
#include "EditorDemo.h"
#include "EditorDemoDoc.h"
#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CEditorDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CEditorDemoDoc, CDocument)
END_MESSAGE_MAP()

CEditorDemoDoc::CEditorDemoDoc()
{
}

CEditorDemoDoc::~CEditorDemoDoc()
{
}

BOOL CEditorDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	if (!m_viewList.IsEmpty()) {
		reinterpret_cast<CEditView*>(m_viewList.GetHead())->SetWindowText(NULL);
	}
	return TRUE;
}

void CEditorDemoDoc::Serialize(CArchive& ar)
{
	if (!m_viewList.IsEmpty()) {
		reinterpret_cast<CEditView*>(m_viewList.GetHead())->SerializeRaw(ar);
	}
}
