#include "Simulation.h"
#include <iostream>
using namespace std;

void main() {
	int MM[] = { 20, 75, 100, 105, 75, 0 }, VV[] = { 0,75,150,200,250,300 };
	Engine eng(10,MM,VV,0.01,0.0001,0.1);
	Simulation simulation(eng);
	double t;
	t = simulation.Test(109, 0.001, 110);
	cout <<" -- "<< t <<endl;

}