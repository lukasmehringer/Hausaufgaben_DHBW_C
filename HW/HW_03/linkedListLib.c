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

void addListElem(listElement *start){

    listElement *new;
    new = (listElement*)malloc(sizeof(listElement));
    if (new == NULL){
        printf("can't retore storage.\n");
        return;
    }
    listElement *currElem = start;
    while(currElem->nextElem != NULL) currElem = currElem->nextElem;
    currElem->nextElem = new;
    new->nextElem = NULL;
 
     // Enter data 
    printf("please enter last Name: ");
    scanf("%s",new->lastName);

    printf("please enter first Name: ");
    scanf("%s",new->firstName);                            //scanf will immer adresse

    printf("please enter age: ");
    scanf("%d",&(new->age));                               // int ist keine adresse wir wollen aber adresse dewegen &

}

void printList(listElement *start){

    if (start->nextElem == NULL) printf("\nlist is empty.\n");
    else{
        int i = 1;
        listElement *currElem = start;
        do{
            currElem = currElem->nextElem;
            printf("%d.)\n",i); i++;
            printf("\t%s\n",currElem->lastName);
            printf("\t%s\n",currElem->firstName);         //printf erwartet bei string ne adresse ansosten speicherort;
            printf("\t%d\n",currElem->age);               // -> geht auf adresse bei string (weil string immer adresse ist) bei int usw immer speicherort;
        
        }while(currElem->nextElem != NULL);
    }

}

int getLenofList (listElement *start){
    int len=0;
    listElement *currElem = start;
    while (currElem->nextElem != NULL){
        len++; currElem = currElem->nextElem;
    }
    return len;
}


void saveList(listElement *start){
    char filename[50];                              //char arrey for filename
    listElement * currElem = start;

    if (getLenofList(start) == 0){
        printf("\nthe list is empty therfore we wont save the list! #pechgehbt #aechibaechi");    //check if saving makes sense
        return;
    }

    printf("\nsaving data...\n");
    printf("please enter a filename without extesion: ");
    scanf("%s", filename);
    strcat(filename, ".txt");  

    FILE * fPtr;
    fPtr = fopen(filename, "w");

    //1.)
    // check if fopen was succsessfull
    if(fPtr == NULL){
        printf ("\nthis action was termiated! Please Note: YOUR FILES HAVE NOT BEEN SAVED!"); 
        return;
    }

    //2.)
    // print length of list into document 
    fprintf(fPtr,"%d\n\n",getLenofList(start));
    
    //3.)
    // print elemtens into list
    do{
        currElem = currElem->nextElem,
        fprintf(fPtr,"\n%s",currElem->lastName);
        fprintf(fPtr,"\n%s",currElem->firstName);
        fprintf(fPtr,"\n%d\n",currElem->age);

    }while(currElem->nextElem != NULL);
    
    //4.)
    //close fptr and tell user that everything went well
    fclose(fPtr);
    printf("all data was succsefully saved");
}

void loadList(listElement *start){
    
    listElement *currElem = start;
    int quan=0;                                 //quantity of files in list
    char filename[50];
    
    printf("\nloading data...\n\n");
    printf("available data\n-------------------\n");
    system("dir /b *.txt");
    printf("\nenter filename without extension: ");
    scanf("%s", filename);
    strcat(filename, ".txt");

    FILE * fPtr;
    fPtr = fopen(filename, "r");

    //1.)
    //check if fptr was succsessfull
    if(fPtr == NULL){
        printf ("\nno such file in directory. this action was termiated!"); 
        return;
    }

    //2.)
    //scan how many files have to be saved
    fscanf(fPtr, "%d", &quan);

    //3.)
    //save each file into an Element
    for(int i = 0; i < quan; i++){
        
        listElement *new;
        
        new = (listElement*)malloc(sizeof(listElement));
        if (new == NULL){
            printf("can't retore storage.\n");
            return;
        }
        
        while(currElem->nextElem != NULL) currElem = currElem->nextElem;
        currElem->nextElem = new;
        fscanf(fPtr, "%s", new->lastName);
        fscanf(fPtr, "%s", new->firstName);
        fscanf(fPtr, "%d", &(new->age));
        new->nextElem = NULL;
    }
    fclose(fPtr);
    printf("The action was succsefully! All following names are now in your list:\n");
    printList(start);
}



/*

char temp[60];
temp[0] = "A";
temp[1] = "B";


&(temp[0]) == temp  // adresse von zelle 0 wird übergeben    //also adresse von A
temp[0] == A// geht and wert in 0;

*/