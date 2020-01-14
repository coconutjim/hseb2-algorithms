#include "Group.h"

Client* Group::operator[](const string& email)
{
    for (Group::iterator it = this->begin(); it != this->end(); ++ it) {
        if ((*it)->getEmail() == email) {
            return *it;
        }
    }

	return NULL;
}

void Group::add(Client* ptr)
{
	objects.push_back(ptr);
}

Group::iterator Group::begin()
{
	return objects.begin();
}

Group::iterator Group::end()
{
	return objects.end();
}