#include <Windows.h>

//����� ����� � ����������
int WINAPI wWinMain(HINSTANCE hInst, HINSTANCE hPrevInst, PWSTR pCmdLine, INT nCmdShow)
{
	//������������ ������� �����
	const wchar_t CLASS_NAME[] = L"Sample Windows Class";

	WNDCLASS wc = { };
	wc.lpfnWndProc	= WindowProc;
	wc.hInstance = hInst;
	wc.lpszClassName = CLASS_NAME;

	RegisterClass(&wc);

	HWND hwnd = CreateWindowExW(
		0, //����������� ����� ���� WS_EX_
		CLASS_NAME, //��� �������� ������
		L"��� ������ ���������� WinAPI", //����� � ��������� ����
		WS_OVERLAPPEDWINDOW, //����� ����
		//������ � �������
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, //������������ ����, ��� ���� �������� ������ NULL
		NULL, //���� ��� ����
		hInst, //����������� ����
		NULL
	);

	if (hwnd == NULL) {
		return = 0;
	}


	return 0;
}