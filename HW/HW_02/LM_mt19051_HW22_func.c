
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func(double);
double slope(double);
double nrv (double);
//double slope2(double);

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

/*
Versuch die Ableitung zu approximieren. Gescheiter
je nach potenz ist ergebnis besser/schlechter bis ca -10 stigernde "genauheit" bei -15 kompletter schwachsinn bei -20 0???

frage gibt es bessere methode?
if false: wie finde ich die beste groesse für potenz ohne probieren heraus? (sizeof(double) als int gibt 8 zurück fange ich damit was an?)

double slope2(double x)
{	
	double y = (func(x) - func(x+pow(10,-15)))/(-pow(10,-15));
	return y;
}

*/