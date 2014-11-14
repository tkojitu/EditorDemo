#pragma once

class CEditorDemoDoc : public CDocument
{
protected:
	CEditorDemoDoc();
	DECLARE_DYNCREATE(CEditorDemoDoc)

public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

public:
	virtual ~CEditorDemoDoc();

protected:
	DECLARE_MESSAGE_MAP()
};
