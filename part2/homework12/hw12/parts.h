// parts.h

#ifndef _PARTS_H_
#define _PARTS_H_

#include <vector>
#include <map>
#include <string>

using namespace std;

//**************** Part ****************
class Part {
	
public:
	string name;

	// TODO: Finish declaration
	map<Part*, int> quantityMap;
	Part(string const &n) : name(n) {};
	void describe(void);
	int count_howmany(Part const *p);
};


//**************** NameContainer ****************
class NameContainer  {

private:
	map<string,Part*> name_map;

public:
	NameContainer(void) {};

	// Destructor
	~NameContainer() {
		for (map<string,Part*>::iterator it = name_map.begin(); it!= name_map.end(); it++){
			delete it->second;
		}
	};

	Part* lookup(string const &name) {
    
        // TODO: Finish implementation
		map<string, Part*>::iterator it = name_map.find(name);
		if (it != name_map.end()) {
			return it->second;
		}
		else {
			Part* part = new Part(name);
			name_map.insert(pair<string,Part*>(name, part));
			return part;
		}
	}
};

NameContainer partContainer;

//**************** Part Member Functions ****************
void Part::describe(void) {
	
    // TODO: Finish implementation
	cout << "Part "<< name <<" subparts are:" << endl;
	if (quantityMap.empty()){
		cout << "\tIt has no subparts" << endl;
		return;
	}
	for (map<Part*, int>::iterator it = quantityMap.begin(); it != quantityMap.end(); it++){
		cout <<"\t" << it->second <<" " << it->first->name << endl;
	}
}

int Part::count_howmany(Part const *p) {
		
    // TODO: Finish implementation
	if (name == p->name){
		return 1;
	}
	int sum = 0;
	for (map<Part*,int>::iterator it = quantityMap.begin(); it != quantityMap.end(); it++){
		sum += it->second*(it->first->count_howmany(p));
	}
	return sum;
}

//**************** Miscellaneous Functions ****************
void add_part(string const &x, int q, string const &y) {

    // TODO: Finish implementation
	Part* container = partContainer.lookup(x);
	Part* content = partContainer.lookup(y);
	map<Part*, int>::iterator it = container->quantityMap.find(content);
	if (it != container->quantityMap.end()){
		it->second += q;
	}
	else {
		container->quantityMap.insert(pair<Part*, int>(content, q));
	}
}

#endif
