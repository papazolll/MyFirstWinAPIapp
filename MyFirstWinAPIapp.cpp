#include <Windows.h>

//Точка входа в приложение
int WINAPI wWinMain(HINSTANCE hInst, HINSTANCE hPrevInst, PWSTR pCmdLine, INT nCmdShow)
{
	//Регистрируем оконный класс
	const wchar_t CLASS_NAME[] = L"Sample Windows Class";

	WNDCLASS wc = { };
	wc.lpfnWndProc	= WindowProc;
	wc.hInstance = hInst;
	wc.lpszClassName = CLASS_NAME;

	RegisterClass(&wc);

	HWND hwnd = CreateWindowExW(
		0, //Расширенный стиль окна WS_EX_
		CLASS_NAME, //Имя оконного класса
		L"Мое первое приложение WinAPI", //Текст в загаловке окна
		WS_OVERLAPPEDWINDOW, //Стиль окна
		//Размер и позиция
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, //Родительское окно, для окон верхнего уровня NULL
		NULL, //Меню для окна
		hInst, //Дескриптрор окна
		NULL
	);

	if (hwnd == NULL) {
		return = 0;
	}


	return 0;
}