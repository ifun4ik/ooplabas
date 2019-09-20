#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

struct Student {
    char name [30];
    int group;
    int marks [5];
};

void GetData(Student *A){
   cin.ignore();
     for (int i=0;i<10;i++)
      {
        cout << "\n";
        cout << "ФИО: ";
        cin.getline(A[i].name,30);

        cout << "Номер группы: ";
        cin >> A[i].group;
        cin.ignore();

        cout << "Оценки ";
        cin >> A[i].marks[0];    cin.ignore();
        cin >> A[i].marks[1];    cin.ignore();
        cin >> A[i].marks[2];    cin.ignore();
        cin >> A[i].marks[3];    cin.ignore();
        cin >> A[i].marks[4];    cin.ignore();


      }
}


int main()
{
    setlocale(LC_ALL,"");
    system("CLS");

    Student *A = new Student [10];

    GetData(A);
    delete[]A;

    system("PAUSE");
    return 0;

}
