#pragma warning (disable:4786)
#pragma warning (disable:4503)

#include "RailSystem.h"
#include "limits.h"

void RailSystem::reset(void) {

	// TODO: reset the data objects of the 
    // City objects' contained in cities

	for (map<string, City*>::iterator it = cities.begin(); it != cities.end(); ++ it) {
		it->second->visited = false;
		it->second->total_fee = 0;
		it->second->total_distance = 0;
		it->second->from_city = "";
	}
}

RailSystem::RailSystem(string const &filename) {

	load_services(filename);
}

void RailSystem::load_services(string const &filename) {

	ifstream inf(filename.c_str());
	string from, to;
	int fee, distance;

	while ( inf.good() ) {

		// Read in the from city, to city, the fee, and distance.
		inf >> from >> to >> fee >> distance;

		if ( inf.good() ) {

			// TODO: Add entries in the cities container and
			// and services in the rail system for the new 
            // cities we read in.	

			if (cities.find(from) == cities.end()) {
				cities[from] = new City(from);
			}
			if (cities.find(to) == cities.end()) {
				cities[to] = new City(to);
			}
			if (outgoing_services.find(from) == outgoing_services.end()) {
				list<Service*> list;
				outgoing_services[from] = list;
			}
			outgoing_services[from].push_back(new Service(to, fee, distance));

		}
	}


	inf.close();
}

RailSystem::~RailSystem(void) {

	// TODO: release all the City* and Service*
    // from cities and outgoing_services

	for (map<string, City*>::iterator it = cities.begin(); it != cities.end(); ++ it) {
		delete it->second;
	}
	for (map<string, list<Service*> >::iterator itList = outgoing_services.begin(); 
		itList != outgoing_services.end(); ++ itList) {
		for (list<Service*>::iterator it = itList->second.begin(); it != itList->second.end(); ++ it) {
			delete *it;
		}
	}
}

void RailSystem::output_cheapest_route(const string& from,
	const string& to, ostream& out) {

		reset();
		pair<int, int> totals = calc_route(from, to);

		if (totals.first == INT_MAX) {
			out << "There is no route from " << from << " to " << to << "\n";
		} else {
			out << "The cheapest route from " << from << " to " << to << "\n";
			out << "costs " << totals.first << " euros and spans " << totals.second
				<< " kilometers\n";
			cout << recover_route(to) << "\n\n";
		}
}

bool RailSystem::is_valid_city(const string& name) {

	return cities.count(name) == 1;
}

pair<int, int> RailSystem::calc_route(string from, string to) {

	vector<City*>  candidates;

	for (std::map<string, City*>::iterator it = cities.begin(); it != cities.end(); ++ it) {
		if (it->first != from) {
			it->second->total_fee = INT_MAX;
		}
		candidates.push_back(it->second);
	}   

	// TODO: Implement Dijkstra's shortest path algorithm to
	// find the cheapest route between the cities

	while (candidates.size() != 0) {
		City* u = *candidates.begin();
		int temp = 0;
		for (int i = 0, limit = candidates.size(); i < limit; ++ i) {
			if (candidates[i]->total_fee<u->total_fee) {
				u = candidates[i];
				temp=i;
			}
		}
		City *temp_city = candidates.back();
		candidates.back() = candidates[temp];
		candidates[temp] = temp_city;      
		candidates.pop_back();
		if (u->total_fee == INT_MAX) {
			break;
		}
		u->visited = true;
		for (vector<City*>::iterator it = candidates.begin(); it != candidates.end(); ++ it) {           
			for (list<Service*>::iterator itList = outgoing_services[u->name].begin(); 
				itList != outgoing_services[u->name].end(); ++ itList) {
				if ((*itList)->destination == (*it)->name) {
					City* v = cities[(*it)->name];
					int alt = (u->total_fee + (*itList)->fee);
					if (v->total_fee > alt) {
						v->total_fee = alt;
						v->total_distance = u->total_distance + (*itList)->distance;
						v->from_city = u->name;                           
					}
				}            
			}
		}
	}


	// Return the total fee and total distance.
	// Return (INT_MAX, INT_MAX) if not path is found.
	if (cities[to]->visited) {
		return pair<int,int>(cities[to]->total_fee, cities[to]->total_distance);
	} else {
		return pair<int,int>(INT_MAX, INT_MAX);
	}

}

string RailSystem::recover_route(const string& city) {

	// TODO: walk backwards through the cities
	// container to recover the route we found

	City* temp = cities[city];
	string result = temp->name;
	temp = cities[temp->from_city];
	while(temp->from_city != "") {
		result = temp->name + " to " + result;
		temp = cities[temp->from_city];
	}
	result = temp->name + " to " + result;
	return result;
}
