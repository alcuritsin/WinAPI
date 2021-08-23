#include<Windows.h>
#include"resource.h"

HWND hEdit1;
HWND hEdit2;

HWND hStatic2;

CONST UINT TEXT_SIZE = 256;

CHAR sz_text_1[TEXT_SIZE] = { "Какой-то текст..." };
CHAR sz_text_2[TEXT_SIZE] = { "" };

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

		hEdit1 = GetDlgItem(hwnd, IDC_EDIT1);
		hEdit2 = GetDlgItem(hwnd, IDC_EDIT2);

		hStatic2 = GetDlgItem(hwnd, IDC_STATIC2);

		SendMessage(hEdit1, WM_SETTEXT, 0, (LPARAM)sz_text_1);

	}
	break;
	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
		case IDOK:
		{
			SendMessage(hEdit1, WM_GETTEXT, (WPARAM)TEXT_SIZE, (LPARAM)sz_text_2);
			SendMessage(hEdit2, WM_SETTEXT, 0, (LPARAM)sz_text_2);

			SendMessage(hStatic2, WM_SETTEXT, 0, (LPARAM)sz_text_2);
			//SendMessage(GetDlgItem(hwnd, IDC_STATIC1), WM_SETTEXT, 0, (LPARAM)sz_text_1);
			SetDlgItemText(hwnd, IDC_STATIC1, sz_text_1);
		}

		//MessageBox(NULL, "Press butn 'OK'", "Info", MB_ICONINFORMATION | MB_OK);
		break;
		case IDCANCEL: EndDialog(hwnd, 0); break;
		}
	}
	break;
	case WM_CLOSE: EndDialog(hwnd, 0);
	}
	return FALSE;
}
