#include"resource.h"
#pragma once


// MakeDirectory dialog



class MakeDirectory : public CDialog
{
	DECLARE_DYNAMIC(MakeDirectory)

public:
	MakeDirectory(CWnd* pParent = NULL);   // standard constructor
	CEdit* MDdirectory;
	CEdit* MDname;
	CButton* MDok;
	CButton* MDcancel;
	virtual ~MakeDirectory();

// Dialog Data
	enum { IDD = MAKEDIR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog()
	{
		CDialog::OnInitDialog();

		MDdirectory = (CEdit *)GetDlgItem(MDDirectory);
		MDname = (CEdit *)GetDlgItem(MDNameFolder);
		MDok = (CButton *)GetDlgItem(MDOK);
		MDcancel = (CButton *)GetDlgItem(MDCANCEL);
		return true;
	}

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedMdok();
	afx_msg void OnClickedMdcancel();
};
