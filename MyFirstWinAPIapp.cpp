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
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);

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
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);

		FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

		EndPaint(hwnd, &ps);
	}
		return 0;
	case WM_CLOSE:
	{
		if (MessageBox(hwnd, L"׸�����������? ��������?", L"��������?", MB_YESNO) == IDYES)
			DestroyWindow(hwnd);
		return 0;
	}
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
		break;
	}

	
}