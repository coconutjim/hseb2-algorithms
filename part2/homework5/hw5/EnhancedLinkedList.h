
#include "LinkedList.h"


class ListItemNotFoundException : public logic_error {

public:
    ListItemNotFoundException(const string& what_arg ) throw() :
    logic_error ("Item not found: " + what_arg) { } 
};



template<class T>
class EnhancedLinkedList : public LinkedList<T> {

public:
	T& find_first (const T& key);
	EnhancedLinkedList find_all (const T& key);
	void remove_first (const T& key);
	void remove_all (const T& key);

};

// finds and returns the first item that matches the value in parameter key

template<class T>
T& EnhancedLinkedList<T>::find_first (const T& key) {

	if (count == 0) {
		throw ListItemNotFoundException("List is empty!");
	}
	
	Node<T>* current = head;
    do {
		if (current->getData() == key) {
			return current->getData();
		}
        current = current->getNext();
	} while (current != NULL); // checking existance

	throw ListItemNotFoundException("No such item!");

}



// finds all items that matches the value in parameter key and returns a list of them

template<class T>
EnhancedLinkedList<T> EnhancedLinkedList<T>::find_all (const T& key) {

	EnhancedLinkedList<T> new_list; // the result list

	if (count == 0) {
		return new_list;
	}

	Node<T>* current = head;
    do {
		if (current->getData() == key) {
			new_list.push_back(current->getData());
		}
        current = current->getNext();
	} while (current != NULL); // checking existance

	return new_list;
}


// removes the first item that matches the value in parameter key

template<class T>
void EnhancedLinkedList<T>::remove_first (const T& key) {

	if (count == 0) {
		return;
	}

	if (head->getData() == key) { 
		pop_front(); 
		return; 
	}
	
	Node<T>* current = head->getNext();
	Node<T>* previous = head;

	while (current != NULL) { // checking existance
		if (current->getData() == key) {
			Node<T>* temp; 
			temp = current; 
			current = current->getNext(); 
			previous->getNext() = current; 
			-- count;
			delete temp; 
			return;	
		}
		previous = current;
        current = current->getNext();
	} 

}


// removes all items that matches the value in parameter key

template<class T>
void EnhancedLinkedList<T>::remove_all (const T& key) {

	if (count == 0) {
		return;
	}

	if (head->getData() == key) { 
		pop_front(); 
	}
	
	Node<T>* current = head->getNext();
	Node<T>* previous = head;

    while (current != NULL) { // checking existance
		if (current->getData() == key) {
			Node<T> * temp; 
			temp = current; 
			current = current->getNext(); 
			previous->getNext() = current; 
			-- count; 
			delete temp; 
			continue;
		}
		previous = current;
        current = current->getNext();
	} 

}
