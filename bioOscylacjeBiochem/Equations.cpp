#include "Equations.h"

#include <fstream>
#include <sstream>


Equations::Equations()
{
}

Equations::Equations(double p0, double r0)
{
	p = new double[tMax];
	r = new double[tMax];

	p[0] = p0;
	r[0] = r0;
}


Equations::~Equations()
{
}

double Equations::getDelayedP(int i)
{
	if (i < 0)
		return 0.0;// p[0];
	return p[i];
}

double Equations::calculateNewP(int i)
{
	double newP = p[i - 1];
	newP += deltaT*(beta*r[i - 1] - kp*p[i - 1]);
	return newP;
}

double Equations::calculateNewR(int i)
{
	double newR = r[i - 1];
	newR += deltaT*((alfa*pow(k, h)) / (pow(k, h) + pow(getDelayedP(i - 1 - tau), h)) - kr*r[i - 1]);
	return newR;
}


void Equations::calculateCompleteIterations()
{
	for (size_t i = 1; i < tMax; i++)
	{
		p[i] = calculateNewP(i);
		r[i] = calculateNewR(i);
		//if (i % 10)
			//std::cout << p[i] << ";" << r[i] << std::endl;
	}
}

void Equations::zapiszDoPlikaTXT(std::string nzawa){

	std::ofstream file(nzawa);


	for (size_t i = 0; i < tMax; i++)
	{
		if (i % 10) {
			std::stringstream ss;
			ss << i*0.005 << ";" << p[i] << "; " << r[i];
			file << ss.str() << std::endl;
		}
	}

	file.close();
}
