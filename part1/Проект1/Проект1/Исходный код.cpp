#include <iostream> 
#include<Windows.h>
using namespace std;
int f1(int&, int, int);
void  heapify(int *arr, int heapsize, int i)
{
	int max, left = 2 * i + 1, right = 2 * i + 2, temp;
	if (left < heapsize && arr[left] > arr[i]) {
		max = left;
	}
	else {
		max = i;
	}
	if (right < heapsize && arr[right] > arr[max]) {
		max = right;
	}
	if (max != i) {
		temp = arr[i];
		arr[i] = arr[max];
		arr[max] = temp;
		heapify(arr, heapsize, max);
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
void Hoare_sort(int *arr, int min, int max)
{
	int mn = min, mx = max, mid = arr[(mn + mx) / 2], temp;
	do {
		while (arr[mn] < mid) ++ mn;
		while (arr[mx] > mid) -- mx;
		if (mn <= mx) {
			if (mn < mx) {
				temp = arr[mn];
				arr[mn] = arr[mx];
				arr[mx] = temp;
			}
			++ mn; -- mx;
		}
	} while (mn <= mx);
	if (mn < max) Hoare_sort(arr, mn, max);
	if (min < mx) Hoare_sort(arr, min, mx);
}
void simple_sort(int* arr, int n)
{
	int temp;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n - i; j++)
		{
			if (arr[j + 1] < arr[j])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			//k++;
		}
	}
}
void generate(int *arr, int n, int min, int max)
{
	//srand(time(0));
	//srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (max - min + 1) + min;
	}
}
void copy(int *srcarr1, int *outarr, int n)
{
	for (int i = 0; i < n; i++)
		outarr[i] = srcarr1[i];
}
/*void main()
{
	/*
	int* a = new int[7];
	a[0] = 7;
	a[1] = 3;
	a[2] = 8;
	a[3] = 5;
	a[4] = 4;
	a[5] = 6;
	a[6] = 9;
	heapify(a, 5, 1);
	for (int i = 0; i < 7; ++ i)
		cout << a[i] << endl; */
	/*int* a = new int[9];
	a[0] = 6;
	a[1] = 4;
	a[2] = 2;
	a[3] = 5;
	a[4] = 3;
	a[5] = 1;
	a[6] = 7;
	a[7] = 4;
	a[8] = 9;
	Hoare_sort(a, 2, 6);
	for (int i = 0; i < 9; ++ i)
		cout << a[i] << endl;*/
	/*
	int *a = new int[1000];
	int *b = new int[1000];
	generate(a, 1000, 0, INT_MAX);
	LARGE_INTEGER frequency, startTime4, elapsedTime4;
	copy(a,b,1000);
	QueryPerformanceCounter(&startTime4);
	Hoare_sort(b, 0, 1000);
	QueryPerformanceCounter(&elapsedTime4);
	cout << elapsedTime4.QuadPart - startTime4.QuadPart << endl;
	copy(a,b,1000);
	QueryPerformanceCounter(&startTime4);
	Hoare_sort(b, 0, 1000);
	QueryPerformanceCounter(&elapsedTime4);
	cout << elapsedTime4.QuadPart - startTime4.QuadPart << endl;
	copy(a,b,1000);
	QueryPerformanceCounter(&startTime4);
	Hoare_sort(b, 0, 1000);
	QueryPerformanceCounter(&elapsedTime4);
	cout << elapsedTime4.QuadPart - startTime4.QuadPart << endl;
	copy(a,b,1000);
	QueryPerformanceCounter(&startTime4);
	Hoare_sort(b, 0, 1000);
	QueryPerformanceCounter(&elapsedTime4);
	cout << elapsedTime4.QuadPart - startTime4.QuadPart << endl;
	copy(a,b,1000);
	QueryPerformanceCounter(&startTime4);
	Hoare_sort(b, 0, 1000);
	QueryPerformanceCounter(&elapsedTime4);
	cout << elapsedTime4.QuadPart - startTime4.QuadPart << endl;
	copy(a,b,1000);
	QueryPerformanceCounter(&startTime4);
	Hoare_sort(b, 0, 1000);
	QueryPerformanceCounter(&elapsedTime4);
	cout << elapsedTime4.QuadPart - startTime4.QuadPart << endl;
	cout << 34<< endl;
	copy(a,b,1000);
	simple_sort(b, 1000);
	copy(a,b,1000);
	simple_sort(b, 1000);
	copy(a,b,1000);
	simple_sort(b, 1000);
	copy(a,b,1000);
	simple_sort(b, 1000);
	copy(a,b,1000);
	simple_sort(b, 1000);
	copy(a,b,1000);
	simple_sort(b, 1000);
	copy(a,b,1000);
	QueryPerformanceCounter(&startTime4);
	Hoare_sort(b, 0, 1000);
	QueryPerformanceCounter(&elapsedTime4);
	cout << elapsedTime4.QuadPart - startTime4.QuadPart << endl;
	copy(a,b,1000);
	QueryPerformanceCounter(&startTime4);
	Hoare_sort(b, 0, 1000);
	QueryPerformanceCounter(&elapsedTime4);
	cout << elapsedTime4.QuadPart - startTime4.QuadPart << endl;
	copy(a,b,1000);
	QueryPerformanceCounter(&startTime4);
	Hoare_sort(b, 0, 1000);
	QueryPerformanceCounter(&elapsedTime4);
	cout << elapsedTime4.QuadPart - startTime4.QuadPart << endl;
	copy(a,b,1000);
	QueryPerformanceCounter(&startTime4);
	Hoare_sort(b, 0, 1000);
	QueryPerformanceCounter(&elapsedTime4);
	cout << elapsedTime4.QuadPart - startTime4.QuadPart << endl;
	copy(a,b,1000);
	QueryPerformanceCounter(&startTime4);
	Hoare_sort(b, 0, 1000);
	QueryPerformanceCounter(&elapsedTime4);
	cout << elapsedTime4.QuadPart - startTime4.QuadPart << endl;
	copy(a,b,1000);
	QueryPerformanceCounter(&startTime4);
	Hoare_sort(b, 0, 1000);
	QueryPerformanceCounter(&elapsedTime4);
	cout << elapsedTime4.QuadPart - startTime4.QuadPart << endl;
	int a[4] = {0, 2, 4, 6};
int* p = a;
(*p)++;
cout << *p << endl;
	system("pause");
}*/

void Hoare_sort_1(int *arr, int min, int max) {
	int mn = min, mx = max, mid = arr[(mn + mx) / 2], temp;
	do {
		while (arr[mn] < mid) ++ mn;
		while (arr[mx] > mid) -- mx;
		if (mn <= mx) {
			if (mn < mx) {
				temp = arr[mn];
				arr[mn] = arr[mx];
				arr[mx] = temp;
			}
			++ mn; -- mx;
		}
	} while (mn <= mx);
	//if (mn < max) Hoare_sort_1(arr, mn, max);
	//if (min < mx) Hoare_sort_1(arr, min, mx);
}

int main(void)
{
	int ar[] = {1,8,2,4,5,3,4,7};
	Hoare_sort_1(ar,0,7);
	for (int i = 0; i < 8; ++i) {
		cout << ar[i] << " ";
	}
	system("pause");
}