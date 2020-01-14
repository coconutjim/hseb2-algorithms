#include "fifo.h"
#include <fstream>

fifo::fifo(int seconds_per_page) : simulator(seconds_per_page) { }

void fifo::simulate(string file) {

	// loading data from file
	loadworkload(file);

	// output file
	file.erase(file.find("."), file.length());
	file.append(".out");
	ofstream ofile(file, ios::trunc);

	if (workload.empty()) {
		ofile << "Nothing to print" << endl;
		ofile.close();
		return;
	}

	// total documents
	int total = 0;
	// aggregate latency
	int latency = 0;

	ofile << "FIFO Simulation" << endl;
	ofile << endl;

	// next time when the printer will be free to serve
	int next = 0;

	for (int seconds = 0; ! ( workload.empty() && waiting.empty() ); ++ seconds) {

		// if there is smth to arrive
		while (! workload.empty() && seconds >= workload.front().arrival_time()) {
			event e = workload.front();
			workload.pop();
			waiting.push(e);
			ofile << "\tArriving: " << e.getjob() << " at "<< seconds << " seconds" << endl;
		}

		// if there is smth to serve
		if (seconds >= next && ! waiting.empty()) {
			event e = waiting.front();
			ofile << "\tServicing: " << e.getjob() << " at " << seconds << " seconds" << endl;
			waiting.pop();
			// counting when the printer will be free to serve
			next = seconds + seconds_per_page * e.getjob().getnumpages();

			latency += seconds - e.arrival_time();
			++ total;
		}
	}

	// Printing the result
	ofile << endl;
	ofile << "\tTotal jobs: " << total << endl;
	ofile << "\tAggregate latency: " << latency << " seconds" << endl;
	ofile << "\tMean latency: " << (float)latency / (float)total << " seconds" << endl;

	ofile.close();
}

