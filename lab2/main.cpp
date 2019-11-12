#include <iostream>
#include <cstdlib>
#include <fstream>
#include <clocale>
#include <Windows.h>


using namespace std;

struct Student {
    char name [30];
    int group;
    int marks [5];
};

int AvgMark (Student *A, int i){
    double avg = (A[i].marks[0] + A[i].marks[1] + A[i].marks[2] + A[i].marks[3] + A[i].marks[4])/5;
    return (avg);
}

void ShowData(Student *A)
{
    for (int i=0;i<3;i++)
    {
        if (AvgMark(A, i)>=4){
            cout << "ФИО:" << A[i].name << endl;
            cout << "Группа:" << A[i].group << endl;
            cout << "Оценки:" << A[i].marks[0] << "  " <<A[i].marks[1] << "  " <<A[i].marks[2] << "  " <<A[i].marks[3] << "  " <<A[i].marks[4] << "  " << endl;
            cout << "Средняя:" << AvgMark(A, i) << endl << endl;
        }
    }
}

void Write (Student *A){
    std::ofstream out;          // поток для записи
    out.open ("data.txt"); // окрываем файл для записи
    if (out.is_open()){
        for (int i = 0; i < 3; ++i) {
            out << "ФИО:" << A[i].name << endl;
            out << "Группа:" << A[i].group << endl;
            out << "Оценки:" << A[i].marks[0] << "  " <<A[i].marks[1] << "  " <<A[i].marks[2] << "  " <<A[i].marks[3] << "  " <<A[i].marks[4] << "  " << endl << endl;
        }
    }

    std::cout << "End of program" << std::endl;
}

void Read (){
    string line;

    ifstream in("data.txt"); // окрываем файл для чтения
    if (in.is_open())
    {
        while (getline(in, line))
        {
            cout << line << endl;
        }
    }
    in.close();     // закрываем файл

    std::cout << "End of program" << std::endl;
}

void GetData(Student *A){
    for (int i=0;i<3;i++)
    {
        cout << "ФИО: ";
        cin.getline(A[i].name,30);

        cout << "Номер Группы: ";
        cin >> A[i].group;
        cin.ignore();

        cout << "Оценки: ";
        cin >> A[i].marks[0];    cin.ignore();
        cin >> A[i].marks[1];    cin.ignore();
        cin >> A[i].marks[2];    cin.ignore();
        cin >> A[i].marks[3];    cin.ignore();
        cin >> A[i].marks[4];    cin.ignore();


    }
}

void SortData (Student *A){
    Student tmp;
    int minSym = (int)A[0].group;
    int index = 0, k = 0, i, j;
    for (i=0; i<3; i++){
        for (j=k; j<3; j++){
            if (minSym > (int)A[j].group){
                minSym = (int)A[j].group;
                index = j;
            }
        }
        tmp = A[i];
        A[i] = A[index];
        A[index] = tmp;
        k++;
        minSym = (int)A[k].group;
        index = k;
    }
}


int main()
{
    setlocale(LC_ALL,"Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int choice;
    Student *A = new Student [3];
    while (1){
        cout << "|1: Ввести данные;" << endl << "|2: Просмотреть данные;" << endl << "|3: Записать в файл;" << endl << "|4: Считать из файла;" << endl << "|5: Отсортировать данные по номеру группы ;" << endl << "|" << endl << "|0: Выйти" << endl << "|42: Очистить экран" << endl << "=====================" << endl << endl;
        cout << "Выберите действие:";
        cin >> choice; cin.ignore();
            switch (choice) {
                case 1:
                    GetData(A);
                    break;
                case 2:
                    ShowData(A);
                    break;
                case 3:
                    Write(A);
                    break;
                case 4:
                    Read();
                    break;
                case 5:
                    SortData(A);
                    break;
                case 42:
                    system("cls");
                    break;
                case 0:
                    cout << "Пока-пока";
                    return 0;
                default:
                    cout << "Не ломайся, выбери нормально." << endl << endl;
                    break;

            }
    }


}
