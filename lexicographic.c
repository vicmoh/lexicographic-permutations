/* Vicky Mohammad
 * 0895391
 * program try to get the lexiorder
 * of the permutation
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>

bool nextPermutation(int array[], size_t length) {
    // Find non-increasing
    if (length == 0){
        return false;
    }//end if
    size_t x= length - 1;
    while (x> 0 && array[x- 1] >= array[x]){
        x--;
    }//end if
    if (x== 0){
        return false;
    }//end if
    
    // Find pivot
    size_t y = length - 1;
    while (array[y] <= array[x- 1]){
        y--;
    }//end if
    int temp = array[x- 1];
    array[x- 1] = array[y];
    array[y] = temp;
    
    // Reverse
    y = length - 1;
    while (x< y) {
        temp = array[x];
        array[x] = array[y];
        array[y] = temp;
        x++;
        y--;
    }//end if
    return true;
}//end if

int userInputToInt(char* input){
    //declare var
    int num;
    //ask for user input
    input[0] = '\0';
    fgets(input, 100, stdin);
    input[strlen(input)-1] = '\0';
    num = atoi(input);
    //return
    return num;
}//end func

char* userInput(char* input){
    //ask for user input
    input[0] = '\0';
    fgets(input, 100, stdin);
    input[strlen(input)-1] = '\0';
    //return
    return input;
}//end func

int main(int argc, char **argv){
    //declare var
    int menu = 0, numOfArray = 0, x = 0;
    char stringBuffer[99];

    //aks the user and assign the number of array
    do{
        printf("Please enter the number of integer for Array (number valid from 2 to 20):\n");
        numOfArray = userInputToInt(stringBuffer);
    }while(numOfArray <= 2 || numOfArray >= 20);
    int arrayOfInt[numOfArray-1];

    //ask the intger in the array
    printf("Please input the %d integers \n", numOfArray);
    for(x=0; x<=numOfArray-1; x++){
        scanf("%d", &arrayOfInt[x]);
    }//end for
    getchar();

    do {
        for(x=0; x < numOfArray; x++){
            printf("%d ", arrayOfInt[x]);
        }//end for
        printf("\n");
    } while (nextPermutation(arrayOfInt, numOfArray));
    //done with program
    return 0;

}//end if