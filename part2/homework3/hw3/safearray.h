#ifndef SAFEARRAY_H
#define SAFEARRAY_H
#include <stdexcept>
using namespace std;

template <class T> 
class safearray {

  private:
    T *storage;
    int capacity;
  
  public:
    safearray() : storage(NULL), capacity(0) {} // default constructor
    safearray(int); // single param constructor
    ~safearray(void); // destructor
    T& operator[] (int) const throw(out_of_range);
};

#endif
