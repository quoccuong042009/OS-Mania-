// Move.cpp : implementation file
//

#include "stdafx.h"
#include "Move.h"
#include "afxdialogex.h"
#include <io.h>
#include <sys/stat.h>

// Move dialog

IMPLEMENT_DYNAMIC(Move, CDialog)

Move::Move(CWnd* pParent /*=NULL*/)
	: CDialog(Move::IDD, pParent)
{

}

Move::~Move()
{
}

void Move::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Move, CDialog)
	ON_BN_CLICKED(MOOK, &Move::OnClickedMook)
	ON_BN_CLICKED(MOCANCEL, &Move::OnClickedMocancel)
END_MESSAGE_MAP()


// Move message handlers


void Move::OnClickedMook()
{
	CString curDir, name, total, newDir, total2;

	MOcur->GetWindowText(curDir);
	MOname->GetWindowText(name);
	MOnew->GetWindowText(newDir);

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
					temp.Format(newDir + "\\" + name + "- Moved");
				else
					temp.Format(newDir + name + "-Moved");
				CreateDirectory(temp, NULL);
				total2.Format(temp);
			}

			if (SHCopy(total, total2)){
				SHDelete(total);
				MessageBox(_T("File successfully moved."), _T("Status"), MB_OK);
			}
			else
				MessageBox(_T("File failed moved."), _T("Status"), MB_OK);

			MOcur->SetWindowText(L"");
			MOname->SetWindowText(L"");
			MOnew->SetWindowText(L"");
		}
		else
			MessageBox(_T("Make sure you have a correct path!"), _T("Status"), MB_OK);
	}
}

void Move::OnClickedMocancel()
{
	int result = MessageBox(_T("Are You Sure?"), _T("Exiting"), MB_ICONERROR | MB_YESNO);

	if (result == IDYES){
		Beep(1000, 100);
		Move::OnOK();
	}
	else
		Beep(200, 100);
}

bool Move::SHCopy(LPCTSTR from, LPCTSTR to)
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

bool Move::SHDelete(LPCTSTR from)
{
	SHFILEOPSTRUCT fileOp = { 0 };
	fileOp.wFunc = FO_DELETE;
	TCHAR newFrom[MAX_PATH];
	_tcscpy_s(newFrom, from);
	newFrom[_tcsclen(from) + 1] = NULL;
	fileOp.pFrom = newFrom;

	fileOp.fFlags = FOF_SILENT | FOF_NOCONFIRMATION | FOF_NOERRORUI | FOF_NOCONFIRMMKDIR;

	int result = SHFileOperation(&fileOp);

	return result == 0;
}

BOOL Move::IsDots(const TCHAR* str) {
	if (_tcscmp(str, _T(".")) && _tcscmp(str, _T("..")))
		return FALSE;
	return TRUE;
}

BOOL Move::DeleteDirectory(const TCHAR* sPath) {
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

