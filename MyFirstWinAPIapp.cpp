#ifndef UNICODE
#define UNICODE
#endif

#include <Windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
//����� ����� � ����������

int WINAPI wWinMain(HINSTANCE hInst, HINSTANCE hPrevInst, PWSTR pCmdLine, int nCmdShow)
{
	//������������ ������� �����
	const wchar_t CLASS_NAME[] = L"Sample Windows Class";

	WNDCLASS wc = { };
	wc.lpfnWndProc	= WindowProc;
	wc.hInstance = hInst;
	wc.lpszClassName = CLASS_NAME;

	RegisterClass(&wc);

	//������� ����
	HWND hwnd = CreateWindowEx(
		0, //����������� ����� ���� WS_EX_ �� ����������
		CLASS_NAME, //��� �������� ������
		L"��� ������ ���������� WinAPI", //����� � ��������� ����
		WS_OVERLAPPEDWINDOW, //����� ����
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, //������ � ������� �� ���������
		NULL, //������������ ����, ��� ���� �������� ������ NULL
		NULL, //���� ��� ����
		hInst, //����������� ����
		NULL 
	);

	if (hwnd == NULL) {
		return 0;
	}

	ShowWindow(hwnd, nCmdShow);

	//��������� ���� ������ ���������
	MSG msg = { };
	while (GetMessage(&msg, NULL, 0, 0) >0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
		break;
	}

	
}