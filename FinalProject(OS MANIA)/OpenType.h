#include"resource.h"
#pragma once


// OpenType dialog

class OpenType : public CDialog
{
	DECLARE_DYNAMIC(OpenType)

public:
	OpenType(CWnd* pParent = NULL);   // standard constructor
	CEdit* OTcur;
	CEdit* OTname;
	CEdit* OTcontent;
	CButton* OTok;
	CButton* OTcancel;
	virtual ~OpenType();

// Dialog Data
	enum { IDD = TYPE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog()
	{
		CDialog::OnInitDialog();

		OTcur = (CEdit *)GetDlgItem(OTCURDIR);
		OTname = (CEdit *)GetDlgItem(OTNAME);
		OTcontent = (CEdit *)GetDlgItem(OTCONTENT);
		OTok = (CButton *)GetDlgItem(OTOK);
		OTcancel = (CButton *)GetDlgItem(OTCANCEL);
		return true;
	}
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedOtok();
	afx_msg void OnClickedOtcancel();
	afx_msg void OnPrintPrint();
	afx_msg void OnPrintopen();
};
