#include <string>
using namespace std;

class Car {
private:
	// fields
	string license;
	int number;
public:
	// empty constuctor
	Car();
	// constructor with data
	Car(string license, int number);
	// setters
	void setLicense(const string&);
	void setNumber(const int);
	// getters
	string getLicense() const;
	int getNumber() const;
	// if the car is moved
	void moved();
};