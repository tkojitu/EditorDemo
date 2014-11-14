#pragma once

class CMainFrame : public CFrameWnd
{
protected:
    CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

public:
	virtual ~CMainFrame();

protected:
	DECLARE_MESSAGE_MAP()
};
