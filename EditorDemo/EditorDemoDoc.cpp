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
    if (!CDocument::OnNewDocument()) {
        return FALSE;
    }
    if (!GetEditView()) {
        return TRUE;
    }
    GetEditView()->SetWindowText(NULL);
    return TRUE;
}

void CEditorDemoDoc::Serialize(CArchive& ar)
{
    if (!GetEditView()) {
        return;
    }
    if (ar.IsStoring()) {
        Store(ar);
    } else {
        Load(ar);
    }
}

void CEditorDemoDoc::Store(CArchive& ar)
{
    CString ws;
    GetEditView()->GetEditCtrl().GetWindowText(ws);
    std::string str = UnicodeToUtf8(ws);
    ar.Write(str.c_str(), (UINT)str.length());
}

void CEditorDemoDoc::Load(CArchive& ar)
{
    char buf[8193] = {0};
    std::string str;
    for (;;) {
        UINT size = ar.Read(buf, 8192);
        str.append(buf, size);
        if (size < 8192) {
            break;
        }
    }
    CString ws = Utf8ToUnicode(str);
    GetEditView()->GetEditCtrl().SetWindowText(ws);
}

CEditView* CEditorDemoDoc::GetEditView()
{
    if (m_viewList.IsEmpty()) {
        return NULL;
    }
    return (CEditView*)m_viewList.GetHead();
}

CString CEditorDemoDoc::Utf8ToUnicode(const std::string& utf8)
{
    int bufsiz = ::MultiByteToWideChar(CP_UTF8, 0, utf8.c_str(), -1, NULL, 0);
    wchar_t* buf = new wchar_t[bufsiz];
    ::MultiByteToWideChar(CP_UTF8, 0, utf8.c_str(), -1, buf, bufsiz);
    CString ret(buf);
    delete [] buf;
    return ret;
}

std::string CEditorDemoDoc::UnicodeToUtf8(CString unicode)
{
    int bufsiz = ::WideCharToMultiByte(CP_UTF8, 0, unicode, -1, NULL, 0, NULL, NULL);
    char* buf = new char[bufsiz];
    ::WideCharToMultiByte(CP_UTF8, 0, unicode, -1, buf, bufsiz, NULL, NULL);
    std::string ret(buf);
    delete [] buf;
    return ret;
}
