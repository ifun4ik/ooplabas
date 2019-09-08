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

void spiral(int arr[n][m]){
    int i1=10, j1=10, j=0, i, temp=0, arr1[10*10];
    j=0;
    while(j<j1)
    {
        i=10-i1;
        j=10-j1;
        for(; j<j1; j++)
        {
            printf("case1\n");
            arr1[temp]=arr[i][j];
            temp++;
        }
        j--;
        for(i++; i<i1; i++)
        {
            printf("case2\n");
            arr1[temp]=arr[i][j];
            temp++;
        }
        i--;
        for(j--; j>=10-j1; j--)
        {
            printf("case3\n");
            arr1[temp]=arr[i][j];
            temp++;
        }
        j++;
        for(i--; i>10-j1; i--)
        {
            printf("case4\n");
            arr1[temp]=arr[i][j];
            temp++;
        }
        i++;
        i1--;
        j1--;
    }
    for(i=10*10-1; i>=0; i--)
        printf("%5d",arr1[i]);

    printf("\n");
}

int main(){
    int arr[n][m];
    arr[n][m]=randArr(arr);
    printf("The initial array is:\n");
    printingArr(arr);
    printf("Spiral:\n");
    spiral(arr);
}


