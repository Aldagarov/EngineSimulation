#pragma once

class Engine {
public:
	double M, V, Hm, Hv, C;
	int *MM, *VV, I;
	double T_eng = 0, t = 0;
	Engine();
	Engine(int i, int MM[], int VV[], double hm, double hv, double C);
	double temp(double Te, double dt, int j);
	~Engine();
};