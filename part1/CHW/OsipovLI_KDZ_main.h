/*
ФИО: Осипов Лев Игоревич
Группа: 271(1)ПИ
Тема работы: Контрольное домашнее задание
Среда разработки: Microsoft Visual Studio 2012 
Дата: 15.12.2013
*/

bool test_arr(int*, int);
void generate(int*, int, int, int);
void generate2to2(int*, int);
void generate0toMax(int*, int);
void sorted(int*, int);
void close_to_sorted(int*, int);
void reversed_sort(int*, int);
void copy(int*, int*, int);

/* Адаптеры для некоторых сортировок */
void countingS_adapter(int*, int);
void mergeS_adapter(int*, int);
void Hoare1S_adapter(int*, int);
void Hoare2S_adapter(int*, int);
void Hoare3S_adapter(int*, int);