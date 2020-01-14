#include<fstream>

#include "dictionary.h"

using namespace std;

Dictionary::Dictionary(const string& filename) {
	ifstream in; 

	in.open(filename.c_str());
	if (! in) { 
		cerr << "Problems with openning the file occured" << endl;
		exit(EXIT_FAILURE);
	}

	string word;
	int i = 0;
	while (! in.eof()) {
		in >> word;
		insert(word);
	}

	in.close();
}