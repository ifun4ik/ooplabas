#include <iostream>
#include <windows.h>
#include <cmath>

using namespace std;

class Money {
 int rubbles;
 int cents;
 public:
     void setRubbles(int rub){
        rubbles = rub;
     }

     void SetYCoord(int c){
        cents = c;
     }

     int GetRubbles(){
        return rubbles;
     }

     int GetCents(){
        return cents;
     }

     void Init(int rub, int c){
         rubbles = rub;
         cents = c;
     }

     void Init(const Money& val ){
         rubbles = val.rubbles;
         cents = val.cents;
     }

     void Display(){
        cout << rubbles <<"."<< cents;
     }

     void Sum (const Money& val, const Money& val2){
        int rub1 = val.rubbles;
        int rub2 = val2.rubbles;
        int c1 = val.cents;
        int c2 = val2.cents;
        int sumrub, sumcents;
        if((c1+c2)>99){
            sumrub = rub1+rub2+1;
            sumcents = c1+c2-100;
        } else {
            sumrub = rub1+rub2;
            sumcents = c1+c2;
        }
        this->Init(sumrub, sumcents);
     }

     void Minus (const Money& val, const Money& val2) {
        int rub1 = val.rubbles;
        int rub2 = val2.rubbles;
        int c1 = val.cents;
        int c2 = val2.cents;
        int sumrub, sumcents;
        if((c1-c2)<0){
            sumrub = rub1-rub2-1;
            sumcents = c1-c2+100;
        } else {
            sumrub = rub1-rub2;
            sumcents = c1-c2;
        }
        this -> Init(sumrub, sumcents);
     }

     void Multiply (const Money &val, double per){
        int rub = val.rubbles;
        int c = val.cents;
        float whole = rub + (c/100);
        float multiplied = whole * per;
        rub = (int)multiplied;
        c = (int)((multiplied - floor(multiplied))* pow(10,2));
        this -> Init(rub,c);
     }

};

class Account {
 int accNum;
 double persent;
 Money amount;
 public:
    char *surname;
     void Init(const Money& money, char *owner, int accountNum) {
        amount = money;
        surname = owner;
        accNum = accountNum;
     }
     void Display(){
         cout << "The account number is: " << accNum << endl;
         cout << "Owned by: " << surname << endl;
         cout << "Amount: ";
        amount.Display();
        cout << "UAH" <<endl;
     }
     void changeOwner(char *newSurname){
        surname = newSurname;
     }
    void putMoney (const Money&toput){
        amount.Sum(amount, toput);
    }
    void getMoney (const Money&toget){
        amount.Minus(amount, toget);
    }
    void getPersents (int persents){
        Money multiplied;
        multiplied.Multiply(amount,persents);
        amount.Sum(amount, multiplied);
    }
    void toUSD (){
        Money toUSD;
        toUSD.Multiply(amount, 0.041);
        toUSD.Display();
    }
    void toEUR (){
        Money toEUR;
        toEUR.Multiply(amount, 0.035);
        toEUR.Display();
    }
};




int main(int argc, char* argv[])
{
    Account acc;
    Money amount;
    while (1){
        cout << "Welcome to Gl1n- banking software" << endl;
        cout << "1. To become the client of Gl1n- bank" << endl;
        cout << "2. To show your data" << endl;
        cout << "3. To change the account owner" << endl;
        cout << "4. To put money on your account" << endl;
        cout << "5. To get money from your account" << endl;
        cout << "6. To get percents on your amount" << endl;
        cout << "____________________________________" << endl;
        cout << endl;
        cout << "7. How much USD do you have" << endl;
        cout << "8. How much EUR do you have" << endl;
        cout << endl; cout << endl;
        int choice;
        cin >> choice;
        switch (choice){
        case 1:{
            int payRub, payCents, accNum;
            cout << "How much you'd like to put on your acc (UAH -> Enter -> Cents): ";
            cin >> payRub >> payCents;
            amount.Init(payRub, payCents);
            cout << "Choose the desired account number: ";
            cin >> accNum;
            char *ownedBy = new char [30];
            cout << "Input account owner's surname: ";
            cin >> ownedBy;
            acc.Init(amount, ownedBy, accNum);
            cout << "The account has been created" << endl << endl;
            break;
        }
        case 2:
            acc.Display();
            cout << endl << endl;
            break;
        case 3:{
            char *ownedBy = new char [30];
            cout << "Input new account owner's surname: ";
            cin >> ownedBy;
            acc.changeOwner(ownedBy);
            cout << "The account owner has been changed" << endl << endl;
            break;
            }
        case 4:
            Money toPay;
            int payRub, payCents;
            cout << "How much you'd like to put on your acc (UAH -> Enter -> Cents): ";
            cin >> payRub >> payCents;
            toPay.Init(payRub, payCents);
            acc.putMoney(toPay);
            cout << "Money are already on your account" << endl << endl;
            break;
        case 5:
            Money toGet;
            int getRub, getCents;
            cout << "How much you'd like to get from your acc (UAH -> Enter -> Cents): ";
            cin >> getRub >> getCents;
            toGet.Init(getRub, getCents);
            acc.getMoney(toGet);
            cout << "Money were charged successfully" << endl << endl;
            break;
        case 6:
            int persents;
            cout << "How much percents from your balance you want to get: ";
            cin >> persents;
            acc.getPersents(persents);
            cout << "Percents were added successfully" << endl << endl;
            break;
        case 7:
            cout << "Your balance in USD is: ";
            acc.toUSD();
            cout << " with course 1 USD = 24.11UAH" << endl;
            break;
         case 8:
            cout << "Your balance in EUR is: ";
            acc.toEUR();
            cout << " with course 1 EUR = 26.57UAH" << endl << endl;
            break;
        default:
            return(0);
    }
}
}
