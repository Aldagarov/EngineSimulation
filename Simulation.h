#pragma once
#include "Engine.h"

class Simulation {
public:
	Engine engine;
	Simulation();
	Simulation(Engine engine);
	double Test(double Te, double dt, double T);
	~Simulation();
};