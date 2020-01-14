/*
ФИО: Осипов Лев Игоревич
Группа: 271(1)ПИ
Тема работы: Проект 12. Длинные целые
Среда разработки: Microsoft Visual Studio 2012 
Дата: 10.12.2013
*/

using namespace std;
#include<fstream>
#include<string>

class LongInteger {
public:
	LongInteger(int, int);
	LongInteger(string, int);
	static LongInteger* read(string, int);
	void printConsole();
	void printFile(const char*);
	void clear();
	LongInteger* add(LongInteger*);
	LongInteger* sub(LongInteger*);
	static int compare(LongInteger*, LongInteger*);
	~LongInteger();
private:
	int* number;
	int N;
};

//void fibon(LongInteger, int, int);

LongInteger* fibon(int, int);