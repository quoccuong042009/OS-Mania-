#pragma once
#include"resource.h"

// Sort dialog

class Sort : public CDialog
{
	DECLARE_DYNAMIC(Sort)

public:
	Sort(CWnd* pParent = NULL);   // standard constructor
	CEdit* Spath;
	CEdit* Sname;
	CEdit* Snew;
	CButton* Sok;
	CButton* Scancel;
	virtual ~Sort();

// Dialog Data
	enum { IDD = SORT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog()
	{
		CDialog::OnInitDialog();

		Spath = (CEdit *)GetDlgItem(SPATH);
		Sname = (CEdit *)GetDlgItem(SNAME);
		Snew = (CEdit *)GetDlgItem(SNEWNAME);
		Sok = (CButton *)GetDlgItem(SOK);
		Scancel = (CButton *)GetDlgItem(SCANCEL);
		return true;
	}
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedSok();
	afx_msg void OnClickedScancel();
};
