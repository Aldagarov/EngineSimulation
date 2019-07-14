#pragma once

class AbstractEngine {                                                       //Абстрактный класс для двигателей
protected:
	double T_eng = 0, t = 0;                                                 //Значения температуры и времени работы
public:
	AbstractEngine();
	virtual ~AbstractEngine();
	virtual double temp(double Te, double dt, int j)=0;                      //расчёт температуры по dt
};

class Engine: public AbstractEngine{                                          //исходный двигател
private:
	double M, V, Hm, Hv, C;                                                   
	int *MM, *VV, I;
	
public:
	Engine();
	Engine(int i, int MM[], int VV[], double hm, double hv, double C);
	double temp(double Te, double dt, int j);
	double time();                                                           //возвращает текущее время работы двигателя
	void pre_start(double Te);                                               //подготовка параметров двигателя к старту
	bool cmp(int j);                                                         //сравнение V к кусочно-линейной функции
	~Engine();
};