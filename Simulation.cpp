#include "Simulation.h"


AbstractSimulation::AbstractSimulation() {};
AbstractSimulation::~AbstractSimulation() {};

Simulation::Simulation() {};
Simulation::Simulation(Engine eng) { engine = eng; }
double Simulation::Test(double Te, double dt, double T) {
	int j = 0;
	engine.start(Te);
	for (;;) {
		if (engine.temp(Te, dt, j)>=T) return engine.time();
		if (engine.cmp(j)) {j++;}
	}
}
Simulation::~Simulation() {};
