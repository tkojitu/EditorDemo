#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "EditorDemo.h"
#include "MainFrm.h"
#include "EditorDemoDoc.h"
#include "EditorDemoView.h"
#include "AboutDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

BEGIN_MESSAGE_MAP(CEditorDemoApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &CEditorDemoApp::OnAppAbout)
	ON_COMMAND(ID_FILE_NEW, &CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinApp::OnFileOpen)
END_MESSAGE_MAP()

CEditorDemoApp::CEditorDemoApp()
{
	SetAppID(_T("EditorDemo.AppID.NoVersion"));
}

CEditorDemoApp theApp;

BOOL CEditorDemoApp::InitInstance()
{
	CWinApp::InitInstance();
	EnableTaskbarInteraction(FALSE);
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));
	LoadStdProfileSettings(4);
    InitTemplate();
    if (!InitCommandLine())
        return FALSE;
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

void CEditorDemoApp::InitTemplate()
{
    CSingleDocTemplate* pDocTemplate = new CSingleDocTemplate(
        IDR_MAINFRAME,
        RUNTIME_CLASS(CEditorDemoDoc),
        RUNTIME_CLASS(CMainFrame),
        RUNTIME_CLASS(CEditorDemoView));
    AddDocTemplate(pDocTemplate);
}

BOOL CEditorDemoApp::InitCommandLine()
{
    CCommandLineInfo cmdInfo;
    ParseCommandLine(cmdInfo);
    return ProcessShellCommand(cmdInfo);
}

void CEditorDemoApp::OnAppAbout()
{
    CAboutDlg aboutDlg;
    aboutDlg.DoModal();
}
