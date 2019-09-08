#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 10
#define m 10

using namespace std;

//Defining global variables
int maxString, maxColumn, minString, minColumn;

//Creating random array
int randArr(int arr[n][m]){
    int i, j;
    srand(time(NULL));
    for (i=0; i<n; i++){
        for (j=0; j<m; j++){
            arr[i][j]=rand()%(20+20+1)-20;
        }
        printf("\n");
    }
    return arr[n][m];
}

//Printing your array
void printingArr(int arr[n][m]){
    int i,j;
    for (i=0; i<n; i++){
        for (j=0; j<m; j++){
            // arr[i][j]=rand()%(20+20+1)-20;
            printf("%3d \t", arr[i][j]);
        }
        printf("\n");
    }

}


int searchMax(int arr[n][m]){
    int max = -21, i, j;
    //Searching for max element
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            if(arr[i][j]>max){
                max=arr[i][j];
                maxString=i;
                maxColumn=j;
            }
        }
    }

    return max;
}

int main(){
    int arr[n][m];
    arr[n][m]=randArr(arr);
    printingArr(arr);
    int maxEl = searchMax(arr);
    printf("The element %d is highest", maxEl);
}


