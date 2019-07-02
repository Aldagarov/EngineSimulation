#include "Engine.h"

Engine::Engine() {};

 Engine::Engine(int i, int mm[], int vv[], double hm, double hv, double c) {
	 I = i;
	 MM = mm;
	 VV = vv;
	 Hm = hm;
	 Hv = hv;
	 C = c;
}
 double Engine::temp(double Te, double dt, int j) {	 
	 t += dt;
	 if (j >= 5) {
		 M = 0; V = 300;
	 }
	 else {
		 V += M * dt / I;
		 M = MM[j] + (V - VV[j]) * (MM[j + 1] - MM[j]) / (VV[j + 1] - VV[j]);
	 }
	 //if (M * Hm * dt + V * V * Hv * dt + C * (Te - T_eng) * dt<=0.0001) return 110;
	 T_eng = T_eng + M*Hm*dt + V*V*Hv*dt+C*(Te - T_eng)*dt;
	 return T_eng;
 }
 Engine::~Engine() {};