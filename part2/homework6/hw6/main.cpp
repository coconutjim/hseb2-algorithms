#include <iostream>
#include <fstream>
#include <stack>
#include "car.h"



int const MAX_CARS = 5;

void car_arrival(ofstream&, stack<Car*>&, const string);
void car_departure(ofstream&, stack<Car*>&, const string);


int main(int argc, char* argv[]) {

	// the first argument is name of exe file
	if (argc != 2) {
		cerr << "Need a filename!" << endl;
		return EXIT_FAILURE;
	}

	// input file
	ifstream ifile(argv[1]);

	if (! ifile) { 
		cerr << "Could not open \"" << argv[1] << "\"!"<< endl;
		return EXIT_FAILURE;
	}

	// simulate the parking lot
	stack<Car*> cars;
	
	// output file
	ofstream ofile("output.txt", ios::trunc);

	// reading file and writing data to other one
	string license, action;
	while (! ifile.eof()) {

		// processing the data
		ifile >> license;
		ifile >> action;

		// if the car arrives
		if (action == "arrives") {
			car_arrival(ofile, cars, license);
		}

		// if the car departs
		if (action == "departs") {
			car_departure(ofile, cars, license);
		}			
	}

	// remaining cars (we can "depart" them)
	while (! cars.empty()) {
		car_departure(ofile, cars, cars.top()->getLicense());
	}


	ifile.close();
	ofile.close();

	cout << "Done." << endl;

	return EXIT_SUCCESS;
}

void car_arrival(ofstream& ofile, stack<Car*>& cars, const string license) {
	
	// checking if there is space
	if (cars.size() == MAX_CARS) {
		ofile << "Sorry " << license << ", the lot is full" << endl;
		return;
	}

	cars.push(new Car(license, 0));
}

void car_departure(ofstream& ofile, stack<Car*>& cars, const string license) {

	stack<Car*> temp_cars;
	// checking license_plate
	Car* car = cars.top();
	while (car->getLicense() != license) {
		car->moved();
		temp_cars.push(car);
		cars.pop();

		car = cars.top();
	}

	// if this is needed car
	ofile << car->getLicense() << " was moved " << car->getNumber() << " since it was here" << endl;
	cars.pop();

	delete car;

	// returning cars
	while (! temp_cars.empty()) {
		cars.push(temp_cars.top());
		temp_cars.pop();
	}
}
