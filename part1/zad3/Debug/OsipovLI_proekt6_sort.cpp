/*
* ФИО: Николаев Михаил
* Группа: 271ПИ
* Дата: 18/10/2013
* Проект: 6-7
* Название: рекурсивные сортировки
* Среда программирования: Visual Studio 2012
*/

#include "OsipovLI_proekt6_sort.h"
#include<iostream>
#include<ctime>

using namespace std;

//сохранение основного свойства кучи
void heapify(int *p, int N, int i, int &heapsize)
{
	int largest = i;
	int L = 2 * i + 1;
	int R = 2 * i + 2;

	if (L < heapsize && p[L] > p[i])
	{
		largest = L;
	}

	if (R < heapsize && p[R] > p[largest])
	{
		largest = R;
	}

	if (largest != i)
	{
		int temp = p[i];
		p[i] = p[largest];
		p[largest] = temp;

		heapify(p, N, largest, heapsize);
	}
}

//построить кучу
void buildHeap(int *p, int N, int &heapsize)
{
	for (int i = (N - 1) / 2; i >= 0; i--)
	{
		heapify(p, N, i, heapsize);
	}
}

//отсортировать кучу (пирамидальная сортировка)
void heapSort(int *p, int N)
{
	int heapsize = N;
	buildHeap(p, N, heapsize);

	for (int i = N - 1; i > 0; i--)
	{
		int temp = p[0];
		p[0] = p[i];
		p[i] = temp;
		heapsize--;
		heapify(p, N, 0, heapsize);
	}
}

//слить два массива
void merge(int *p, int left_bound, int middle, int right_bound)
{
	int *b = new int[right_bound+1];

	for (int i = left_bound; i <= right_bound; i++)
	{
		b[i] = p[i];
	}

	int p1 = left_bound;
	int p2 = middle + 1;

	for (int k = left_bound; k <= right_bound; k++)
	{
		if ((p1 > middle) || (p2 > right_bound))
		{
			if (p1 > middle)
			{
				p[k] = b[p2];
				p2++;
			}
			else
			{
				p[k] = b[p1];
				p1++;
			}
		}
		else
		{
			if (b[p1] > b[p2])
			{
				p[k] = b[p2];
				p2++;
			}
			else
			{
				p[k] = b[p1];
				p1++;
			}
		}
	}

	delete [] b;
}

//сортировка слиянием
void MergeSort(int *p, int left_bound, int right_bound)
{
	if (left_bound < right_bound)
	{
		int mid = (left_bound + right_bound) / 2;
		MergeSort(p, left_bound, mid);
		MergeSort(p, mid + 1, right_bound);
		merge(p, left_bound, mid, right_bound);
	}
}

//сортировка Хоара с срединным разделяющим элементом
void HoarSort_Middle(int *p, int left, int right)
{
	int i = left;
	int j = right;
	int k = (i + j) / 2;
	int x = p[k];

	do
	{
		while (p[i] < x)
		{
			i++;
		}

		while (p[j] > x)
		{
			j--;
		}

		if (i <= j)
		{
			int buf = p[i];
			p[i] = p[j];
			p[j] = buf;
			i++;
			j--;
		}
	} while (i <= j);

	if (i < right)
	{
		HoarSort_Middle(p, i, right);
	}

	if (j > left)
	{
		HoarSort_Middle(p, left, j);
	}
}

//сортировка Хоара со вторым разделяющим элементом
void HoarSort_SecondLeft(int *p, int left, int right)
{
	int i = left;
	int j = right;
	int k = i + 1;
	int x = p[k];

	do
	{
		while (p[i] < x)
		{
			i++;
		}

		while (p[j] > x)
		{
			j--;
		}

		if (i <= j)
		{
			int buf = p[i];
			p[i] = p[j];
			p[j] = buf;
			i++;
			j--;
		}
	} while (i <= j);

	if (i < right)
	{
		HoarSort_Middle(p, i, right);
	}

	if (j > left)
	{
		HoarSort_Middle(p, left, j);
	}
}

//сортировка Хоара со случайным разделяющим элементом
void HoarSort_Rand(int *p, int N)
{
	srand(time(0));
	if (N <= 1)
	{
		return;
	}
	int k = rand() % N;

	int buf = p[0];
	p[0] = p[k];
	p[k] = buf;

	int last = 0;

	for (int i = 1; i < N; i++)
	{
		if (p[i] < p[0])
		{
			last++;
			int temp = p[last];
			p[last] = p[i];
			p[i] = temp;
		}
	}

	buf = p[0];
	p[0] = p[last];
	p[last] = buf;

	HoarSort_Rand(p, last);
	HoarSort_Rand(p + last + 1, N - last - 1);
}