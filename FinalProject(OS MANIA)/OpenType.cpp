// OpenType.cpp : implementation file
//

#include "stdafx.h"
#include "OpenType.h"
#include "afxdialogex.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <io.h>
#include <stdlib.h>
#include <time.h>
#define COMPRESS "\x1b(s16.5H";

using namespace std;

const char fileDialogFilter[] =
"C++ Files (*.cpp) | *.cpp|Header Files\
(*.h)|*.h|Resource Files (*.rc) | *.rc |Text Files (*.txt)|*.txt| All Files (*.*)| *.*||";
const char fileDialogExt[] = "cpp";


CString csFileDgExt = CString(fileDialogExt);
CString csFilDlgFilter = CString(fileDialogFilter);

// OpenType dialog

IMPLEMENT_DYNAMIC(OpenType, CDialog)

OpenType::OpenType(CWnd* pParent /*=NULL*/)
	: CDialog(OpenType::IDD, pParent)
{

}

OpenType::~OpenType()
{
}

void OpenType::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(OpenType, CDialog)
	ON_BN_CLICKED(OTOK, &OpenType::OnClickedOtok)
	ON_BN_CLICKED(OTCANCEL, &OpenType::OnClickedOtcancel)
	ON_COMMAND(ID_PRINT_PRINT, &OpenType::OnPrintPrint)
	ON_COMMAND(PRINTOPEN, &OpenType::OnPrintopen)
END_MESSAGE_MAP()


// OpenType message handlers


void OpenType::OnClickedOtok()
{
	CString curDir, name, total;

	OTcur->GetWindowText(curDir);
	OTname->GetWindowText(name);

	if (curDir.IsEmpty() || name.IsEmpty()){
		MessageBox(_T("Please fill all the blank"), _T("Status"), MB_OK);
	}
	else
	{

		total.Format(curDir + "\\" + name);

		int pathExists = PathFileExists((LPCWSTR)total);
		if (pathExists){
			CStdioFile file;
			file.Open(total, CFile::modeRead | CFile::typeText);

			CString buffer;
			CString textfile;

			if (file){
				while (file.ReadString(textfile))
				{
					buffer += textfile;
					buffer += "\r\n";
				}

				file.Close();

				OTcontent->SetWindowText(buffer);

			}
			else
			{
				MessageBox(_T("File failed opened."), _T("Status"), MB_OK);
			}
		}
		else
			MessageBox(_T("Make sure you have a correct path!"), _T("Status"), MB_OK);
	}
}



void OpenType::OnClickedOtcancel()
{
	int result = MessageBox(_T("Are You Sure?"), _T("Exiting"), MB_ICONERROR | MB_YESNO);

	if (result == IDYES){
		Beep(1000, 100);
		OpenType::OnOK();
	}
	else
		Beep(200, 100);
}


void OpenType::OnPrintPrint()
{

}


void OpenType::OnPrintopen()
{
	char b[10000];
	unsigned int x = 0;
	ofstream printer("\\\\cts-fp.bhcc.dom\\D119");

	int result = MessageBox(L"Screen File?", L"Print what?",
		MB_ICONINFORMATION | MB_YESNO);
	if (result == IDYES)
	{
		UINT length = OTcontent->GetWindowTextLength();
		OTcontent->GetWindowText((LPTSTR)b, length +1);

		for (x = 0; x < (2*(length + 1)); x++)
			printer << b[x];
		printer << "\f";
	}
	else
	{
		char s[30];

		CPrintDialog printDialog(FALSE,
			PD_ALLPAGES | PD_PAGENUMS | PD_SELECTION);
		if (printDialog.DoModal() == IDOK)
		{
			cout << "Number of Copies:  "
				<< printDialog.GetCopies()
				<< endl
				<< endl;
			CString css = CString(s);
			MessageBox(css, L"Dialog Information",
				MB_ICONINFORMATION);
			int result = MessageBox(L"Ready to send file to printer",
				L"File Printing", MB_ICONQUESTION | MB_YESNO);
			if (result == IDYES)
			{

				char s[200];
				//ostrstream ostr (s,200);

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
					char name[20];
					//Same fix here
					CString csPathName = CString(fileDialog.GetPathName());
					strcpy_s(name, (LPCSTR)csPathName.GetString());

					if (_access(name, 04) == 0)

						MessageBox(L"File is there", L"Status", MB_OK);

					ifstream file(name, ios::binary);
					while (!file.eof())
					{

						file.read((char*)&b[x++], sizeof(char));

					}



					file.close();


					status = f.Open(fileDialog.GetPathName(), CFile::
						modeRead, &exception);
					if (!status)
					{
						char s[100];
						sprintf_s(s, "Error opening file for reading. Code:  %d",
							exception.m_cause);
						CString css = CString(s);
						MessageBox(css, L"Error", MB_OK);
						return;
					}


				}

			}

			css = CString(s);
			MessageBox(css,
				L"Dialog Information",
				MB_ICONINFORMATION);
			OTcontent->SetFocus();

			for (unsigned int z = 0; z<x; z++)

				printer << b[z];
			printer << "\f";
			printer.close();
		}

	}
	OTcontent->SetFocus();
}
