#include <iostream>

#include "Equations.h"

int main() {

	double p0 = 0.4;//initial protein concentration
	double r0 = 0.4;//initial mRNA concentration

	Equations eq(p0, r0);

	eq.calculateCompleteIterations();
	eq.zapiszDoPlikaTXT("yoloyolo.txt");

	system("pause");
	return 0;
}