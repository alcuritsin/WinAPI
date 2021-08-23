#include<Windows.h>
#include"resource.h"

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInst,
	PSTR lpCmdLine,
	INT nCmdShow)
{
	
	//MessageBox(NULL, "New Window in WIN API", "Window WIN API", MB_ICONINFORMATION | MB_YESNOCANCEL);
	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), 0, DlgProc, 0);
	//MoveWindow((HWND)hInstance, 20, 20, 20, 20, TRUE);
	
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
	}
		break;
	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
		case IDOK: MessageBox(NULL, "Press butn 'OK'", "Info", MB_ICONINFORMATION | MB_OK); break;
		case IDCANCEL: EndDialog(hwnd, 0); break;
		}
	}
	break;
	case WM_CLOSE: EndDialog(hwnd, 0);
	}
	return FALSE;
}
