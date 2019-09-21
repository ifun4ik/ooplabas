#include <iostream>
#include <cstdlib>
#include <fstream>


using namespace std;

struct Student {
    char name [30];
    int group;
    int marks [5];
};

void ShowData(Student *A)
{
    for (int i=0;i<10;i++)
    {
        cout << "ФИО:" << A[i].name << endl;
        cout << "Группа:" << A[i].group << endl;
        cout << "Оценки:" << A[i].marks[0] << "  " <<A[i].marks[1] << "  " <<A[i].marks[2] << "  " <<A[i].marks[3] << "  " <<A[i].marks[4] << "  " << endl << endl;
        //количество купленного не выводим, сейчас не нужно, хотя хотите - выводите.
    }
}

void Write (Student *A){
    std::ofstream out;          // поток для записи
    out.open ("data.txt"); // окрываем файл для записи
    if (out.is_open()){
        for (int i = 0; i < 10; ++i) {
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
    for (int i=0;i<2;i++)
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


int main()
{
    setlocale(LC_ALL,"");
    int choice;
    Student *A = new Student [10];
    while (1){
        cout << "|1: Ввести данные;" << endl << "|2: Просмотреть данные;" << endl << "|3: Записать в файл;" << endl << "|4: Считать из файла;" << endl << "|" << endl << "|0: Выйти" << endl << "=====================" << endl << endl;
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
                case 0:
                    cout << "Пока-пока";
                    return 0;
                default:
                    cout << "Не ломайся, выбери нормально." << endl << endl;
                    break;

            }
    }

    delete[]A;

    system("read -p 'Press Enter to continue...' var");
    return 0;

}
