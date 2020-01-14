#include "Categories.h"

using namespace std;

// Constants
const int Categories::NO_PARENT = 0;
const int Categories::TOP_LEVEL = 0;

void Categories::add(Category* ptr) {
    objects.push_back (ptr);
}

Category* Categories::operator[](const int& number) {

    for (Categories::iterator it = this->begin(); it != this->end(); it++) {
        if ((*it)->getNumber() == number) {
            return *it;
        }
    }

    return NULL;
}

Categories::iterator Categories::begin() {
    return objects.begin();
}

Categories::iterator Categories::end() {
    return objects.end();
}

