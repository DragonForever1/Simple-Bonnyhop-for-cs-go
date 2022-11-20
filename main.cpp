#include <iostream>
#include <Windows.h>
using namespace std;

void Space()
{
	INPUT input;
	WORD vKey = VK_SPACE;
	input.type = INPUT_KEYBOARD;
	input.ki.wScan = MapVirtualKey(vKey, MAPVK_VK_TO_VSC);
	input.ki.wVk = vKey;
	SendInput(1, &input, sizeof(INPUT));// вниз

	input.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &input, sizeof(INPUT)); // вверх
}

bool bHop = false;

void Bonnyhop()
{
	if (GetAsyncKeyState(VK_SPACE)); // нажми Пробел и станешь прыгать автоматически
	{
		Sleep(100);
		bHop = true;
	}
	if (GetAsyncKeyState(VK_CONTROL)) // Контрол чтобы остановиться
	{
		Sleep(100);
		bHop = false; 
	}
	if (bHop) Space();
}

int main()
{
	while (true) // бесконечный цикл
	{
		Bonnyhop();
	}
}
