#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <set>

#include "dictionary.h"

using namespace std;

void lower(string& s);
string strip_punct(const string& s);
void check_spelling(ifstream& in, Dictionary& dict);
void make_suggestion(Dictionary&, const string&, set<string>&);


int main(int argc, char* argv[]) {

	// Output usage message if improper command line args were given.
	if (argc != 3) {
		cerr << "Usage: " << argv[0] << " wordlist_filename input_file\n";
		return EXIT_FAILURE;
	}

	ifstream inf(argv[2]);
	if (! inf) {
		cerr << "Could not open " << argv[2] << "\n";
		return EXIT_FAILURE;
	}

	// Read dictionary, but let user know what we are working on.
	cout << "Loading dictionary, this may take awhile...\n";

	Dictionary d(argv[1]);

	check_spelling(inf, d);

	inf.close();

	system("pause");
	return EXIT_SUCCESS;
}

void check_spelling(ifstream& in, Dictionary& dict) {

	int line_number = 0;

	while (in) {

		line_number++;

		string line;
		getline(in, line);

  	    stringstream ss (stringstream::in | stringstream::out);
		ss << line;

		string word;
		while (ss >> word) {
			
            // TODO: Complete the spell check of each word
			word = strip_punct(word);
			lower(word);
			
			// Checking
			if (! dict.search(word)) { 
				set <string> suggestions;
				//string temp_word;

				for (int i = 0; i < word.size(); ++ i) {

					if (i != 0) {

						// Swapping
						swap(word[i - 1], word[i]);
						make_suggestion(dict, word, suggestions);

						swap(word[i - 1], word[i]);
					}

					if (word.size() > 1) {

						// Removing
						make_suggestion(dict, word.substr(0, i) + word.substr(i + 1), suggestions);
					}

					for (char initial, c = 'a'; c <= 'z'; c ++) {

						// Replacing
						make_suggestion(dict, word.substr(0, i) + string(1, c) + word.substr(i + 1), suggestions);

						// Inserting
						make_suggestion(dict, word.substr(0, i) + string(1, c) + word.substr(i), suggestions);

						if (i == word.size() - 1) { 
							make_suggestion(dict, word + string(1, c), suggestions); 
						}
					}
				}
				
				cout << "line " << line_number << ": '" << word << "'\n\tsuggestions:";
				if (suggestions.empty()) {
					cout << "\n\t\tno matches found";
					continue;
				}
				
				for (set<string>::const_iterator it = suggestions.begin(); it != suggestions.end(); ++ it) {
					cout <<  "\n\t\t" << *it;
				}
				cout << endl;
			}

		}

	}

}

void lower(string& s) {

    // Ensures that a word is lowercase
	for (int i = 0; i < s.length(); i++) {
		s[i] = tolower(s[i]);
	}
}

string strip_punct(const string& s) {

	// Remove any single trailing
	// punctuation character from a word.  
	if (ispunct(s[s.length() - 1]) ) {
		return s.substr (0, s.length() - 1);
	}
	else {
		return s;
	}
}

void make_suggestion(Dictionary& dict, const string& word, set<string>& suggestions) {
	if (dict.search(word)) suggestions.insert(word);
}
