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
	  t += dt;                                                                 //текущее время
	  V += M * dt / I;                                                         //изменение V по dt
	  M = MM[j] + (V - VV[j]) * (MM[j + 1] - MM[j]) / (VV[j + 1] - VV[j]);	   //расчёт M из кусочно-линейной зависимости
	                                                                           //(прямая по двум точкам)
	  T_eng = T_eng + M*Hm*dt + V*V*Hv*dt+C*(Te - T_eng)*dt;                   //расчёт температуры
	  return T_eng;
 }

 void Engine::pre_start(double Te) {
	 V = VV[0];
	 M = MM[0];
	 T_eng= Te;                                                                //Т двигателя = Т окружающей среды
	 t = 0;                                                                   
 }
 bool Engine::cmp(int j) {
	 return V >= VV[j + 1];
 }
 double Engine::time() {
	 return t;
 }
 Engine::~Engine() {};