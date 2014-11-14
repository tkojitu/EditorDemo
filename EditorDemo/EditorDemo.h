
// EditorDemo.h : main header file for the EditorDemo application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CEditorDemoApp:
// See EditorDemo.cpp for the implementation of this class
//

class CEditorDemoApp : public CWinApp
{
public:
	CEditorDemoApp();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CEditorDemoApp theApp;
