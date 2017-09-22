// MakeDirectory.cpp : implementation file
//

#include "stdafx.h"
#include "MakeDirectory.h"
#include "afxdialogex.h"


// MakeDirectory dialog

IMPLEMENT_DYNAMIC(MakeDirectory, CDialog)

MakeDirectory::MakeDirectory(CWnd* pParent /*=NULL*/)
: CDialog(MakeDirectory::IDD, pParent)
{

}

MakeDirectory::~MakeDirectory()
{
}

void MakeDirectory::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MakeDirectory, CDialog)
	ON_BN_CLICKED(MDOK, &MakeDirectory::OnClickedMdok)
	ON_BN_CLICKED(MDCANCEL, &MakeDirectory::OnClickedMdcancel)
END_MESSAGE_MAP()


// MakeDirectory message handlers


void MakeDirectory::OnClickedMdok()
{
	CString csFileName, csFilePath, total;

	MDdirectory->GetWindowText(csFilePath);
	MDname->GetWindowText(csFileName);

	if (csFilePath.IsEmpty() || csFileName.IsEmpty()){
		MessageBox(_T("Please fill all the blank"), _T("Status"), MB_OK);
	}
	else{
		total.Format(csFilePath + "\\" + csFileName);

		if (CreateDirectory(total, NULL) ){
			MessageBox(_T("File successfully created."), _T("Status"), MB_OK);
		}
		else{
			if (ERROR_ALREADY_EXISTS == GetLastError())
				MessageBox(_T("Error creating file.\nThe file has already existed!"), _T("Status"), MB_OK);
			else
				MessageBox(_T("Error creating file.\nMake sure you have a correct path!"), _T("Status"), MB_OK);

		}
		MDdirectory->SetWindowText(L"");
		MDname->SetWindowText(L"");
	}
}


void MakeDirectory::OnClickedMdcancel()
{
	int result = MessageBox(_T("Are You Sure?"), _T("Exiting"), MB_ICONERROR | MB_YESNO);

	if (result == IDYES){
		Beep(1000, 100);
		MakeDirectory::OnOK();
	}
	else
		Beep(200, 100);
}
