#include <iostream>
#include <windows.h>

using namespace std;

class NumPower {
private:
 double first;
 int second;
public:
 void Init(double _first, double _second){
 first = _first;
 second = _second;
 };
 void Display(){
 cout << "The powered number is: " << Power()<<"\n";
 };
 void Read(){
     double number;
     int powered;
     cout << "Input number and power: \n";
     cin >> number >> powered;
     Init(number, powered);
 };
 double Power(){
    int result = 1;
    for (int i=0; i<second; i++){
        result = result * first;
    }
    return result;
 };
};
int main(int argc, char* argv[])
{
NumPower A;
NumPower* B = new NumPower();
A.Read();
A.Display();
B->Read();
B->Display();
delete B;
system("PAUSE");
return 0;
}
