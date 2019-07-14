#pragma once

class AbstractEngine {                                                       //����������� ����� ��� ����������
protected:
	double T_eng = 0, t = 0;                                                 //�������� ����������� � ������� ������
public:
	AbstractEngine();
	virtual ~AbstractEngine();
	virtual double temp(double Te, double dt, int j)=0;                      //������ ����������� �� dt
};

class Engine: public AbstractEngine{                                          //�������� ��������
private:
	double M, V, Hm, Hv, C;                                                   
	int *MM, *VV, I;
	
public:
	Engine();
	Engine(int i, int MM[], int VV[], double hm, double hv, double C);
	double temp(double Te, double dt, int j);
	double time();                                                           //���������� ������� ����� ������ ���������
	void pre_start(double Te);                                               //���������� ���������� ��������� � ������
	bool cmp(int j);                                                         //��������� V � �������-�������� �������
	~Engine();
};