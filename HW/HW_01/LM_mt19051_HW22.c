//name: Lukas Mehringer
//student ID: mt19051
//HW21
//technical support by Henry Bai (mt19078)
//culinary support by Greta Mehringer

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "LM_mt19051_HW22.h"


int main()
{
	double (*funcpointer) (double);
	funcpointer = func;
	
	double (*slope2pointer) (double);
	slope2pointer = slope2;
	
	double (*nrvpointer) (double);
	nrvpointer = nrv;
	
	
	
	/* 
	Teil von versuchsaufbau 
	printf("%lf\n",slope(8));
	printf("%lf\n\n",slope2(8));
	*/
	
	
	double res = pow(10,-20); //resolution
	int leny = pow(10,4);
	double stval = 5;			//start value
	
	double inres [3][leny];		//arrey for values 
	
	//insert and print of first row
	
	printf("pass:\tfunc val:\tzero pos:\n--------------------------------------\n");
	
	inres[2][0]=stval;
	inres[1][0]=funcpointer(stval);
	inres[0][0]=1;
	
	printf("%.0lf",inres[0][0]);
	printf("\t%lf",inres[1][0]);
	printf("\t%lf",inres[2][0]);
	
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
		inres[2][row] = nrv(inres[2][(row-1)]);
		inres[1][row] = funcpointer (inres[2][row]);
		inres[0][row] = (double)(row+1);
		printf("\n%.0lf",inres[0][row]);
		printf("\t%lf",inres[1][row]);
		printf("\t%lf",inres[2][row]);
		row++;
	}
	while(((fabs(inres[1][(row - 2)]) - fabs(inres[1][(row - 1)])) >= res) && row != (leny) ); //while either stops when arrey is full or the necessary resolution is reached
	
	printf ("\n\nOne zero position of the given function is at %.3lf",inres[2][(row-1)]);
}