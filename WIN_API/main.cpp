#ifndef UNICODE
#define UNICODE
#endif // !UNICODE

#include<Windows.h>

#include"resource.h"

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
void OnSize(HWND hwnd, UINT flag, int width, int heigth);



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
		case IDOK: MessageBox(NULL, L"Press butn 'OK'", L"Info", MB_ICONINFORMATION | MB_OK); break;
		case IDCANCEL: EndDialog(hwnd, 0); break;
		}
	}
	break;
	case WM_CLOSE:
		
		//EndDialog(hwnd, 0);
		if(MessageBox(hwnd, L"Really quit?", L"My application", MB_OKCANCEL) == IDOK)
		{
			DestroyWindow(hwnd);
		}
		return 0;
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
		break; 

	case WM_SIZE:
	{
		int width = LOWORD(lParam);   //  Macro to get the low-order word.
		int heidth = HIWORD(lParam);  //  Macro to get the high-order word.

		// Respond to the message:
		OnSize(hwnd, (UINT)wParam, width, heidth);
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);

		FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
		EndPaint(hwnd, &ps);
	}
	break;

	}
	return FALSE;
}

//LRESULT CALLBACK WindowsProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
//{
//	switch (uMsg)
//	{
//
//	case WM_SIZE:
//	{
//		int width = LOWORD(lParam);   //  Macro to get the low-order word.
//		int heidth = HIWORD(lParam);  //  Macro to get the high-order word.
//
//		// Respond to the message:
//		OnSize(hwnd, (UINT)wParam, width, heidth);
//	}
//	break;
//	case WM_PAINT:
//	{
//		PAINTSTRUCT ps;
//		HDC hdc = BeginPaint(hwnd, &ps);
//
//		FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
//		EndPaint(hwnd, &ps);
//	}
//	break;
//	}
//	return 0;
//}

void OnSize(HWND hwnd, UINT flag, int width, int heigth)
{
	//  Handle resizing

}