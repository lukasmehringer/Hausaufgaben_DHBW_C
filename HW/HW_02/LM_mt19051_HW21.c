//name: Lukas Mehringer
//student ID: mt19051
//HW21
//technical support by Henry Bai (mt19078)
//culinary support by Greta Mehringer

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func(double);
double slope(double);
double nrv (double);

int main()
{
	double res = pow(10,-20); //resolution
	int leny = pow(10,4);
	double stval = 5;			//start value
	
	double insol [3][leny];		//arrey for values 
	
	//insert and print of first row
	insol[2][0]=stval;
	insol[1][0]=func(stval);
	insol[0][0]=1;
	
	printf("\n%lf",insol[0][0]);
	printf("\t%lf",insol[1][0]);
	printf("\t%lf",insol[2][0]);
	
	/*
	
	print and calculate further values 
	columm		description
	0 			pass
	1 			func values => goes to 0
	2 			approximated zero position
	
	*/
	int row = 1;
	do 
	{
		insol[2][row] = nrv(insol[2][(row-1)]);
		insol[1][row] = func (insol[2][row]);
		insol[0][row] = (double)(row+1);
		printf("\n%lf",insol[0][row]);
		printf("\t%lf",insol[1][row]);
		printf("\t%lf",insol[2][row]);
		row++;
	}
	while(((fabs(insol[1][(row - 2)]) - fabs(insol[1][(row - 1)])) >= res) && row != (leny) ); //while stops either when arrey is full or the necessary resolution is reached
	
	printf ("\n\nOne zero position of the given function is at %.3lf",insol[2][(row-1)]);
}

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

