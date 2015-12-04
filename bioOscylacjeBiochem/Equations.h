#pragma once

#include <iostream>

const int tMax = 200*600;

class Equations
{
public:
	Equations();
	Equations(double p0, double r0);
	~Equations();

	double getDelayedP(int i);

	double calculateNewP(int i);
	double calculateNewR(int i);

	void calculateCompleteIterations();

	void zapiszDoPlikaTXT(std::string nzawa);

private:
	double *r;//mRNA concentration
	double *p;//protein concentration

	const double h = 2;//Hill coeff., h > 1, h~2
	const double k = 0.1;//dissociation constant of protein
	const double kr = (1.0/24.1);//mRNA mortality ~(25 min)^(-1)
	const double kp = (1.0/22.3);//protein mortality ~(25 min)^(-1)
	const double alfa = 1.0;//mRNA production intensity
	const double beta = 0.1;//protein production intensity
	const double deltaT = 0.005;//time step
	const int tau = 20 / deltaT;//length of delay ~10-100 min
};

