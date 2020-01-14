#ifndef  _DICTIONARY_H_ 
#define  _DICTIONARY_H_

#include  <iostream>
#include  <vector>
#include  <list>
#include  <algorithm>
#include  <string>

#include  "hashset.h"
#include  "hashset.cpp"

using namespace std;

class hash_function
{
public:
    hash_function() {}

	// Function
    unsigned int operator()( const string& s )  const {
		
		unsigned int hash = 0;

		for (int i = 0; i < s.size(); ++ i) {
			hash += s[i];
			hash += (hash << 10);
			hash ^= (hash >> 6);
		}
		hash += (hash << 3);
		hash ^= (hash >> 11);
		hash += (hash << 15);

    return hash;
	}
};

class equality
{
public:
    equality() {}
    bool  operator()( const string& A, const string& B )  const {
		return  (A == B);
    }
};

class Dictionary: public HashSet<string, hash_function, equality> {

public:
	Dictionary(const string& filename);

};

#endif
