#include "Simulation.h"
#include <iostream>
using namespace std;

void main() {
	int MM[] = { 20, 75, 100, 105, 75, 0 }, VV[] = { 0,75,150,200,250,300 };
	AbstractSimulation *simulation = new Simulation(Engine(10, MM, VV, 0.01, 0.0001, 0.1));
	double Te;
	char flag;
	for (;;) {
		cout << "Please, enter ambient temperature, C*: " << endl;
		cin >> Te;
		if (Te >= 110) {                                                   //двигатель уже "перегрет"
			cout << "Engine	overheating time: " << 0 << endl; }
		else if (Te <= 20) {                                               //охлаждение = нагреванию, расходящийся ряд
			cout << "Engine overheating time: " << "inf" << endl; }
		else {                                                             
			cout << "Engine overheating time: ";
			cout << simulation->Test(Te, 0.001, 110) << endl;
		}
		cout << '/' << endl << '/'<<endl;
		cin.clear();
		cin.ignore(10000, '\n');                                           //если введён не верный символ
		cout << "Continue the simulation?: [y/n] " << endl;
		cin >> flag;
		if (flag == 'n') { break; }
		cout << endl;
	}
	system("pause");
}