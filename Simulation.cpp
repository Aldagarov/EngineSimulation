#include "Simulation.h"


AbstractSimulation::AbstractSimulation() {};
AbstractSimulation::~AbstractSimulation() {};

Simulation::Simulation() {};
Simulation::Simulation(Engine eng) { engine = eng; }

double Simulation::Test(double Te, double dt, double T) {
	int j = 0;                                                              //флаг для переходов кусочно-линейной ф-ции
	engine.pre_start(Te);                                                   //подготовка двигателя
	for (;;) {                                                              
		if (engine.temp(Te, dt, j)>=T) return engine.time();                //изменение температуры и проверка на перегрев
		if (engine.cmp(j)) {j++;}                                           
	}
}
Simulation::~Simulation() {};
