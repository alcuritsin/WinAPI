#include<Windows.h>
#include"resource.h"

CONST CHAR* LIST_CONTENT[] =
{
	"This",
	"is",
	"my",
	"first",
	"ListBox"
};

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{

	//MessageBox(NULL, "New Window in WIN API", "Window WIN API", MB_ICONINFORMATION | MB_YESNOCANCEL);
	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), 0, (DLGPROC)DlgProc, 0);

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

		HWND hList = GetDlgItem(hwnd, IDC_LIST1);

		for (int i = 0; i < sizeof(LIST_CONTENT) / sizeof(LIST_CONTENT[0]); i++)
		{
			SendMessage(hList, LB_ADDSTRING, 0, (LPARAM)LIST_CONTENT[i]);
		}
	}
	break;
	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
		case IDOK:
		{
			HWND hList = GetDlgItem(hwnd, IDC_LIST1);

			int i = SendMessageA(hList, LB_GETCURSEL, 0, 0);

			//MessageBox(NULL, LIST_CONTENT[i], "Вы выбрали", MB_ICONINFORMATION | MB_OK);
			
			CHAR sz_buffer[256] = {};
			SendMessageA(hList, LB_GETTEXT, 0, (LPARAM)sz_buffer);
			MessageBox(NULL, sz_buffer, "Вы выбрали", MB_ICONINFORMATION | MB_OK);
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
