#include "Engine.h"

AbstractEngine::AbstractEngine() {};
AbstractEngine::~AbstractEngine() {};


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
	  V += M * dt / I;
	  M = MM[j] + (V - VV[j]) * (MM[j + 1] - MM[j]) / (VV[j + 1] - VV[j]);	 
	  T_eng = T_eng + M*Hm*dt + V*V*Hv*dt+C*(Te - T_eng)*dt;
	  return T_eng;
 }

 void Engine::start(double Te) {
	 V = VV[0];
	 M = MM[0];
	 T_eng= Te;
	 t = 0;
 }
 bool Engine::cmp(int j) {
	 return V >= VV[j + 1];
 }
 double Engine::time() {
	 return t;
 }
 Engine::~Engine() {};