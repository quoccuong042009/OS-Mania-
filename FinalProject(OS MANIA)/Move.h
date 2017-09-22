#include"resource.h"
#pragma once


// Move dialog

class Move : public CDialog
{
	DECLARE_DYNAMIC(Move)

public:
	Move(CWnd* pParent = NULL);   // standard constructor
	CEdit* MOcur;
	CEdit* MOname;
	CEdit* MOnew;
	CButton* MOok;
	CButton* MOcancel;
	virtual ~Move();

// Dialog Data
	enum { IDD = MOVE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog()
	{
		CDialog::OnInitDialog();

		MOcur = (CEdit *)GetDlgItem(MOCURDIR);
		MOname = (CEdit *)GetDlgItem(MONAME);
		MOnew = (CEdit *)GetDlgItem(MONEWDIR);
		MOok = (CButton *)GetDlgItem(MOOK);
		MOcancel = (CButton *)GetDlgItem(MOCANCEL);
		return true;
	}
	DECLARE_MESSAGE_MAP()
public:
	bool SHDelete(LPCTSTR path);
	BOOL DeleteDirectory(const TCHAR* sPath);
	BOOL IsDots(const TCHAR* str);
	bool SHCopy(LPCTSTR from, LPCTSTR to);
	afx_msg void OnClickedMook();
	afx_msg void OnClickedMocancel();
};
