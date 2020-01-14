/*
ФИО: Осипов Лев Игоревич
Группа: 271(1)ПИ
Тема работы: Проект 6-7. Реализации различных рекурсивных сортировок на языке С++
Среда разработки: Microsoft Visual Studio 2012 
Дата: 18.10.2013
*/

#include <iostream>
#include <ctime>
using namespace std;

void insertion_sort(int *arr, int n)
{
	int temp, j;
	for (int i = 1; i < n; ++ i)
	{
		temp = arr[i];
		for (j = i - 1; temp < arr[j] && j >= 0; -- j)
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = temp;
	}
}

void merge(int *arr, int min, int mid, int max)
{
	int p1 = min;
	int p2 =  mid + 1;
	int p3 = 0;
	int *helparr = new int[max - min + 1];
	while (p1 <= mid && p2 <= max) {
		if (arr[p1] < arr[p2]) {
			helparr[p3 ++] = arr[p1 ++];
		} else {
			helparr[p3 ++] = arr[p2 ++];
		}
	}
	while (p2 <= max) {
		helparr[p3 ++] = arr[p2 ++];
	}
	while (p1 <= mid) {
		helparr[p3 ++] = arr[p1 ++];
	}
	for (p3 = 0; p3 < max - min + 1; p3++) {
		arr[min + p3] = helparr[p3];
	}
	delete [] helparr;
}

void merge_sort(int *arr, int min, int max)
{
	int mid;
	if (min < max)
	{
		mid = (min + max) / 2;
		merge_sort(arr, min, mid);
		merge_sort(arr, mid + 1, max);
		merge(arr, min, mid, max);
	}
}

void  heapify(int *arr, int heapsize, int i)
{
	int max, left = 2 * i + 1, right = 2 * i + 2, temp;
	if (left < heapsize && arr[left] > arr[i])
	{
		max = left;
	}
	else
	{
		max = i;
	}
	if (right < heapsize && arr[right] > arr[max])
	{
		max = right;
	}
	if (max != i)
	{
		temp = arr[i];
		arr[i] = arr[max];
		arr[max] = temp;
		heapify(arr, heapsize, max);
	}
}

void  build_heap(int *arr, int n)
{
	for (int i = n - 1; i >= 0; --i)
	{
		heapify(arr, n, i);
	}
}

void  heap_sort(int *arr, int n)
{
	int heapsize = n, temp;
	build_heap(arr, n);
	for (int i = n - 1; i >= 1; --i)
	{
		temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp;
		-- heapsize;
		heapify(arr, heapsize, 0);
	}
}

void Hoare_sort_1(int *arr, int min, int max)
{
	int mn = min, mx = max, mid = arr[(mn + mx) / 2], temp;
	do
	{
		while (arr[mn] < mid) ++ mn;
		while (arr[mx] > mid) -- mx;
		if (mn <= mx) 
		{
			if (mn < mx)
			{
				temp = arr[mn];
				arr[mn] = arr[mx];
				arr[mx] = temp;
			}
			++ mn; -- mx;
		}
	} while (mn <= mx);
	if (mn < max) Hoare_sort_1(arr, mn, max);
	if (min < mx) Hoare_sort_1(arr, min, mx);
}

void Hoare_sort_2(int *arr, int min, int max)
{
	int mn = min, mx = max, mid = arr[mn + 1], temp;
	do
	{
		while (arr[mn] < mid) ++ mn;
		while (arr[mx] > mid) -- mx;
		if (mn <= mx) 
		{
			if (mn < mx)
			{
				temp = arr[mn];
				arr[mn] = arr[mx];
				arr[mx] = temp;
			}
			++ mn; -- mx;
		}
	} while (mn <= mx);
	if (mn < max) Hoare_sort_2(arr, mn, max);
	if (min < mx) Hoare_sort_2(arr, min, mx);
}

void Hoare_sort_3(int *arr, int min, int max)
{
	int mn = min, mx = max, mid = arr[rand() % (mx - mn + 1) + mn], temp;
	do
	{
		while (arr[mn] < mid) ++ mn;
		while (arr[mx] > mid) -- mx;
		if (mn <= mx) 
		{
			if (mn < mx)
			{
				temp = arr[mn];
				arr[mn] = arr[mx];
				arr[mx] = temp;
			}
			++ mn; -- mx;
		}
	} while (mn <= mx);
	if (mn < max) Hoare_sort_3(arr, mn, max);
	if (min < mx) Hoare_sort_3(arr, min, mx);
}
