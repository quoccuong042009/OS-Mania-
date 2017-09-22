// Sort.cpp : implementation file
//

#include "stdafx.h"
#include "Sort.h"
#include "afxdialogex.h"
#include"QuickSort.h"

// Sort dialog

IMPLEMENT_DYNAMIC(Sort, CDialog)

Sort::Sort(CWnd* pParent /*=NULL*/)
	: CDialog(Sort::IDD, pParent)
{

}

Sort::~Sort()
{
}

void Sort::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Sort, CDialog)
	ON_BN_CLICKED(SOK, &Sort::OnClickedSok)
	ON_BN_CLICKED(SCANCEL, &Sort::OnClickedScancel)
END_MESSAGE_MAP()


// Sort message handlers

void Sort::OnClickedSok()
{
	TCHAR currentDir[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, currentDir);
	DoublyLinkedList list;

	CString path, name, newName;

	Spath->GetWindowText(path);
	Sname->GetWindowText(name);
	Snew->GetWindowText(newName);

	if (path.IsEmpty() || name.IsEmpty() || newName.IsEmpty()){
		MessageBox(_T("Please fill all the blank"), _T("Status"), MB_OK);
	}
	else{
		int pathExists = PathFileExists((LPCWSTR)path);
		if (pathExists){
			SetCurrentDirectory(path);

			fstream file(name, ios::in);

			if (file){
				string k;
				while (file){
					getline(file, k, '\n');

					list.insertFirst(k);
				}
				list.quickSort();
				file.close();

				// write it to another file

				ofstream fileOut(newName, ios::out);
				if (fileOut){
					list.printToFile(fileOut);
					fileOut.close();

					MessageBox(_T("File successfully sorted."), _T("Status"), MB_OK);

				}
			}
			else
				MessageBox(_T("Error open file.\nMake sure you have a correct path!"), _T("Status"), MB_OK);

			Spath->SetWindowText(L"");
			Sname->SetWindowText(L"");
			Snew->SetWindowText(L"");

			SetCurrentDirectory(currentDir);
		}
		else
			MessageBox(_T("Make sure you have a correct path!"), _T("Status"), MB_OK);
	}

}
void Sort::OnClickedScancel()
{
	int result = MessageBox(_T("Are You Sure?"), _T("Exiting"), MB_ICONERROR | MB_YESNO);

	if (result == IDYES){
		Beep(1000, 100);
		Sort::OnOK();
	}
	else
		Beep(200, 100);
}
