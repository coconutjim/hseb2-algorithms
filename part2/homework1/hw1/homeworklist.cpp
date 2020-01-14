#include "homeworklist.h"
#include "date.h"

homeworklist::homeworklist() : current_size(0) { }

bool homeworklist::add(homework h) {
	if (current_size < 50) {
		list[current_size] = h;
		++ current_size;
		return true;
	}
	else {
		return false;
	}
}

homeworklist homeworklist::dueafter(date d) {
	homeworklist newList = homeworklist();
	homework temp = homework("", d, d); // forced to create a new homework instance
	for (int i = 0; i < current_size; ++ i) {
		if (list[i].compareTo(temp) == 1) { 
			newList.add(list[i]);
		}
	}
	return newList;
}

homeworklist homeworklist::duebefore(date d) {
	homeworklist newList = homeworklist();
	homework temp = homework("", d, d); // forced to create a new homework instance
	for (int i = 0; i < current_size; ++ i) {
		if (list[i].compareTo(temp) == -1) { 
			newList.add(list[i]);
		}
	}
	return newList;
}

homeworklist homeworklist::dueon(date d) {
	homeworklist newList = homeworklist();
	homework temp = homework("", d, d); // forced to create a new homework instance
	for (int i = 0; i < current_size; ++ i) {
		if (list[i].compareTo(temp) == 0) { 
			newList.add(list[i]);
		}
	}
	return newList;
}

ostream &operator<< (ostream &stream, homeworklist hl) {
	for (int i = 0; i < hl.current_size; ++ i) {
		stream << hl.list[i] << endl;
	}
	return stream;
}