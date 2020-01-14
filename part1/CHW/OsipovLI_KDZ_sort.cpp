/*
ФИО: Осипов Лев Игоревич
Группа: 271(1)ПИ
Тема работы: Контрольное домашнее задание
Среда разработки: Microsoft Visual Studio 2012 
Дата: 15.12.2013
*/

#include <iostream>
#include <ctime>
#include "OsipovLI_KDZ_sort.h"
using namespace std;

void simple_bubble_sort(int* arr, int n) {
	int temp;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			if (arr[j + 1] < arr[j]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void bubble_sort_condition_1(int *arr, int n) {
	int temp;
	bool flag = false;
	for (int i = 1; i < n && !flag; i++) {
		flag = true;
		for (int j = 0; j < n - i; j++) {
			if (arr[j + 1] < arr[j]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flag = false;
			}
		}
	}
}

void bubble_sort_condition_2(int *arr, int n) {
	int temp, bound, t = n - 1;
	while (t != 0) {
		bound = t;
		t = 0;
		for (int j = 0; j < bound; j++) {
			if (arr[j + 1] < arr[j]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				t = j;
			}
		}
	}
}

void insertion_sort(int *arr, int n) {
	int temp, j;
	for (int i = 1; i < n; ++ i) {
		temp = arr[i];
		for (j = i - 1; temp < arr[j] && j >= 0; -- j) {
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = temp;
	}
}

void binary_insertion_sort(int *arr, int n) {
	int min, mid, max, temp;
	for (int i = 1; i < n; ++ i) {
		if (arr[i] < arr[i - 1]) {
			temp = arr[i];
			min = 0;
			max = i - 1;
			do {
				mid = (min + max) / 2;
				if (arr[mid] < temp) {
					min = mid + 1;
				}
				else {
					max = mid - 1;
				}
			} while (min <= max);
			for (int j = i - 1; j >= min; -- j) {
				arr[j + 1] = arr[j];
			}
			arr[min] = temp;
		}
	}
}

void counting_sort(int *arr, int n, int k) {
	int *oldarr = new int[n];
	for (int i = 0; i <= n; ++ i) {
		oldarr[i] = arr[i];
	}
	int *helparr = new int[k + 1];
	for (int i = 0; i <= k; ++ i) {
		helparr[i] = 0;
	}
	for (int i = 0; i < n; ++ i) {
		++ helparr[oldarr[i]];
	}
	for (int i = 1; i <= k; ++ i) {
		helparr[i] += helparr[i - 1];
	}
	for (int i = n - 1; i >= 0; -- i) {
		arr[helparr[oldarr[i]] - 1] = oldarr[i];
		-- helparr[oldarr[i]];
	}
	delete [] helparr;
}

int find_max(int* arr, int n) {
	int max = arr[0];
	for (int i = 0; i < n; ++ i) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}

void radix_sort_16(int *arr, int n) {
	int *helparr = new int[n];
	int max = find_max(arr, n);
	int length = 0;
	while (max != 0) {
		max /= 16;
		++ length;
	}
	for (int i = 0; i < length; ++ i) {
		int temp[16] = {0};
		for (int j = 0; j < n; ++ j) {
			++ temp[arr[j] / (int)pow(16, i) % 16];
		}
		for (int j = 1; j < 16; ++ j) {
			temp[j] += temp[j - 1];
		}
		for (int j = n - 1; j >= 0; -- j) {
			helparr[-- temp[arr[j] / (int)pow(16, i) % 16]] = arr[j];
		}
		for (int j = 0; j < n; ++j) {
			arr[j] = helparr[j];
		}
	}
	delete [] helparr;
}

void merge(int *arr, int min, int mid, int max) {
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

void merge_sort(int *arr, int min, int max) {
	int mid;
	if (min < max) {
		mid = (min + max) / 2;
		merge_sort(arr, min, mid);
		merge_sort(arr, mid + 1, max);
		merge(arr, min, mid, max);
	}
}

void  heapify(int *arr, int heapsize, int i) {
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

void  build_heap(int *arr, int n) {
	for (int i = n - 1; i >= 0; --i) {
		heapify(arr, n, i);
	}
}

void  heap_sort(int *arr, int n) {
	int heapsize = n, temp;
	build_heap(arr, n);
	for (int i = n - 1; i >= 1; --i) {
		temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp;
		-- heapsize;
		heapify(arr, heapsize, 0);
	}
}

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
	if (mn < max) Hoare_sort_1(arr, mn, max);
	if (min < mx) Hoare_sort_1(arr, min, mx);
}

void Hoare_sort_2(int *arr, int min, int max) {
	int mn = min, mx = max, mid = arr[mn + 1], temp;
	if (mn == mx) {
		mid = mn;
	}
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
	if (mn < max) Hoare_sort_2(arr, mn, max);
	if (min < mx) Hoare_sort_2(arr, min, mx);
}

void Hoare_sort_3(int *arr, int min, int max) {
	int mn = min, mx = max, mid = arr[rand() % (mx - mn + 1) + mn], temp;
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
	if (mn < max) Hoare_sort_3(arr, mn, max);
	if (min < mx) Hoare_sort_3(arr, min, mx);
}

