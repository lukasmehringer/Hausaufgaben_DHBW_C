/*
Programmed by Lukas Mehringer
Student ID: mt19051
HW3 
linked list program
*/

//CONFIDENTIAL: I thought the Homework was too well prepared!

#ifndef LINKEDLISTLIB_H_
#define LINKEDLISTLIB_H_

struct listElem{
    char lastName[50];
    char firstName[50];
    int age;
    struct listElem *nextElem;
};
typedef struct listElem listElement;
void addListElem(listElement *);
void printList(listElement *);
void saveList(listElement *);
void loadList(listElement *);



#endif