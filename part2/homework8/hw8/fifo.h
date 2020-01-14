#include "simulator.h"

class fifo : public simulator {

private:
	queue<event> waiting;

public:
	fifo(int seconds_per_page);
	virtual void simulate(string file);
};