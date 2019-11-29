#include <iostream>
#include <cmath>
#define PI 3.14159265
using namespace std;

class Triangle{
    public:
        double a;
        double b;
        double c;

        Triangle(){
            this->a=1;
            this->b=1;
            this->c=1;
        }

        Triangle(double a,double b,double c){
            // проверка на существование треуцгольника
            if ((a + b > c) &&(a + c > b)&&(b + c > a)){
            this->a=a;
            this->b=b;
            this->c=c;}
            else {
                this->a=1;
                this->b=1;
                this->c=1;
                cout<<"Треугольник с указаными сторонами не может существовать. Вместо него создан треугольник со сторонами 1,1,1";
            }
        }

        Triangle(double a){
            this->a=a;
            this->b=a;
            this->c=a;
        }

        void Angeles(){
            double alfa,beta,gamma;
            alfa=acos((this->b*this->b+this->c*this->c-this->a*this->a)/(2*this->b*this->c))* 180.0 / PI;
            beta=acos((this->a*this->a+this->c*this->c-this->b*this->b)/(2*this->a*this->c))* 180.0 / PI;
            gamma=acos((this->b*this->b+this->a*this->a-this->c*this->c)/(2*this->b*this->a))* 180.0 / PI;
            cout<<"alfa: "<<alfa<<endl;
            cout<<"beta: "<<beta<<endl;
            cout<<"gamma: "<<gamma<<endl;
        }

        void Perimetr(){
            double P;
            P=this->a+this->b+this->c;
            cout<<"P: "<<P<<endl;
        }
};

class Equilateral : public Triangle{
    private:
    double square;

    public:
        Equilateral(double a) : Triangle (a)
        {}

        Equilateral() : Triangle ()
        {}

        void GetSquare(){
            square=(this->a*this->a*sqrt(3))/4;
            cout<<"S: "<<square<<endl;
        }
};

int main()
{
    setlocale(LC_ALL,"Rus");
    Triangle t;
    Triangle t1(3);
    t1.Angeles();
    t1.Perimetr();
    cout<<endl;
    Triangle t2(5,7,3);
    t2.Angeles();
    t2.Perimetr();
    cout<<endl;
    Equilateral e(3);
    e.Angeles();
    e.GetSquare();
    e.Perimetr();
    cout<<endl;
    Equilateral e1;
    e1.Angeles();
    e1.GetSquare();
    e1.Perimetr();
    return 0;
}
