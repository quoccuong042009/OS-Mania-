#include"resource.h"
#pragma once


// Rename dialog

class Rename : public CDialog
{
	DECLARE_DYNAMIC(Rename)

public:
	Rename(CWnd* pParent = NULL);   // standard constructor
	CEdit* RNdir;
	CEdit* RNold;
	CEdit* RNnew;
	CButton* RNok;
	CButton* RNcancel;
	virtual ~Rename();

// Dialog Data
	enum { IDD = RENAME };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog()
	{
		CDialog::OnInitDialog();

		RNdir = (CEdit *)GetDlgItem(RNDIR);
		RNold = (CEdit *)GetDlgItem(RNOLD);
		RNnew = (CEdit *)GetDlgItem(RNNEW);
		RNok = (CButton *)GetDlgItem(RNOK);
		RNcancel = (CButton *)GetDlgItem(RNCANCEL);
		return true;
	}
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedRncancel();
	afx_msg void OnClickedRnok();
};
