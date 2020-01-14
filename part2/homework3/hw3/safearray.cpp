#include "safearray.h"
template<class T>

safearray<T>::safearray(int capacity) : storage(new T[capacity]), capacity(capacity) { }

template <class T> 
safearray<T>::~safearray(void) {
	delete [] storage;
}

template <class T> 
T& safearray<T>::operator[] (int index) const throw(out_of_range) {
	if(index < 0) {
		throw out_of_range("Index is below 0!");
	}
	if(index >= capacity) {
		throw out_of_range("Index is too high!");
	}
	return storage[index];
}