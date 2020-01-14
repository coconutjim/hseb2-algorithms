/*#include<stdexcept>

using namespace std;
#include<iostream>
class A {
public:
	A(int a) {val = a;}
	int value() {return val;}
private:
int val;
};
void main()
try {
	int a = 10;
	throw A(a);
}
catch(A &obj) 
{
	cout << obj.value() << endl;
}*/
/*
using namespace std;
class Excp {};
class A {
public:
	A() try : a(1) { } catch(Excp) { }
private: 
	int a;
};*/

class A {};
class B : public A {};

void f1() throw (A);
void f2() throw (B);

void (*p1)() throw (A) = &f1; // нет ошибки
void (*p2)() throw (A) = &f2; // нет ошибки
void (*p3)() throw (B) = &f1; // ошибка

int main() 
{
	/*try {}
	catch(A *obj) {
	}*/
	return 0;
}






