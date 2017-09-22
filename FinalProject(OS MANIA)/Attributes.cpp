// Attributes.cpp : implementation file
//

#include "stdafx.h"
#include "Attributes.h"
#include "afxdialogex.h"


// Attributes dialog

IMPLEMENT_DYNAMIC(Attributes, CDialog)

Attributes::Attributes(CWnd* pParent /*=NULL*/)
	: CDialog(Attributes::IDD, pParent)
{

}

Attributes::~Attributes()
{
}

void Attributes::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Attributes, CDialog)
	ON_BN_CLICKED(AOK, &Attributes::OnClickedAok)
	ON_BN_CLICKED(ACANCEL, &Attributes::OnClickedAcancel)
END_MESSAGE_MAP()


// Attributes message handlers


void Attributes::OnClickedAok()
{
	CString path, name;

	Apath->GetWindowText(path);
	Aname->GetWindowText(name);

	if (path.IsEmpty() || name.IsEmpty()){
		MessageBox(_T("Please fill all the blank"), _T("Status"), MB_OK);
	}
	else{
		int pathExists = PathFileExists((LPCWSTR)path);
		if (pathExists){
			SetCurrentDirectory(path);

			int type = Atype->GetCurSel();
			int action = Aaction->GetCurSel();
			DWORD tempTyep;
			switch (type)
			{
			case 2: tempTyep = FILE_ATTRIBUTE_READONLY;	break;
			case 1: tempTyep = FILE_ATTRIBUTE_HIDDEN;	break;
			case 0: tempTyep = FILE_ATTRIBUTE_ARCHIVE;	break;
			case 3: tempTyep = FILE_ATTRIBUTE_SYSTEM;	break;
			}

			if (action == 0){
				if (SetFileAttributes(name, tempTyep))
					MessageBox(_T("FileAtributes successfully activated ."), _T("Status"), MB_OK);
				else
					MessageBox(_T("FileAtributes failed activated"), _T("Status"), MB_OK);
			}
			else {
				if (SetFileAttributes(name, GetFileAttributes(name) & ~tempTyep))
					MessageBox(_T("FileAtributes successfully deactivated."), _T("Status"), MB_OK);
				else
					MessageBox(_T("FileAtributes failed deactivated"), _T("Status"), MB_OK);

			}
		}
		else
			MessageBox(_T("Make sure you have a correct path!"), _T("Status"), MB_OK);
	}
}


void Attributes::OnClickedAcancel()
{
	int result = MessageBox(_T("Are You Sure?"), _T("Exiting"), MB_ICONERROR | MB_YESNO);

	if (result == IDYES){
		Beep(1000, 100);
		Attributes::OnOK();
	}
	else
		Beep(200, 100);
}
