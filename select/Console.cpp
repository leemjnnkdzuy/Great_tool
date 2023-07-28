#include "lib.h"


void clrscr()
{
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
	HANDLE	hConsoleOut;
	COORD	Home = { 0,0 };
	DWORD	dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);

	FillConsoleOutputCharacter(hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}


void LockConsoleWindowSize()
{
	HWND consoleWindow = GetConsoleWindow();
	if (consoleWindow != NULL) 
	{
		RECT rect;
		GetWindowRect(consoleWindow, &rect);
		MoveWindow(consoleWindow, rect.left, rect.top, 600, 600, TRUE);
	}

	if (consoleWindow != NULL) 
	{
		LONG style = GetWindowLong(consoleWindow, GWL_STYLE);

		
		style &= ~WS_THICKFRAME;  // Loại bỏ khung thay đổi kích thước
		style &= ~WS_MAXIMIZEBOX; // Loại bỏ nút phóng to
		style &= ~WS_MINIMIZEBOX; // Loại bỏ nút thu nhỏ
		style &= ~WS_SIZEBOX;     // Loại bỏ khả năng thay đổi kích thước bằng chuột

		SetWindowLong(consoleWindow, GWL_STYLE, style);
	}
}

void TextColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}