#include"resource.h"
#pragma once


// ChangeDirectory dialog

class ChangeDirectory : public CDialog
{
	DECLARE_DYNAMIC(ChangeDirectory)

public:
	ChangeDirectory(CWnd* pParent = NULL);   // standard constructor
	CEdit* CDnewDir;
	CButton* CDok;
	CButton* CDcancel;
	virtual ~ChangeDirectory();

// Dialog Data
	enum { IDD = CHANGEDIR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog()
	{
		CDialog::OnInitDialog();

		CDnewDir = (CEdit *)GetDlgItem(CDNEWDIR);
		CDok = (CButton *)GetDlgItem(CDOK);
		CDcancel = (CButton *)GetDlgItem(CDCANCEL);
		return true;
	}
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedCdok();
	afx_msg void OnClickedCdcancel();
};
