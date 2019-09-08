#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#define n 10
#define m 10

using namespace std;

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

//Searching for max el
int searchMax(int arr[n][m]){
    int max = -21, i, j, tempMax = -21;
    //Searching for max element
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            if(arr[i][j]>tempMax){
                tempMax = arr[i][j];
                continue;
            }
            if (arr[i][j]==tempMax){
                max = tempMax;
            }
        }
    }
    return max;
}

int notZeroStrings (int arr[n][m]){
    int i,j, counter = 0;
    for (i=0; i<m; i++) {
        for (j = 0; j < n; j++) {
            if (arr[i][j] == 0) {
                counter++;
                break;
            } else {
                continue;
            }
        }
    }
    return (10-counter);
}

int main(){
    int arr[n][m];
    arr[n][m]=randArr(arr);
    printingArr(arr);
    int maxEl = searchMax(arr);
    int notZero = notZeroStrings(arr);
    printf("There are %d non-zero strings\n", notZero);
    printf("The maximal element is %d", maxEl);
}


