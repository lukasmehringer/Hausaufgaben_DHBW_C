
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func(double);
double slope(double);
double nrv (double);

double nrv(double cval)
{
	cval -= func(cval)/slope(cval);
	return cval;
}

double func(double x)
{
	double y = pow((x-3),2);
	return y;
}

double slope(double x)
{
	double y = 2*(x-3);
	return y;
}

