// RemoveDirectory.cpp : implementation file
//

#include "stdafx.h"
#include "RemoveDirectory.h"
#include "afxdialogex.h"
#include <io.h>
#include <sys/stat.h>

// RemoveDirectory dialog

IMPLEMENT_DYNAMIC(RemoveDirectoryF, CDialog)

RemoveDirectoryF::RemoveDirectoryF(CWnd* pParent /*=NULL*/)
: CDialog(RemoveDirectoryF::IDD, pParent)
{

}

RemoveDirectoryF::~RemoveDirectoryF()
{
}

void RemoveDirectoryF::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(RemoveDirectoryF, CDialog)
	ON_BN_CLICKED(RDOK, &RemoveDirectoryF::OnClickedRdok)
	ON_BN_CLICKED(RDCANCEL, &RemoveDirectoryF::OnClickedRdcancel)
END_MESSAGE_MAP()


// RemoveDirectory message handlers


void RemoveDirectoryF::OnClickedRdok()
{
	CString csFileName, csFilePath, total;

	RDdirectory->GetWindowText(csFilePath);
	RDname->GetWindowText(csFileName);

	if (csFilePath.IsEmpty() || csFileName.IsEmpty()){
		MessageBox(_T("Please fill all the blank"), _T("Status"), MB_OK);
	}
	else{
		total.Format(csFilePath + "\\" + csFileName);

		int pathExists = PathFileExists((LPCWSTR)total);
		if (pathExists){
			if (DeleteDirectory(total)){
				MessageBox(_T("File successfully removed."), _T("Status"), MB_OK);
				RDdirectory->SetWindowText(L"");
				RDname->SetWindowText(L"");
			}
			else{
				MessageBox(_T("Error creating file.\nMake sure you have a correct path!"), _T("Status"), MB_OK);
				RDdirectory->SetWindowText(L"");
				RDname->SetWindowText(L"");
			}
		}
		else
			MessageBox(_T("Make sure you have a correct path!"), _T("Status"), MB_OK);
	}
}


void RemoveDirectoryF::OnClickedRdcancel()
{
	int result = MessageBox(_T("Are You Sure?"), _T("Exiting"), MB_ICONERROR | MB_YESNO);

	if (result == IDYES){
		Beep(1000, 100);
		RemoveDirectoryF::OnOK();
	}
	else
		Beep(200, 100);
}

BOOL RemoveDirectoryF::IsDots(const TCHAR* str) {
	if (_tcscmp(str, _T(".")) && _tcscmp(str, _T("..")))
		return FALSE;
	return TRUE;
}

BOOL RemoveDirectoryF::DeleteDirectory(const TCHAR* sPath) {
	HANDLE hFind;    // file handle
	WIN32_FIND_DATA FindFileData;

	TCHAR DirPath[MAX_PATH];
	TCHAR FileName[MAX_PATH];

	_tcscpy_s(DirPath, sPath);
	_tcscat_s(DirPath, _T("\\*"));    // searching all files
	_tcscpy_s(FileName, sPath);
	_tcscat_s(FileName, _T("\\"));

	// find the first file
	hFind = FindFirstFile(DirPath, &FindFileData);
	if (hFind == INVALID_HANDLE_VALUE) return FALSE;
	_tcscpy_s(DirPath, FileName);

	bool bSearch = true;
	while (bSearch) {    // until we find an entry
		if (FindNextFile(hFind, &FindFileData)) {
			if (IsDots(FindFileData.cFileName)) continue;
			_tcscat_s(FileName, FindFileData.cFileName);
			if ((FindFileData.dwFileAttributes &
				FILE_ATTRIBUTE_DIRECTORY)) {

				// we have found a directory, recurse
				if (!DeleteDirectory(FileName)) {
					FindClose(hFind);
					return FALSE;    // directory couldn't be deleted
				}
				// remove the empty directory
				RemoveDirectory(FileName);
				_tcscpy_s(FileName, DirPath);
			}
			else {
				if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_READONLY){
					// change read-only file mode

					_wchmod(FileName, _S_IWRITE);
				}
				if (!DeleteFile(FileName)) {    // delete the file
					FindClose(hFind);
					return FALSE;
				}
				_tcscpy_s(FileName, DirPath);
			}
		}
		else {
			// no more files there
			if (GetLastError() == ERROR_NO_MORE_FILES)
				bSearch = false;
			else {
				// some error occurred; close the handle and return FALSE
				FindClose(hFind);
				return FALSE;
			}

		}

	}
	FindClose(hFind);                  // close the file handle

	return RemoveDirectory(sPath);     // remove the empty directory

}

