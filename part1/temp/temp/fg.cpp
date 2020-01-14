using namespace std;
#include <iostream>
#include <vector>


void comb(vector<int> &combs, int N, int k, int start, int index) {
	if (index > k) {
		for (int i = 0; i < combs.size(); ++ i) {
			cout << combs[i]<< " ";
		}
		cout << endl;
		return;
	}
	for (int i = start; i <= N - (k - index); ++ i) {
		combs[index - 1] = i;
		comb(combs, N, k, i + 1, index + 1);
	}
}

void combinations(int N, int k) {
	vector<int> combs (k);
	comb(combs, N, k, 1, 1);
}

int find_max(int *arr, int n) {
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

void main() {
	int ar[] = {8,6,8,586788,7,2,7678,4,7,4653456,7,7,3,7,4,3,8,4,8,9,3,7};
	radix_sort_16(ar, 23);
	for (int i = 0; i < 23; ++ i) {
		cout << ar[i] << " ";
	}
	system("pause");
}
