
// EditorDemoView.h : interface of the CEditorDemoView class
//

#pragma once


class CEditorDemoView : public CEditView
{
protected: // create from serialization only
	CEditorDemoView();
	DECLARE_DYNCREATE(CEditorDemoView)

// Attributes
public:
	CEditorDemoDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CEditorDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in EditorDemoView.cpp
inline CEditorDemoDoc* CEditorDemoView::GetDocument() const
   { return reinterpret_cast<CEditorDemoDoc*>(m_pDocument); }
#endif

