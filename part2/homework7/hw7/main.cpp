#pragma warning(disable:4786)

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <stack>
#include <stdexcept>
#include <vector>
#include <algorithm>

#include "car.h"

using namespace std;

const int PARKING_SPOTS_PER_AISLE = 3;
const int NUMBER_OF_AISLES = 5;

void handle_arrival(vector<Car>&, vector<stack<string> >&, const string&);
void handle_departure(vector<Car>&, vector<stack<string> >&, const string&);
Car& find_car(vector<Car>&, string);

int main(int argc, char* argv[]) {

    try {

        if (argc != 2) {
            cerr << "Usage:\n" << argv[0] << " data-file";
            return EXIT_FAILURE;
        }    

        ifstream inf(argv[1]);
        if (! inf) {
            cerr << "Could not open " << argv[1];
            return EXIT_FAILURE;
        }

		vector<Car> cars;
		vector< stack<string> > parking_lot(NUMBER_OF_AISLES);

        while (! inf.eof()) {
        
            string action, plate;
            inf >> plate >> action;
        
            if (action == "arrives") {
                handle_arrival(cars, parking_lot, plate);
            } 
            else if (action == "departs") {
                handle_departure(cars, parking_lot, plate);            
            } else {
                cerr << "Unknown action: " << action << endl;
            }
        
        }
        inf.close();    

        cout << "\nHere are all the cars that visited the lot today:\n";

        // TODO: Output the license plates of all the
        // cars that visited the lot, in alphabetical order		
		sort(cars.begin(), cars.end());
		vector<Car>::iterator it = cars.begin();
        for ( ; it != cars.end(); it++) {
            cout << it->getPlate() << endl;
        }

        return EXIT_SUCCESS;
        
    }
    catch (exception& e) {
        cerr << e.what() << endl;
    }
    catch (...) {
        cerr << "Unknown exception caught!" << endl;
    }
    
    return EXIT_FAILURE;
}

void handle_arrival(vector<Car>& cars, vector< stack<string> >& parking_lot, const string& plate) {

    // TODO: Handle car arrivals

	for (size_t i = 0; i < NUMBER_OF_AISLES; ++ i) {
		if (parking_lot[i].size() < PARKING_SPOTS_PER_AISLE) {
			parking_lot[i].push(plate);
			cars.push_back(Car(plate, i));
			return;
		}
	}

	cout << "Sorry " << plate << ", no place for you"<< endl;

}

void handle_departure(vector<Car>& cars, vector< stack<string> >& parking_lot, const string& plate) {

    // TODO: Handle car departures

	Car depart = find_car(cars, plate);

	stack<string>& current_aisle = parking_lot[depart.getAisle()];

	stack<string> temp_cars;
	// checking license_plate and moving from one stack to another
	string temp_plate = current_aisle.top();
	while (temp_plate != plate) {
		Car& temp = find_car(cars, temp_plate);
		temp.setTimesMoved(temp.getTimesMoved() + 1);
		temp_cars.push(temp_plate);
		current_aisle.pop();

		temp_plate = current_aisle.top();
	}

	// if this is needed car
	cout << plate << " was moved " << depart.getTimesMoved() << " since it was here" << endl;
	current_aisle.pop();

	// returning cars
	while (! temp_cars.empty()) {
		current_aisle.push(temp_cars.top());
		temp_cars.pop();
	}


}

Car& find_car(vector<Car>& cars, string plate) {

	// TODO: Return a reference to the 
	// the Car object whose license plate equals 
	// the parameter 'plate'

	Car temp = Car(plate);
	vector<Car>::iterator result = find(cars.begin(), cars.end(), temp);

	return *result;

}
