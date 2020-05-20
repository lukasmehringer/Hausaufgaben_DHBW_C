#ifndef Header_h_
#define Header_h_

typedef struct {
    
    char num[1000];
    double re;
    double im;

}cns;    //complex number stuct

void parsingfcn(cns *);
void calc(cns, cns, cns *, char);
void sumfnc(cns, cns, cns*);
void diffnc(cns, cns, cns*);
void profnc(cns, cns, cns*);
void divfnc(cns, cns, cns*);
void resprint (cns *);

#endif