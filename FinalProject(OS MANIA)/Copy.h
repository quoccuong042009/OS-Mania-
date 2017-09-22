#include"resource.h"
#pragma once


// Copy dialog

class Copy : public CDialog
{
	DECLARE_DYNAMIC(Copy)

public:
	Copy(CWnd* pParent = NULL);   // standard constructor
	CEdit* CPcur;
	CEdit* CPname;
	CEdit* CPnew;
	CButton* CPok;
	CButton* CPcancel;
	virtual ~Copy();

// Dialog Data
	enum { IDD = COPY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog()
	{
		CDialog::OnInitDialog();

		CPcur = (CEdit *)GetDlgItem(CPCURDIR);
		CPname = (CEdit *)GetDlgItem(CPNAME);
		CPnew = (CEdit *)GetDlgItem(CPNEWDIR);
		CPok = (CButton *)GetDlgItem(CPOK);
		CPcancel = (CButton *)GetDlgItem(CPCANCEL);
		return true;
	}
	DECLARE_MESSAGE_MAP()
public:
	bool SHCopy(LPCTSTR from, LPCTSTR to);
	afx_msg void OnClickedCpcancel();
	afx_msg void OnClickedCpok();
};
