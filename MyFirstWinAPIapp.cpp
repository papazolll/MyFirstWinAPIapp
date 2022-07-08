#ifndef UNICODE
#define UNICODE
#endif

#include <Windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

//Точка входа в приложение
int WINAPI wWinMain(HINSTANCE hInst, HINSTANCE hPrevInst, PWSTR pCmdLine, int nCmdShow)
{
	//Регистрируем оконный класс
	const wchar_t CLASS_NAME[] = L"Sample Windows Class";

	WNDCLASS wc = { };
	wc.lpfnWndProc	= WindowProc;
	wc.hInstance = hInst;
	wc.lpszClassName = CLASS_NAME;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);

	RegisterClass(&wc);

	//Создаем окно
	HWND hwnd = CreateWindowEx(
		0, //Расширенный стиль окна WS_EX_ не используем
		CLASS_NAME, //Имя оконного класса
		L"Мое первое приложение WinAPI", //Текст в загаловке окна
		WS_OVERLAPPEDWINDOW, //Стиль окна
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, //Размер и позиция по умолчанию
		NULL, //Родительское окно, для окон верхнего уровня NULL
		NULL, //Меню для окна
		hInst, //Дескриптрор окна
		NULL 
	);

	if (hwnd == NULL) {
		return 0;
	}

	ShowWindow(hwnd, nCmdShow);

	//Запускаем цикл отлова сообщений
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
		if (MessageBox(hwnd, L"Чёёёёёёёёёёёё? Серьёзно?", L"Выходишь?", MB_YESNO) == IDYES)
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