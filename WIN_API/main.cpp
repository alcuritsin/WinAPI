#include<Windows.h>
#include"resource.h"

CONST CHAR* CB_CONTENT[] =
{
	"This",
	"is",
	"my",
	"first",
	"Combo",
	"Box"
};

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
	
	//MessageBox(NULL, "New Window in WIN API", "Window WIN API", MB_ICONINFORMATION | MB_YESNOCANCEL);
	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), 0, (DLGPROC) DlgProc, 0);

	return 0;
}

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
	{
		HICON hIcon = LoadIcon(GetModuleHandle(0), MAKEINTRESOURCE(IDI_ICON1));
		SendMessage(hwnd, WM_SETICON, 1, (LPARAM)hIcon);

		HWND hCombo = GetDlgItem(hwnd, IDC_COMBO1);

		for (int i = 0; i < sizeof(CB_CONTENT) / sizeof(CB_CONTENT[0]); i++)
		{
			SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)CB_CONTENT[i]);
		}

	}
		break;
	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
		case IDOK:
		{
			//MessageBox(NULL, "Press butn 'OK'", "Info", MB_ICONINFORMATION | MB_OK);
			HWND hCombo = GetDlgItem(hwnd, IDC_COMBO1);

			CHAR sz_buffer[256] = {};
			SendMessage(hCombo, CB_GETLBTEXT, SendMessage((HWND)hCombo, (UINT)CB_GETCURSEL,
				(WPARAM)0, (LPARAM)0), (LPARAM)sz_buffer);

			MessageBox(hwnd, sz_buffer, "Вы выбрали: ", MB_ICONINFORMATION | MB_OK);
		}
			break;
		case IDCANCEL: EndDialog(hwnd, 0); break;
		}
	}
	break;
	case WM_CLOSE: EndDialog(hwnd, 0);
	}
	return FALSE;
}
