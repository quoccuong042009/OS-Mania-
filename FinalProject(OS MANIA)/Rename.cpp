// Rename.cpp : implementation file
//

#include "stdafx.h"
#include "Rename.h"
#include "afxdialogex.h"


// Rename dialog

IMPLEMENT_DYNAMIC(Rename, CDialog)

Rename::Rename(CWnd* pParent /*=NULL*/)
	: CDialog(Rename::IDD, pParent)
{

}

Rename::~Rename()
{
}

void Rename::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Rename, CDialog)
	ON_BN_CLICKED(RNCANCEL, &Rename::OnClickedRncancel)
	ON_BN_CLICKED(RNOK, &Rename::OnClickedRnok)
END_MESSAGE_MAP()


// Rename message handlers


void Rename::OnClickedRncancel()
{
	int result = MessageBox(_T("Are You Sure?"), _T("Exiting"), MB_ICONERROR | MB_YESNO);

	if (result == IDYES){
		Beep(1000, 100);
		Rename::OnOK();
	}
	else
		Beep(200, 100);
}


void Rename::OnClickedRnok()
{
	CString curDir, name, total, newName, total2;

	RNdir->GetWindowText(curDir);
	RNold->GetWindowText(name);
	RNnew->GetWindowText(newName);

	if (curDir.IsEmpty() || name.IsEmpty() || newName.IsEmpty()){
		MessageBox(_T("Please fill all the blank"), _T("Status"), MB_OK);
	}
	else{
		int pathExists = PathFileExists((LPCWSTR)curDir);

		if (pathExists ){
			total.Format(curDir + "\\" + name);
			total2.Format(curDir + "\\" + newName);

			if (curDir.Find('\\', curDir.GetLength() - 2) == -1){
				total.Format(curDir + "\\" + name);
				total2.Format(curDir + "\\" + newName);
			}
			else{
				total.Format(curDir + name);
				total2.Format(curDir + newName);
			}

			if (MoveFile(total, total2)){
				MessageBox(_T("File successfully renamed."), _T("Status"), MB_OK);
			}
			else{
				MessageBox(_T("File faild renamed."), _T("Status"), MB_OK);
			}

			RNdir->SetWindowText(L"");
			RNold->SetWindowText(L"");
			RNnew->SetWindowText(L"");
		}
		else
			MessageBox(_T("Make sure you have a correct path!"), _T("Status"), MB_OK);
	}
}