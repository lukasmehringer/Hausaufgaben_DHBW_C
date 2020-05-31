/*
Programmed by Lukas Mehringer
Student ID: mt19051
HW4
linked list program
*/


#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "linkedListLib.h"

int main(){

    listElement *start;
    start = (listElement*)malloc(sizeof(listElement));
    if (start == NULL){
        printf("can't reserve storage");
        return -1;
    }
    start->nextElem = NULL;
    
int FLAGG = 1;
while (FLAGG){
    printf("\n [0] ... end Program\n");
    printf(" [1] ... print list\n");
    printf(" [2] ... add Element to list\n");
    printf(" [3] ... delete element\n");
    printf(" [4] ... delete list\n");
    printf(" [5] ... save list\n");
    printf(" [6] ... load list\n");
    printf(" [7] ... sort list\n");
    scanf("%d",&FLAGG);
    system("cls");


    switch (FLAGG){
        case 1: printList(start); break;
        case 2: addListElem(start); break;
        case 3: delListElem(start); break;
        case 4: delList(start); break;
        case 5: saveList(start); break;
        case 6: loadList(start); break;
        case 7: sortList(start); break;
        case 0: exitFcn(start); FLAGG = 0; break; //exit fcn
        default: printf("invalid choice\n"); break;
    }
} 
    return 0;

}