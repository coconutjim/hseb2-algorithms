/*
ФИО: Осипов Лев Игоревич
Группа: 271(1)ПИ
Тема работы: Проект 8. Изучение инструментов измерения времени
Среда разработки: Microsoft Visual Studio 2012 
Дата: 02.11.2013
*/


#include<iostream>
#include<time.h>
#include<Windows.h>
#pragma comment (lib, "Winmm.lib")
using namespace std;

void main()
{
	setlocale(LC_ALL,"Russian");
	//Измерение минимального интервала (функция clock)
	cout << "Измерение минимального интервала clock. Пожалуйста, подождите" << endl;
	double startTime1, elapsedTime1;
	double min1 = 1000;
	for (int i = 0; i < 3; ++ i)
	{
		startTime1 = clock();
		while (clock() == startTime1); // ожидание изменения счетчика
		elapsedTime1 = clock();
		if (elapsedTime1 - startTime1 < min1) // поиск наименьшего интервала
		{
			min1 = elapsedTime1 - startTime1;
		}
	}
	cout << "Минимальный интервал: " << min1 << " мс" << endl;
	cout << endl;
	//Измерение минимального интервала (функция time)
	cout << "Измерение минимального интервала time. Пожалуйста, подождите" << endl;
	time_t startTime2, elapsedTime2;
	time_t min2 = 1000;
	for (int i = 0; i < 3; ++ i)
	{
		startTime2 = time(NULL);
		while (time(NULL) == startTime2); // ожидание изменения счетчика
		elapsedTime2 = time(NULL);
		if (elapsedTime2 - startTime2 < min2) // поиск наименьшего интервала
		{
			min2 = elapsedTime2 - startTime2;
		}
	}
	cout << "Минимальный интервал: " << min2 << " c" << endl;
	cout << endl;
	//Измерение минимального интервала (функция timeGetTime)
	cout << "Измерение минимального интервала timeGetTime. Пожалуйста, подождите" << endl;
	DWORD startTime3, elapsedTime3;
	DWORD min3 = 1000;
	for (int i = 0; i < 1000; ++ i)
	{
		startTime3 = timeGetTime();
		while (timeGetTime() == startTime3); // ожидание изменения счетчика
		elapsedTime3 = timeGetTime();
		if (elapsedTime3 - startTime3 < min3) // поиск наименьшего интервала
		{
			min3 = elapsedTime3 - startTime3;
		}
	}
	cout << "Минимальный интервал: " << min3 << " мс" << endl;
	cout << endl;
	//Измерение минимального интервала (функция GetTickCount)
	cout << "Измерение минимального интервала GetTickCount. Пожалуйста, подождите" << endl;
	min3 = 1000;
	for (int i = 0; i < 100; ++ i)
	{
		startTime3 = GetTickCount();
		while (GetTickCount() == startTime3); // ожидание изменения счетчика
		elapsedTime3 = GetTickCount();
		if (elapsedTime3 - startTime3 < min3) // поиск наименьшего интервала
		{
			min3 = elapsedTime3 - startTime3;
		}
	}
	cout << "Минимальный интервал: " << min3 << " мс" << endl;
	cout << endl;
	//Измерение минимального интервала (функции Windows API)
	cout << "Измерение минимального интервала Windows API. Пожалуйста, подождите" << endl;
	LARGE_INTEGER frequency, startTime4, elapsedTime4;
	LARGE_INTEGER min4;
	min4.QuadPart = 1000;
	for (int i = 0; i < 1000; ++ i)
	{
		QueryPerformanceFrequency(&frequency); // измерение частоты тиков
		QueryPerformanceCounter(&startTime4);
		do // ожидание изменения счетчика
		{
			QueryPerformanceCounter(&elapsedTime4);
		} while (startTime4.QuadPart == elapsedTime4.QuadPart);
		if (elapsedTime4.QuadPart - startTime4.QuadPart < min4.QuadPart) // поиск наименьшего интервала
		{
			min4.QuadPart = elapsedTime4.QuadPart - startTime4.QuadPart; 
		}
	}
	cout << "Минимальный интервал: " << min4.QuadPart << " тиков (" <<
		(double)min4.QuadPart * 1000000000 / frequency.QuadPart << " нс)" << endl;
	cout << endl;
	
	//Измерение минимального интервала (функция RDTSC-32)
	cout << "Измерение количества тактов в секунду RDTSC-32. Пожалуйста, подождите" << endl;
	_asm //вставка кода ассемблера
	{
		RDTSC
			mov startTime3, eax
	}
	Sleep(1000); //измерение количества тактов за секунду
	_asm  //вставка кода ассемблера
	{
		RDTSC
			mov elapsedTime3, eax
	}
	DWORD ticsPerSec1 = elapsedTime3 - startTime3;
	cout << "Количество тактов в секунду: " << ticsPerSec1 << endl;
	cout << "Измерение минимального интервала RDTSC-32. Пожалуйста, подождите" << endl;
	min3 = 1000;
	for (int i = 0; i < 1000; ++ i)
	{
		_asm  //вставка кода ассемблера
		{
			RDTSC
				mov startTime3, eax
		}
		do // ожидание изменения счетчика
		{
			_asm  //вставка кода ассемблера
			{
				RDTSC
					mov elapsedTime3, eax
			}
		} while (startTime3 == elapsedTime3);
		if (elapsedTime3 - startTime3 < min3) // поиск наименьшего интервала
		{
			min3 = elapsedTime3 - startTime3;
		}
	}
	cout << "Минимальный интервал: " << min3 << " тактов (" <<
		(double)min3 * 1000000000 / ticsPerSec1 << " нс)" << endl;
	cout << endl;
	//Измерение минимального интервала (функция RDTSC-64)
	cout << "Измерение количества тактов в секунду RDTSC-64. Пожалуйста, подождите" << endl;
	__int64 startTime5, elapsedTime5;
	__int64 min5 = 1000;
	_asm  //вставка кода ассемблера
	{
		RDTSC
			mov DWORD PTR startTime5, eax
			mov DWORD PTR startTime5 + 4, edx
	}
	Sleep(1000); //измерение количества тактов за секунду
	_asm  //вставка кода ассемблера
	{
		RDTSC
			mov DWORD PTR elapsedTime5, eax
			mov DWORD PTR elapsedTime5 + 4, edx
	}
	__int64 ticsPerSec2 = elapsedTime5 - startTime5;
	cout << "Количество тактов в секунду: " << ticsPerSec2 << endl;
	cout << "Измерение минимального интервала RDTSC-64. Пожалуйста, подождите" << endl;
	for (int i = 0; i < 1000; ++ i)
	{
		_asm  //вставка кода ассемблера
		{
			RDTSC
				mov DWORD PTR startTime5, eax
				mov DWORD PTR startTime5 + 4, edx
		}
		do // ожидание изменения счетчика
		{
			_asm  //вставка кода ассемблера
			{
				RDTSC
					mov DWORD PTR elapsedTime5, eax
					mov DWORD PTR elapsedTime5 + 4, edx
			}
		} while (startTime5 == elapsedTime5);
		if (elapsedTime5 - startTime5 < min5) // поиск наименьшего интервала
		{
			min5 = elapsedTime5 - startTime5;
		}
	}
	cout << "Минимальный интервал: " << min5 << " тактов (" <<
		(double)min5 * 1000000000 / ticsPerSec2 << " нс)" << endl;
	system ("PAUSE");
}
