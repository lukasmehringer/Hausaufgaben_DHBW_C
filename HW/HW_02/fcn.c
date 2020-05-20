#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "fcn.h"

void parsingfcn(cns *numbers){

    char delimiter[] = "+i";
   
    char *token;
    token = strtok (numbers->num, delimiter);
    numbers->re = atoi(token);

    token = strtok (NULL, delimiter);
    numbers->im = atoi(token);
}

void calc(cns numbers, cns num1, cns *res, char op){
    
    switch(op){
        case '+': sumfnc(numbers, num1, res); break;
        case '-': diffnc(numbers, num1, res); break;
        case '*': profnc(numbers, num1, res); break;
        case '/': divfnc(numbers, num1, res); break;
        default: printf("\nWrong operator\n"); break;
        
    }
};

void sumfnc(cns num0, cns num1, cns *res) {
    res->re = num1.re + num0.re;
    res->im = num1.im + num0.im;
};

void diffnc(cns num0, cns num1, cns *res) {
    res->re = num0.re - num1.re;
    res->im = num0.im - num1.im;
};

void profnc(cns num0, cns num1, cns *res) {
    res->re = (num0.re*num1.re)-(num0.im*num1.im);
    res->im = (num0.re*num1.im)+(num1.re*num0.im);
};

void divfnc(cns num0, cns num1, cns *res){
    res->re = ((num0.re*num1.re)+(num0.im*num1.im))/((num1.re*num1.re)+(num1.im*num1.im));
    res->im = ((num0.re*(-1)*num1.im)+(num1.re*num0.im))/((num1.re*num1.re)+(num1.im*num1.im));
}

void resprint(cns *res){
    sprintf(res->num, "%.2lf+%.2lfi", res->re, res->im);
    printf("result: %s",res->num);
}