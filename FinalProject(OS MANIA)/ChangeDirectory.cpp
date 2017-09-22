// ChangeDirectory.cpp : implementation file
//

#include "stdafx.h"
#include "ChangeDirectory.h"
#include "afxdialogex.h"
#include<direct.h>

// ChangeDirectory dialog

IMPLEMENT_DYNAMIC(ChangeDirectory, CDialog)

ChangeDirectory::ChangeDirectory(CWnd* pParent /*=NULL*/)
	: CDialog(ChangeDirectory::IDD, pParent)
{

}

ChangeDirectory::~ChangeDirectory()
{
}

void ChangeDirectory::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ChangeDirectory, CDialog)
	ON_BN_CLICKED(CDOK, &ChangeDirectory::OnClickedCdok)
	ON_BN_CLICKED(CDCANCEL, &ChangeDirectory::OnClickedCdcancel)
END_MESSAGE_MAP()


// ChangeDirectory message handlers


void ChangeDirectory::OnClickedCdok()
{
	CString newPath;

	CDnewDir->GetWindowText(newPath);

	if (newPath.IsEmpty()){
		MessageBox(_T("Please fill all the blank"), _T("Status"), MB_OK);
	}
	else{
		int pathExists = PathFileExists((LPCWSTR)newPath);
		if (pathExists){
			if (SetCurrentDirectory(newPath)){
				TCHAR currentDir[MAX_PATH];
				GetCurrentDirectory(MAX_PATH, currentDir);
				MessageBox(_T("Directory successfully changed."), _T("Status"), MB_OK);

				MessageBox(currentDir, _T("Current Directory: "), MB_OK);
				CDnewDir->SetWindowText(L"");
			}
			else{
				CDnewDir->SetWindowText(L"");
				MessageBox(_T("Directory failed changed."), _T("Status"), MB_OK);
			}
		}
		else
			MessageBox(_T("Make sure you have a correct path!"), _T("Status"), MB_OK);
	}
}


void ChangeDirectory::OnClickedCdcancel()
{
	int result = MessageBox(_T("Are You Sure?"), _T("Exiting"), MB_ICONERROR | MB_YESNO);

	if (result == IDYES){
		Beep(1000, 100);
		ChangeDirectory::OnOK();
	}
	else
		Beep(200, 100);
}


