/*
���: ������ ��� ��������
������: 271(1)��
���� ������: ������ 11. ��������� ������������� ��������
����� ����������: Microsoft Visual Studio 2012 
����: 06.12.2013
*/

#include <vector>
using namespace std;

unsigned __int64 fact(int);
unsigned __int64 fact_down(int, int);
unsigned __int64 count_permutations(int);
unsigned __int64 count_placements(int, int);
unsigned __int64 count_combinations(int, int);
void permutations_iterations(int);
void perm(int, vector<int>&);
void permutations_recursive(int);
void place(int, int, int, vector<int>&);
void placements(int, int);
void comb(int, int, int, int, vector<int>&);
void combinations(int, int);
void repres(int, vector<int>&);
void representations(int);