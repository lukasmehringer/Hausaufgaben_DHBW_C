/*
Programmed by Lukas Mehringer
Student ID: mt19051
HW3 
linked list program
*/

//CONFIDENTIAL: I thought the Homework was too well prepared!

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
    printf("\n0...end Program\n");
    printf("1...print list\n");
    printf("2...add Element to list\n");
    printf("3...delete element\n");
    printf("4...delete list\n");
    printf("5...save list\n");         //file stream
    printf("6...load list\n");         //files 
    printf("7...sort list\n");          //look at bubble sort
    scanf("%d",&FLAGG);
    //system("cls");


    switch (FLAGG){
        case 1: printList(start); break;
        case 2: addListElem(start); break;
        //case 3&4
        case 5: saveList(start); break;
        case 6: loadList(start); break;
        //case 7
        case 0: FLAGG = 0; break; //exit fcn
        default: printf("invalid choice\n"); break;
    }
} 
    return 0;

}