#include <iostream>
#include <string>
#include <windows.h>
// для своего файла #include "filename.XXX"

using namespace std;

int main (int argc, char* ragv[]) {
	//Set code page

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	// Output code page
	cout << "Code Page		" << GetConsoleCP() << "/" << GetConsoleOutputCP() << endl;
	cout << "Кодовая страница		" << GetConsoleCP() << "/" << GetConsoleOutputCP() << endl;
	// Вывод кириллицы может зависеть от шрифта (SetConsoleCP() влияет на шрифты Юникода)

	for (unsigned char c = 128; c; ++ c) {
		if (c % 16 == 0) cout << endl;
		cout << c;
	}

	cout << "\n\n";
	cout << "Hello world!" << endl;
	cout << "Привет мир!" << endl;
	string s;

	// getline() принимает строку текста, а cin - текст до разделителя (пробела)

	cout << "\n Пожалуйста введите ваше имя\n";
	getline(cin, s); 

	cout << "Здравствуйте " << s << '!' << endl;
	cout << "\n Пожалуйста введите ваше имя\n";
	
	cin >> s;
	cout << "Здравствуйте " << s << '!' << endl;

	/* indicate normal termination */
	system("pause"); // для того чтобы окно не закрылось после окончания

	return EXIT_SUCCESS;
}