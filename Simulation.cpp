#include "Simulation.h"

Simulation::Simulation() {};
Simulation::Simulation(Engine eng) { engine = eng; }
double Simulation::Test(double Te, double dt, double T) {
	int j = 0;
	engine.T_eng = Te;
	engine.V = engine.VV[j];
	engine.M = engine.MM[j];
	for (;;) {
		if (engine.temp(Te, dt, j)>=T) return engine.t;
		if (engine.V > engine.VV[j+1]&&j<=5) {
			j++;
		}
	}
}
Simulation::~Simulation() {};
