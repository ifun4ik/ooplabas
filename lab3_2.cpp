#include <iostream>
#include <windows.h>

using namespace std;

class NumPower {
private:
 double first;
 double second;
 double x;
public:
 void Init(double _first, double _second, double _x){
 first = _first;
 second = _second;
 x = _x;
 };
 void Display(){
 cout << "The result is: " << Power()<<"\n";
 };
 void Read(){
     double a;
     double b;
     double x;
     cout << "Input A,B,x: \n";
     cin >> a >> b >> x;
     Init(a, b, x);
 };
 double Power(){
    return (first*x+second);
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
