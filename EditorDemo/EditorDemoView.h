#pragma once

class CEditorDemoView : public CEditView
{
protected:
	CEditorDemoView();
	DECLARE_DYNCREATE(CEditorDemoView)

public:
	CEditorDemoDoc* GetDocument() const;

public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

public:
	virtual ~CEditorDemoView();

protected:
	DECLARE_MESSAGE_MAP()
};
