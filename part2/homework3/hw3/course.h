#ifndef COURSE_H
#define COURSE_H

int const MAX_LINES = 10;

#include "safearray.cpp"

class course {

  public:
    string name;
    string title;
    safearray<string> description;
     
	course() : name(""), title(""), description(safearray<string>(MAX_LINES)) {}
    course(string name, string title) : 
		name(name), title(title), description(safearray<string>(MAX_LINES)) {}

    friend ostream& operator<<(ostream&, const course&);        
    friend istream& operator>>(istream&, course&);
};

ostream& operator<<(ostream& out, const course& c) {

    out << c.name << ": " << c.title << "\n";

    int index = 0;

	try {
		while (c.description[index] != "") {
		 out << c.description[index++] << "\n";    
		}
	}
	catch (out_of_range &e){
		// Nothing to do : expectable situation with fully filled array
	}

    return out;
}

istream& operator>>(istream& in, course& c) {

    getline(in, c.name);
    getline(in, c.title);

    string line;
    getline(in, line);
    int number = 0;
	// With different text files program may crash, we must fix it:
	try {
		while (line != "") {
		 c.description[number++] = line;
		 getline(in, line);
		}
	}
	catch (out_of_range &e) {
		cerr << e.what() << endl;
	}
    
    return in;
}

#endif
