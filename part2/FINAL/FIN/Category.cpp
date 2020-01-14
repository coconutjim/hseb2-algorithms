#include "Category.h"
#include <string>

Category::Category(void) : number(0), parent(0), name("") { }

Category::Category(int parent, string name): number(0), parent(parent), name(name) { }

// Getters

int Category::getNumber(void) const { 
	return number; 
}

int Category::getParent(void) const { 
	return parent; 
}

string Category::getName(void) const { 
	return name; 
}

// Setters

void  Category::setNumber(int number) { 
	this->number = number; 
}

void  Category::setParent(int parent) { 
	this->parent = parent; 
}

void  Category::setName(string name) { 
	this->name = name; 
}


void Category::addSubCategory(Category* sub_one) { 
	sub_categories.push_back(sub_one); 
}


void Category::addItem(int item) { 
	items.push_back(item); 
}

vector<int>::iterator Category::itemsBegin(){ 
	return items.begin(); 
}

vector<int>::iterator Category::itemsEnd() { 
	return items.end(); 
}

vector<Category*>::iterator Category::subCategoriesBegin() { 
	return sub_categories.begin(); 
}

vector<Category*>::iterator Category::subCategoriesEnd() { 
	return sub_categories.end(); 
}

void Category::findOfferings (Listing::iterator start, Listing::iterator finish, 
							  Listing &matches) {
	
	// Checking
	if ( items.empty() ) { 
		return; 
	}

	vector<int>::iterator res;

	for (Listing::iterator it = start; it != finish; ++ it) {
		res = find(this->itemsBegin(), this->itemsEnd(), (*it)->getNumber());

		if (res != this->itemsEnd()) {
			matches.add(*it);
		}
	}
}

void Category::findOfferingsRecursive (Listing::iterator start, Listing::iterator finish, 
									   Listing &matches) {

	this->findOfferings(start, finish, matches);

	for (vector<Category*>::iterator it = this->subCategoriesBegin(); 
			it != this->subCategoriesEnd(); ++ it) {
		(*it)->findOfferingsRecursive (start, finish, matches);
	}

}

bool Category::operator==(const Category& rhs) {
	return number == rhs.getNumber();
}

istream &operator>>(istream &stream, Category &c){
	int parent_id;
	string name;

	string str;
	getline(stream, str);

	parent_id = atoi((str.c_str()));

	getline(stream, name);

	c.setName(name);
	c.setParent(parent_id);
	
	return stream;
}









