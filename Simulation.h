#pragma once
#include "Engine.h"

class AbstractSimulation
{
public:
	AbstractSimulation();
	virtual double Test(double Te, double dt, double T)=0;
	~AbstractSimulation();	
};

class Simulation: public AbstractSimulation {
private:
	Engine engine;
public:	
	Simulation();
	Simulation(Engine engine);
	double Test(double Te, double dt, double T);
	~Simulation();
};