#include "safearray.h"

template<class T>
class EnhancedSafeArray : public SafeArray<T> {

public:
	EnhancedSafeArray();
	EnhancedSafeArray(size_t);
	EnhancedSafeArray(const EnhancedSafeArray<T>&);
	size_t size() const;
	EnhancedSafeArray<T>& operator= (const EnhancedSafeArray<T>&);
	bool operator== (const EnhancedSafeArray<T>&) const;

};


// default constructor - invokes constructor of a base class

template<class T>
EnhancedSafeArray<T>::EnhancedSafeArray() : SafeArray() { }

// single-parameter constructor - invokes constructor of a base class

template<class T>
EnhancedSafeArray<T>::EnhancedSafeArray(size_t count) : SafeArray(count) { }

// copy constructor

template<class T>
EnhancedSafeArray<T>::EnhancedSafeArray(const EnhancedSafeArray<T> &obj) {
	count = obj.size();                  // it can be obj.count
	storage = new T[count];  
	for (size_t i = 0; i < count; ++ i) {
		storage[i] = obj[i];
	}
}

// method that returns size

template<class T>
size_t EnhancedSafeArray<T>::size() const {
	return count;
}

// overloaded = operator

template<class T>
EnhancedSafeArray<T>& EnhancedSafeArray<T>::operator= (const EnhancedSafeArray<T> &obj) {
	count = obj.size();	

	if (storage != NULL) {
		delete [] storage;     // cleaning memory (if we need to)
	}


	storage = new T[count];
	for (size_t i = 0; i < count; ++ i) {
		storage[i] = obj[i];
	}
	return *this;
}

// overloaded == operator

template<class T>
bool EnhancedSafeArray<T>::operator== (const EnhancedSafeArray<T> &obj) const {
	if (count != obj.size()) { 
		return false;
	}
	for (size_t i = 0; i < count; ++ i) {
		if (storage[i] != obj[i]) {
			return false;
		}
	}
	return true;
}



