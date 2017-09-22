// Cuong Lam
// Final Project Ad c++


//-----------------------------------------------------------------------------------------
#include <afxwin.h>      //MFC core and standard components

#include "resource.h"    //main symbols
#include "splash.h"
#include "RemoveDirectory.h"
#include"ChangeDirectory.h"
#include"MakeDirectory.h"
#include"Copy.h"
#include"Move.h"
#include"Rename.h"
#include"OpenType.h"
#include"EditText.h"
#include"Attributes.h"
#include"Sort.h"
//-----------------------------------------------------------------------------------------
//Globals
splash* splash::c_pSplashDlg;

class GAME_FORM : public CDialog
{
public:
	GAME_FORM(CWnd* pParent = NULL) : CDialog(GAME_FORM::IDD, pParent)
	{    }

	enum{ IDD = MainDIalog };
protected:
	virtual void DoDataExchange(CDataExchange* pDX) { CDialog::DoDataExchange(pDX); }

	virtual BOOL OnInitDialog()
	{
		CDialog::OnInitDialog();
		splash::ShowSplashScreen(NULL);
		GetCurrentDirectory(MAX_PATH, currentDir);
		return true;
	}
public:
	DECLARE_MESSAGE_MAP()
	TCHAR currentDir[MAX_PATH];
	afx_msg void OnGameHenway2();
	afx_msg void OnGameBattleoffice();
	afx_msg void OnGameBrainiac2();
	afx_msg void OnDirectoryDisPlay();
	afx_msg void OnDirectoryMakedirectory();
	afx_msg void OnDirectoryRemovedirectory();
	afx_msg void OnDirectoryChangedirectory();
	afx_msg void OnDirectoryDir();
	afx_msg void OnFileCopy();
	afx_msg void OnFileMove();
	afx_msg void OnFileRename();
	afx_msg void OnFileType();
	afx_msg void OnElseDate();
	afx_msg void OnElseTime();
	afx_msg void OnFileEdit();
	afx_msg void OnDirectoryAttributes();
	afx_msg void OnFileSort();
};
//-----------------------------------------------------------------------------------------
class TheGame : public CWinApp
{
public:
	TheGame() {  }
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL InitInstance()
	{
		CWinApp::InitInstance();
		GAME_FORM dlg;
		m_pMainWnd = &dlg;
		INT_PTR nResponse = dlg.DoModal();
		return FALSE;
	} //close function
};
//-----------------------------------------------------------------------------------------
//Need a Message Map Macro for both CDialog and CWinApp
BEGIN_MESSAGE_MAP(GAME_FORM, CDialog)
	ON_COMMAND(ID_GAME_HENWAY2, &GAME_FORM::OnGameHenway2)
	ON_COMMAND(ID_GAME_BATTLEOFFICE, &GAME_FORM::OnGameBattleoffice)
	ON_COMMAND(ID_GAME_BRAINIAC2, &GAME_FORM::OnGameBrainiac2)
	ON_COMMAND(ID_DIRECTORY_DI, &GAME_FORM::OnDirectoryDisPlay)
	ON_COMMAND(ID_DIRECTORY_MAKEDIRECTORY, &GAME_FORM::OnDirectoryMakedirectory)
	ON_COMMAND(ID_DIRECTORY_REMOVEDIRECTORY, &GAME_FORM::OnDirectoryRemovedirectory)
	ON_COMMAND(ID_DIRECTORY_CHANGEDIRECTORY, &GAME_FORM::OnDirectoryChangedirectory)
	ON_COMMAND(ID_DIRECTORY_DIR, &GAME_FORM::OnDirectoryDir)
//	ON_COMMAND(ID_DIRECTORY_COPY, &GAME_FORM::OnDirectoryCopy)
	ON_COMMAND(ID_FILE_COPY, &GAME_FORM::OnFileCopy)
	ON_COMMAND(ID_FILE_MOVE, &GAME_FORM::OnFileMove)
	ON_COMMAND(ID_FILE_RENAME, &GAME_FORM::OnFileRename)
	ON_COMMAND(ID_FILE_TYPE, &GAME_FORM::OnFileType)
	ON_COMMAND(ID_ELSE_DATE, &GAME_FORM::OnElseDate)
	ON_COMMAND(ID_ELSE_TIME, &GAME_FORM::OnElseTime)
	ON_COMMAND(ID_FILE_EDIT, &GAME_FORM::OnFileEdit)
	ON_COMMAND(ID_DIRECTORY_ATTRIBUTES, &GAME_FORM::OnDirectoryAttributes)
	ON_COMMAND(ID_FILE_SORT, &GAME_FORM::OnFileSort)
END_MESSAGE_MAP()
//-----------------------------------------------------------------------------------------
TheGame theApp;  //Starts the Application

BOOL TheGame::PreTranslateMessage(MSG* pMsg)
{
	// TODO: Add your specialized code here and call the base class, or both.
	if (splash::PreTranslateAppMessage(pMsg))
		return TRUE;

	return CWinApp::PreTranslateMessage(pMsg);
}

void GAME_FORM::OnGameHenway2()
{
	SetCurrentDirectory(currentDir);
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	wchar_t LszCommandLine[] = _T("Henway 2.exe");
	wchar_t* pCommandLine = LszCommandLine;

	// Start the child process. 
	CreateProcess(NULL,   // No module name (use command line)
		pCommandLine,        // Command line
		NULL,           // Process handle not inheritable
		NULL,           // Thread handle not inheritable
		FALSE,          // Set handle inheritance to FALSE
		0,              // No creation flags
		NULL,           // Use parent's environment block
		NULL,           // Use parent's starting directory 
		&si,            // Pointer to STARTUPINFO structure
		&pi);           // Pointer to PROCESS_INFORMATION structure
}

void GAME_FORM::OnGameBattleoffice()
{
	SetCurrentDirectory(currentDir);
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	wchar_t LszCommandLine[] = _T("BattleOffice.exe");
	wchar_t* pCommandLine = LszCommandLine;

	// Start the child process. 
	CreateProcess(NULL,   // No module name (use command line)
		pCommandLine,        // Command line
		NULL,           // Process handle not inheritable
		NULL,           // Thread handle not inheritable
		FALSE,          // Set handle inheritance to FALSE
		0,              // No creation flags
		NULL,           // Use parent's environment block
		NULL,           // Use parent's starting directory 
		&si,            // Pointer to STARTUPINFO structure
		&pi);           // Pointer to PROCESS_INFORMATION structure
}


void GAME_FORM::OnGameBrainiac2()
{
	SetCurrentDirectory(currentDir);
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	wchar_t LszCommandLine[] = _T("Brainiac 2.exe");
	wchar_t* pCommandLine = LszCommandLine;

	// Start the child process. 
	CreateProcess(NULL,   // No module name (use command line)
		pCommandLine,        // Command line
		NULL,           // Process handle not inheritable
		NULL,           // Thread handle not inheritable
		FALSE,          // Set handle inheritance to FALSE
		0,              // No creation flags
		NULL,           // Use parent's environment block
		NULL,           // Use parent's starting directory 
		&si,            // Pointer to STARTUPINFO structure
		&pi);           // Pointer to PROCESS_INFORMATION structure
}


void GAME_FORM::OnDirectoryDisPlay()
{
	SetCurrentDirectory(currentDir);
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	wchar_t LszCommandLine[] = _T("WinDir.exe");
	wchar_t* pCommandLine = LszCommandLine;

	// Start the child process. 
	CreateProcess(NULL,   // No module name (use command line)
		pCommandLine,        // Command line
		NULL,           // Process handle not inheritable
		NULL,           // Thread handle not inheritable
		FALSE,          // Set handle inheritance to FALSE
		0,              // No creation flags
		NULL,           // Use parent's environment block
		NULL,           // Use parent's starting directory 
		&si,            // Pointer to STARTUPINFO structure
		&pi);           // Pointer to PROCESS_INFORMATION structure


}


void GAME_FORM::OnDirectoryMakedirectory()
{
	MakeDirectory app;
	app.DoModal();
}


void GAME_FORM::OnDirectoryRemovedirectory()
{
	RemoveDirectoryF app;
	app.DoModal();
}


void GAME_FORM::OnDirectoryChangedirectory()
{
	ChangeDirectory app;
	app.DoModal();
}


void GAME_FORM::OnDirectoryDir()
{

	TCHAR currentDir[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, currentDir);

	MessageBox(currentDir, _T("Current Directory"), MB_OK);
}


//void GAME_FORM::OnDirectoryCopy()
//{
//	Copy app;
//	app.DoModal();
//}


void GAME_FORM::OnFileCopy()
{
	Copy app;
	app.DoModal();
}


void GAME_FORM::OnFileMove()
{
	Move app;
	app.DoModal();
}


void GAME_FORM::OnFileRename()
{
	Rename app;
	app.DoModal();
}


void GAME_FORM::OnFileType()
{
	OpenType app;
	app.DoModal();
}


void GAME_FORM::OnElseDate()
{
	CTime t;
	t = CTime::GetCurrentTime();
	CString s = t.Format("The current date is : %A, %m/%d/%Y");
	MessageBox(s, L"Date", MB_OK);
}


void GAME_FORM::OnElseTime()
{
	CTime t;
	t = CTime::GetCurrentTime();
	CString s = t.Format("The current time is : %H:%M:%S");
	MessageBox(s, L"Time", MB_OK);
}



void GAME_FORM::OnFileEdit()
{
	SetCurrentDirectory(currentDir);
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	wchar_t LszCommandLine[] = _T("menu.exe");
	wchar_t* pCommandLine = LszCommandLine;

	// Start the child process. 
	CreateProcess(NULL,   // No module name (use command line)
		(LPTSTR)pCommandLine,        // Command line
		NULL,           // Process handle not inheritable
		NULL,           // Thread handle not inheritable
		FALSE,          // Set handle inheritance to FALSE
		0,              // No creation flags
		NULL,           // Use parent's environment block
		NULL,           // Use parent's starting directory 
		&si,            // Pointer to STARTUPINFO structure
		&pi);           // Pointer to PROCESS_INFORMATION structure


}


void GAME_FORM::OnDirectoryAttributes()
{
	Attributes app;
	app.DoModal();
}


void GAME_FORM::OnFileSort()
{
	Sort app;
	app.DoModal();
}
