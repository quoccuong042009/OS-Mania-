#include"resource.h"
#pragma once

// RemoveDirectory dialog

class RemoveDirectoryF : public CDialog
{
	DECLARE_DYNAMIC(RemoveDirectoryF)

public:
	RemoveDirectoryF(CWnd* pParent = NULL);   // standard constructor
	CEdit* RDdirectory;
	CEdit* RDname;
	CButton* RDok;
	CButton* RDcancel;
	virtual ~RemoveDirectoryF();

// Dialog Data
	enum { IDD = REMOVEDIR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog()
	{
		CDialog::OnInitDialog();

		RDdirectory = (CEdit *)GetDlgItem(RDPATH);
		RDname = (CEdit *)GetDlgItem(RDNAME);
		RDok = (CButton *)GetDlgItem(RDOK);
		RDcancel = (CButton *)GetDlgItem(RDCANCEL);
		return true;
	}
	DECLARE_MESSAGE_MAP()
public:
	BOOL DeleteDirectory(const TCHAR* sPath);
	BOOL IsDots(const TCHAR* str);
	afx_msg void OnClickedRdok();
	afx_msg void OnClickedRdcancel();
};
