#include"resource.h"
#pragma once


// splash dialog

class splash : public CDialog
{
	DECLARE_DYNAMIC(splash)

public:
	splash(CWnd* pParent = NULL);   // standard constructor
	virtual ~splash();

// Dialog Data
	enum { IDD = SPLASH };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	static splash* c_pSplashDlg;
	static void ShowSplashScreen(CWnd* pParentWnd /*= NULL*/);
	void HideSplashScreen();
	static BOOL PreTranslateAppMessage(MSG* pMsg);
	afx_msg void OnTimer(UINT nIDEvent);
	virtual BOOL OnInitDialog();
};
