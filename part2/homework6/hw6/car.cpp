#include "car.h"

// realization of constructors

Car::Car() : license(""), number(0) { }

Car::Car(string license, int number) : license(license), number(number) { }

// realization of setters and getters

void Car::setLicense(const string &license) {
	this->license = license;
}

void Car::setNumber(const int number) {
	this->number = number;
}

string Car::getLicense() const {
	return license;
}

int Car::getNumber() const {
	return number;
}

// if the car is moved

void Car::moved() {
	++ number;
}