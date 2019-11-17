#ifndef _classLib_H_
#define _classLib_H_

using namespace std;

class Complex {
    int a;
    int b;
    public:
     void Init(const Complex& val ){
     a = val.a;
     b = val.b;
     }
     void Read(){
     cout << "Input point:" << endl;
     cin >> a >> b;
     }
     void Display(){
     cout << "(" << a <<"; "<< b<<")"<<endl;
     }

};

#endif
