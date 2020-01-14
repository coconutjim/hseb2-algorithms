#include "Listing.h"

void Listing::add(Advertisement* ptr) {
	objects.push_back(ptr);
}

Listing::iterator Listing::begin() {
	return objects.begin();
}

Listing::iterator Listing::end() {
	return objects.end();
}

Advertisement* Listing::operator[](const int& number) {
	
    for (Listing::iterator it = this->begin(); it != this->end(); ++ it) {
        if ((*it)->getNumber() == number) {
            return *it;
        }
    }

    return NULL;
}