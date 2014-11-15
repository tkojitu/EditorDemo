#pragma once

#include <string>

class CEditorDemoDoc : public CDocument
{
protected:
	CEditorDemoDoc();
    virtual ~CEditorDemoDoc();
    DECLARE_DYNCREATE(CEditorDemoDoc)

public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

private:
    CEditView* GetEditView();
    CString Utf8ToUnicode(const std::string& utf8);
    std::string UnicodeToUtf8(CString unicode);
    void Store(CArchive& ar);
    void Load(CArchive& ar);

	DECLARE_MESSAGE_MAP()
};
