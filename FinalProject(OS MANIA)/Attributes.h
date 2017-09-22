#pragma once
#include"resource.h"

// Attributes dialog

class Attributes : public CDialog
{
	DECLARE_DYNAMIC(Attributes)

public:
	Attributes(CWnd* pParent = NULL);   // standard constructor
	CComboBox* Aaction;
	CComboBox* Atype;
	CEdit* Apath;
	CEdit* Aname;
	CButton* Aok;
	CButton* Acancel;
	virtual ~Attributes();

// Dialog Data
	enum { IDD = ATTRIBUTES };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog()
	{
		CDialog::OnInitDialog();

		Aaction = (CComboBox *)GetDlgItem(AACTION);
		Atype = (CComboBox *)GetDlgItem(ATYPE);
		Apath = (CEdit *)GetDlgItem(APATH);
		Aname = (CEdit *)GetDlgItem(ANAME);
		Aok = (CButton *)GetDlgItem(AOK);
		Acancel = (CButton *)GetDlgItem(ACANCEL);
		return true;
	}
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedAok();
	afx_msg void OnClickedAcancel();
};
