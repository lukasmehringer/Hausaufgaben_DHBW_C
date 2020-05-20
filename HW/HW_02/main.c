/*
Programmed by Christean Lutz und Lukas Mehringer
Student ID: mt19048 & mt19051
HW2 
Calculator for imagenary nummbers 
*/

/*
Questions:
1. Is it possible to pass a complete  object array/objects in array to fnc? 
For example: pass cns numers[] to fnc, to read out all numbers and write solution into an extra object in the array
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "fcn.h"

int main(){

    cns numbers[3];
    char op[1];

    printf("insert first num:");
    gets(numbers[0].num);
    parsingfcn(&numbers[0]);
   
    printf("\ninsert operator:");
    gets(op);

    printf("insert second num:");
    gets(numbers[1].num);
    parsingfcn(&numbers[1]);

    calc(numbers[0], numbers[1], &numbers[2], op[0]);

    resprint(&numbers[2]);

   return 0;
}