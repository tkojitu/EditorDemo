#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"

class CEditorDemoApp : public CWinApp
{
public:
	CEditorDemoApp();

public:
	virtual BOOL InitInstance();
	afx_msg void OnAppAbout();

private:
    void InitTemplate();
    BOOL InitCommandLine();

    DECLARE_MESSAGE_MAP()
};

extern CEditorDemoApp theApp;
