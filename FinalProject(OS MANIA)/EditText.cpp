// EditText.cpp : implementation file
//

#include "stdafx.h"
#include "EditText.h"
#include "afxdialogex.h"

//Define filters for use with File Dialog
const char fileDialogFilter[129] =
"C++ Files (*.cpp) | *.cpp|Header Files\
		(*.h)|*.h|Resource Files (*.rc) | *.rc |Text Files (*.txt)|*.txt| All Files (*.*)| *.*||";
const char fileDialogExt[4] = "cpp";

CString csFileDgExt = CString(fileDialogExt);
CString csFilDlgFilter = CString(fileDialogFilter);

CString findString;
// EditText dialog

IMPLEMENT_DYNAMIC(EditText, CDialog)

EditText::EditText(CWnd* pParent /*=NULL*/)
	: CDialog(EditText::IDD, pParent)
{

}

EditText::~EditText()
{
}

void EditText::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(EditText, CDialog)
	ON_COMMAND(OPEN, &EditText::OnOpen)
END_MESSAGE_MAP()

UINT EditText::findMessage = ::RegisterWindowMessage(FINDMSGSTRING);
CFindReplaceDialog *findReplaceDialog = NULL;
// EditText message handlers


void EditText::OnOpen()
{
	char s[200];

	CFileDialog fileDialog(TRUE,
		csFileDgExt, NULL,
		OFN_FILEMUSTEXIST, csFilDlgFilter);

	if (fileDialog.DoModal() == IDOK)
	{
		cout << "Pathname: "
			<< fileDialog.GetPathName()
			<< endl
			<< "Filename: "
			<< fileDialog.GetFileName()
			<< endl
			<< "Extension: "
			<< fileDialog.GetFileExt()
			<< endl
			<< "File Title: "
			<< fileDialog.GetFileTitle()
			<< endl
			<< endl;


		CStdioFile f;
		CFileException exception;
		BOOL status;
		char name[40];
		char b[65535];

		for (int a = 0; a<10000; a++)
			b[a] = ' ';


		int x = 0;
		CString csFileDlg = CString(fileDialog.GetPathName());

		// Does this even make sense?

		strcpy_s(name, (LPCSTR)csFileDlg.GetString());

		if (_access("D:\\tte.txt", 04) == 0)

			MessageBox(L"File is there", L"Status", MB_OK);
		try{
			SetCurrentDirectory(L"D:\\");
			ifstream file("tte.txt", ios::binary);
			while (!file.eof())
			{

				file.read((char*)&b[x++], sizeof(char));

			}


			file.close();

		}

		catch (...)
		{
			MessageBox(L"File is too big to be loaded\n64K Maximum size\n--Returning!", L"Status", MB_OK);
			m_edit->SetFocus();
			return;
		}
		status = f.Open(fileDialog.GetPathName(), CFile::modeRead, &exception);
		if (!status)
		{
			char s[100];
			sprintf_s(s, "Error opening file for reading. Code:  %d",
				exception.m_cause);
			CString css = CString(s);
			MessageBox(css, L"Error", MB_OK);
			return;
		}


		m_edit->SetWindowText((LPTSTR)b);

	}
}

