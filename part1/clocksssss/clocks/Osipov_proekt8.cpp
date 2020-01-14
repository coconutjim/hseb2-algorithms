/*
���: ������ ��� ��������
������: 271(1)��
���� ������: ������ 8. �������� ������������ ��������� �������
����� ����������: Microsoft Visual Studio 2012 
����: 02.11.2013
*/


#include<iostream>
#include<time.h>
#include<Windows.h>
#pragma comment (lib, "Winmm.lib")
using namespace std;

void main()
{
	setlocale(LC_ALL,"Russian");
	//��������� ������������ ��������� (������� clock)
	cout << "��������� ������������ ��������� clock. ����������, ���������" << endl;
	double startTime1, elapsedTime1;
	double min1 = 1000;
	for (int i = 0; i < 3; ++ i)
	{
		startTime1 = clock();
		while (clock() == startTime1); // �������� ��������� ��������
		elapsedTime1 = clock();
		if (elapsedTime1 - startTime1 < min1) // ����� ����������� ���������
		{
			min1 = elapsedTime1 - startTime1;
		}
	}
	cout << "����������� ��������: " << min1 << " ��" << endl;
	cout << endl;
	//��������� ������������ ��������� (������� time)
	cout << "��������� ������������ ��������� time. ����������, ���������" << endl;
	time_t startTime2, elapsedTime2;
	time_t min2 = 1000;
	for (int i = 0; i < 3; ++ i)
	{
		startTime2 = time(NULL);
		while (time(NULL) == startTime2); // �������� ��������� ��������
		elapsedTime2 = time(NULL);
		if (elapsedTime2 - startTime2 < min2) // ����� ����������� ���������
		{
			min2 = elapsedTime2 - startTime2;
		}
	}
	cout << "����������� ��������: " << min2 << " c" << endl;
	cout << endl;
	//��������� ������������ ��������� (������� timeGetTime)
	cout << "��������� ������������ ��������� timeGetTime. ����������, ���������" << endl;
	DWORD startTime3, elapsedTime3;
	DWORD min3 = 1000;
	for (int i = 0; i < 1000; ++ i)
	{
		startTime3 = timeGetTime();
		while (timeGetTime() == startTime3); // �������� ��������� ��������
		elapsedTime3 = timeGetTime();
		if (elapsedTime3 - startTime3 < min3) // ����� ����������� ���������
		{
			min3 = elapsedTime3 - startTime3;
		}
	}
	cout << "����������� ��������: " << min3 << " ��" << endl;
	cout << endl;
	//��������� ������������ ��������� (������� GetTickCount)
	cout << "��������� ������������ ��������� GetTickCount. ����������, ���������" << endl;
	min3 = 1000;
	for (int i = 0; i < 100; ++ i)
	{
		startTime3 = GetTickCount();
		while (GetTickCount() == startTime3); // �������� ��������� ��������
		elapsedTime3 = GetTickCount();
		if (elapsedTime3 - startTime3 < min3) // ����� ����������� ���������
		{
			min3 = elapsedTime3 - startTime3;
		}
	}
	cout << "����������� ��������: " << min3 << " ��" << endl;
	cout << endl;
	//��������� ������������ ��������� (������� Windows API)
	cout << "��������� ������������ ��������� Windows API. ����������, ���������" << endl;
	LARGE_INTEGER frequency, startTime4, elapsedTime4;
	LARGE_INTEGER min4;
	min4.QuadPart = 1000;
	for (int i = 0; i < 1000; ++ i)
	{
		QueryPerformanceFrequency(&frequency); // ��������� ������� �����
		QueryPerformanceCounter(&startTime4);
		do // �������� ��������� ��������
		{
			QueryPerformanceCounter(&elapsedTime4);
		} while (startTime4.QuadPart == elapsedTime4.QuadPart);
		if (elapsedTime4.QuadPart - startTime4.QuadPart < min4.QuadPart) // ����� ����������� ���������
		{
			min4.QuadPart = elapsedTime4.QuadPart - startTime4.QuadPart; 
		}
	}
	cout << "����������� ��������: " << min4.QuadPart << " ����� (" <<
		(double)min4.QuadPart * 1000000000 / frequency.QuadPart << " ��)" << endl;
	cout << endl;
	
	//��������� ������������ ��������� (������� RDTSC-32)
	cout << "��������� ���������� ������ � ������� RDTSC-32. ����������, ���������" << endl;
	_asm //������� ���� ����������
	{
		RDTSC
			mov startTime3, eax
	}
	Sleep(1000); //��������� ���������� ������ �� �������
	_asm  //������� ���� ����������
	{
		RDTSC
			mov elapsedTime3, eax
	}
	DWORD ticsPerSec1 = elapsedTime3 - startTime3;
	cout << "���������� ������ � �������: " << ticsPerSec1 << endl;
	cout << "��������� ������������ ��������� RDTSC-32. ����������, ���������" << endl;
	min3 = 1000;
	for (int i = 0; i < 1000; ++ i)
	{
		_asm  //������� ���� ����������
		{
			RDTSC
				mov startTime3, eax
		}
		do // �������� ��������� ��������
		{
			_asm  //������� ���� ����������
			{
				RDTSC
					mov elapsedTime3, eax
			}
		} while (startTime3 == elapsedTime3);
		if (elapsedTime3 - startTime3 < min3) // ����� ����������� ���������
		{
			min3 = elapsedTime3 - startTime3;
		}
	}
	cout << "����������� ��������: " << min3 << " ������ (" <<
		(double)min3 * 1000000000 / ticsPerSec1 << " ��)" << endl;
	cout << endl;
	//��������� ������������ ��������� (������� RDTSC-64)
	cout << "��������� ���������� ������ � ������� RDTSC-64. ����������, ���������" << endl;
	__int64 startTime5, elapsedTime5;
	__int64 min5 = 1000;
	_asm  //������� ���� ����������
	{
		RDTSC
			mov DWORD PTR startTime5, eax
			mov DWORD PTR startTime5 + 4, edx
	}
	Sleep(1000); //��������� ���������� ������ �� �������
	_asm  //������� ���� ����������
	{
		RDTSC
			mov DWORD PTR elapsedTime5, eax
			mov DWORD PTR elapsedTime5 + 4, edx
	}
	__int64 ticsPerSec2 = elapsedTime5 - startTime5;
	cout << "���������� ������ � �������: " << ticsPerSec2 << endl;
	cout << "��������� ������������ ��������� RDTSC-64. ����������, ���������" << endl;
	for (int i = 0; i < 1000; ++ i)
	{
		_asm  //������� ���� ����������
		{
			RDTSC
				mov DWORD PTR startTime5, eax
				mov DWORD PTR startTime5 + 4, edx
		}
		do // �������� ��������� ��������
		{
			_asm  //������� ���� ����������
			{
				RDTSC
					mov DWORD PTR elapsedTime5, eax
					mov DWORD PTR elapsedTime5 + 4, edx
			}
		} while (startTime5 == elapsedTime5);
		if (elapsedTime5 - startTime5 < min5) // ����� ����������� ���������
		{
			min5 = elapsedTime5 - startTime5;
		}
	}
	cout << "����������� ��������: " << min5 << " ������ (" <<
		(double)min5 * 1000000000 / ticsPerSec2 << " ��)" << endl;
	system ("PAUSE");
}
