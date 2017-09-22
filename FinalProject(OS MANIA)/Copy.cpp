// Copy.cpp : implementation file
//

#include "stdafx.h"
#include "Copy.h"
#include <windows.h> 
#include "afxdialogex.h"

// Copy dialog

IMPLEMENT_DYNAMIC(Copy, CDialog)

Copy::Copy(CWnd* pParent /*=NULL*/)
	: CDialog(Copy::IDD, pParent)
{

}

Copy::~Copy()
{
}

void Copy::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Copy, CDialog)
	ON_BN_CLICKED(CPCANCEL, &Copy::OnClickedCpcancel)
	ON_BN_CLICKED(CPOK, &Copy::OnClickedCpok)
END_MESSAGE_MAP()


// Copy message handlers


void Copy::OnClickedCpcancel()
{
	int result = MessageBox(_T("Are You Sure?"), _T("Exiting"), MB_ICONERROR | MB_YESNO);

	if (result == IDYES){
		Beep(1000, 100);
		Copy::OnOK();
	}
	else
		Beep(200, 100);
}


void Copy::OnClickedCpok()
{
	CString curDir, name, total, newDir, total2;

	CPcur->GetWindowText(curDir);
	CPname->GetWindowText(name);
	CPnew->GetWindowText(newDir);

	if (curDir.IsEmpty() || name.IsEmpty() || newDir.IsEmpty()){
		MessageBox(_T("Please fill all the blank"), _T("Status"), MB_OK);
	}
	else{
		int pathExists = PathFileExists((LPCWSTR)curDir);
		int pathExists2 = PathFileExists((LPCWSTR)newDir);

		if (pathExists && pathExists2){
		int k = curDir.Find('\\', curDir.GetLength() - 2);

		if (k == -1)
			total.Format(curDir + "\\" + name);
		else
			total.Format(curDir + name);

		
			if (name.Find('.') == -1){
				total2.Format(newDir);
			}
			else{
				CString temp;
				if (newDir.Find('\\', newDir.GetLength() - 2) == -1)
					temp.Format(newDir + "\\" + name + "-Copy");
				else
					temp.Format(newDir + name + "-Copy");
				CreateDirectory(temp, NULL);
				total2.Format(temp);
			}

			if (SHCopy(total, total2))
				MessageBox(_T("File successfully copied."), _T("Status"), MB_OK);
			else
				MessageBox(_T("File failed copied."), _T("Status"), MB_OK);

			CPcur->SetWindowText(L"");
			CPname->SetWindowText(L"");
			CPnew->SetWindowText(L"");
		}
		else{
			MessageBox(_T("Make sure you have a correct path!"), _T("Status"), MB_OK);
		}

	}
}

bool Copy::SHCopy(LPCTSTR from, LPCTSTR to)
{
	
	SHFILEOPSTRUCT fileOp = { 0 };
	fileOp.wFunc = FO_COPY;

	TCHAR newFrom[MAX_PATH];
	_tcscpy_s(newFrom, from);
	newFrom[_tcsclen(from) + 1] = NULL;

	fileOp.pFrom = newFrom;

	TCHAR newTo[MAX_PATH];
	_tcscpy_s(newTo, to);
	newTo[_tcsclen(to) + 1] = NULL;

	fileOp.pTo = newTo;
	fileOp.fFlags = FOF_SILENT | FOF_NOCONFIRMATION | FOF_NOERRORUI | FOF_NOCONFIRMMKDIR;

	int result = SHFileOperation(&fileOp);

	return result == 0;


}