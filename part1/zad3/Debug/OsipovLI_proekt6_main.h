/*
* ���: �������� ������
* ������: 271��
* ����: 18/10/2013
* ������: 6-7
* ��������: ����������� ����������
* ����� ����������������: Visual Studio 2012
*/

void generate_arr(int *p, int *p_temp, int, int, int);
void print_arr(int *p, int);

void enter_data(int &N, int &NT, int &low_bound, int &high_bound);
void reEnter_data(int *p, int *p_temp, int);
void read_data(int *p, int *p_temp, int &N, int &NT);

bool isSorted(int *p_temp, int);

void writeToFile(int *p, int *p_temp, int, int, int);
void readFile(int a[100][100], int arr[100], int &NT);