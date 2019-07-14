#pragma once
#include "Engine.h"

class AbstractSimulation                                               //јбстрактный класс дл€ симул€ций
{
public:
	AbstractSimulation();
	virtual double Test(double Te, double dt, double T)=0;             //метод запуска симул€ции
	virtual ~AbstractSimulation();	
};

class Simulation: public AbstractSimulation {                          //исходна€ симул€ци€
private:
	Engine engine;
public:	
	Simulation();
	Simulation(Engine engine);
	double Test(double Te, double dt, double T);                       
	~Simulation();
};