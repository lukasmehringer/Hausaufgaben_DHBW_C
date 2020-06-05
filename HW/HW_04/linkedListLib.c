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

int getLenOfList (listElement *start){
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

    if (getLenOfList(start) == 0){
        printf("\nthe list is empty therfore is no need to save the list!");    //check if saving makes sense
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
    fprintf(fPtr,"%d\n\n",getLenOfList(start));
    
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
JW-2020-05-27:
--------------
> well done (10/10) 
*/

void exitFcn(listElement *start){

  int saveFlagg = 0;

  printf("do you want to save the current list?\n");
  printf("[1] ... yes\n");
  printf("[0] ... no\n");
  scanf("%d",&saveFlagg);

  if (saveFlagg == 1) saveList(start);
  system("cls");
}

void delListElem(listElement *start){

    if(start->nextElem == NULL) printf("list is empty\n");

    else{

        int del=0;
        listElement *currElem = start;
        listElement *delElem = start;
        printList(start);
        printf("please select which Element you would like to delete: ");
        scanf("%d",&del);
        if(del >= getLenOfList(start)){
            printf("can't delete list Element");
            return;
        }
        for(int i = 0; i > del; i--){                  //currElem durch iterieren 
            currElem = currElem->nextElem;
        }
        delElem = currElem->nextElem;                   //delElem ausrichten
        currElem->nextElem = delElem->nextElem;         //oder:    currElem->nextElem = (currElem->nextElem)->nextElem;          next elem umrichten 
        free(delElem);                                  //free del Elem
    }
    printf("Element was deleted\nYour List now looks like this:\n");
    printList(start);
}

void delList(listElement *start){
    
    char check[4] = "Yes";
    char check2[4] = "";
    listElement *currElem = start;
    listElement *delElem = start;

    if(start->nextElem == NULL){
        printf("list is already empty\n");
        return;
    }
    printf("are you sure that you want to delet this List?\nType Yes if so: ");
    scanf("%s",check2);
    if(strcmp(check, check2) == 0){
        while(currElem->nextElem != NULL){
            delElem = currElem->nextElem;
            currElem->nextElem = (currElem->nextElem)->nextElem;
            free(delElem);
        }
        printf("\nlist was succsefully deleted\n");
    }
    else{
        printf("you didnt delet this list.\n");
    }
    return;
}

void stringToLower(char *string) {
	int i;
	int len = strlen(string); 
	for(i=0; i<len; i++) {
		if(string[i] >= 'A' && string[i] <= 'Z') {
			string[i] += 32;
		}
	}
}

/*

char temp[60];
temp[0] = "A";
temp[1] = "B";


&(temp[0]) == temp  // adresse von zelle 0 wird übergeben    //also adresse von A
temp[0] == A// geht and wert in 0;

*/

void sortList(listElement *start){
	
	int i, lenOfList, userFLAGG, swapFLAGG, SWAPPING = 0; // some locals

    listElement * currElem;
    listElement * prevElem;
    
    char temp1[50];
    char temp2[50];

	printf("sort current list according to ...\n");
	printf(" [1] ... last name\n [2] ... first name\n [3] ... age\n [0] ... exit\n");
	scanf("%d",&userFLAGG);
    printf("\n\n");

    // sort useres choice and get flagg if char or int
	if (userFLAGG != 0 && userFLAGG != 1 && userFLAGG != 2 && userFLAGG != 3){
        system("cls");
        printf("invalid choice. will exit function\n\n");
        return; 
    }
    else if (userFLAGG == 0){
        system("cls");
        return;
        }
    else{ // do the sorting

        lenOfList = getLenOfList(start);

        do{

            currElem = start->nextElem;
            prevElem = start;

            SWAPPING = 0; 
            for (i = 0; i < lenOfList -1; i++){

                    swapFLAGG = 0;
                    switch (userFLAGG){
                    case 1: // last name 

                        // 1.) Save last names of strings to compare in temp1 and temp2
                        strcpy(temp1, (currElem->lastName));
                        strcpy(temp2, ((currElem->nextElem)->lastName));

                        //2.) Use stringToLower function to cast temp1 and temp2 so lower cases
                        stringToLower(temp1);
                        stringToLower(temp2);

                        if (strcmp(temp1,temp2) > 0) swapFLAGG = 1;
                        break;
                    case 2: // first name   

                        //3.) Save first names of strings to compare in temp1 and temp2
                        strcpy(temp1, (currElem->firstName));
                        strcpy(temp2, ((currElem->nextElem)->firstName));     

                        //4.) Use stringToLower function to cast temp1 and temp2 so lower cases
                        stringToLower(temp1);
                        stringToLower(temp2);

                        if (strcmp(temp1,temp2) > 0) swapFLAGG = 1;
                        break;
                    case 3: // age  
                        //5.) Check swapFlagg to one if the relevant condition is true
                        if(currElem->age > (currElem->nextElem)->age) swapFLAGG = 1;

                        break;    
                    
                    default:
                        break;
                    }

                if (swapFLAGG){ 

                    //7.) Do the swapping. 
                        prevElem->nextElem = currElem->nextElem;
                        currElem->nextElem = (currElem->nextElem)->nextElem;
                        (prevElem->nextElem)->nextElem = currElem;

                    //8.) Don't forget to increment only the prev pointer.
                    prevElem = prevElem->nextElem;

                    SWAPPING = 1;
                } else{ // increament both
                    currElem = currElem->nextElem;
                    prevElem = prevElem->nextElem;
                }

            }

            lenOfList--;
        
        }while(SWAPPING);
        
    }
	printList(start); // print sorted list.
}
/*
JW-2020-06-05:
--------------
> well done (10/10) !
*/