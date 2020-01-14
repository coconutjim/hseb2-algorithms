#include <iostream>
#include <ctime>
using namespace std;
void insertion_sort(int*, int); 
void binary_insertion_sort(int*, int); 
void counting_sort(int*, int*, int, int); 
void sort_condition_Aiverson_2(int*, int );
void main()
{
	int *arr, *o;
	arr = new int[7];
	o = new int[7];
	arr[0] = 4;
	arr[1] = 2;
	arr[2] = 3;
	arr[3] = 1;
	arr[4] = 4;
	arr[5] = 1;
	arr[6] = 2;
	counting_sort(o,arr, 7, 4);
	
	//binary_insertion_sort(arr, 7);
	for (int i = 0; i< 7; i++ )
	{cout << o[i] << endl;}
	delete [] o;
	delete [] arr;
	system("pause");
}
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
	cout << j << endl;
}

void binary_insertion_sort(int *arr, int n)
{
	int min, mid, max, temp;
	for (int i = 1; i < n; ++ i)
	{
		if (arr[i] < arr[i - 1])
		{
			temp = arr[i];
			max = 0;
			min = i - 1;
			do
			{
				mid = (min + max) / 2;
				if (arr[mid] < temp)
				{
					max = mid + 1;
				}
				else
				{
					min = mid - 1;
				}
			} while (max <= min);
			for (int j = i - 1; j >= max; -- j)
			{
				arr[j + 1] = arr[j];
			}
			arr[max] = temp;
		}
	}
}
void counting_sort(int *arr, int *oldarr, int n, int k)
{
	int *helparr = new int[k + 1];
	for (int i = 0; i <= k; ++ i)
	{
		helparr[i] = 0;
	}
	for (int i = 0; i < n; ++ i)
	{
		++ helparr[oldarr[i]];
	}
	for (int i = 1; i <= k; ++ i)
	{
		helparr[i] += helparr[i - 1];
	}
	//Комментарий
	cout << helparr[4] << endl;
	for (int i = n - 1; i >= 0; -- i)
	{
		arr[helparr[oldarr[i]] - 1] = oldarr[i];
		-- helparr[oldarr[i]];
	}
	delete [] helparr;
}
