#include <iostream>
#include <cmath>

class Root
{
public:
    virtual double getRoot() =0;
    virtual void display()=0;
};

class Linear : public Root
{
private:
    double x;
    double k;
    double y;
public:
    Linear (double y,double k) : y(y),k(k)
    {
    }
    double getRoot() override
    {
         if(this->k!=0){
           this->x=this->y/this->k;
        }
    }

    void display()
    {
        std::cout <<this->y<<"/"<<this->k<< "=" <<this->x <<std::endl;
    }
};
class Square : public Root
{
private:
    double x1,x2,a,b,c;
public:
    Square(double a,double b,double c) : a(a),b(b),c(c)
    {
    }
    double getRoot() override
    {
        double d = this->b * this->b - 4 * this->a * this->c; // –ассчитываем дискриминант
        if (d > 0) // ”словие при дискриминанте больше нул€
        {
            this->x1 = ((-this->b) + sqrt(d)) / (2 * this->a);
            this->x2 = ((-this->b) - sqrt(d)) / (2 * this->a);
        }
        if (d == 0) // ”словие дл€ дискриминанта равного нулю
        {
            this->x1 = -(this->b / (2 * this->a));
            this->x2=NULL;
        }
        if (d < 0) // ”словие при дискриминанте меньше нул€
            std::cout << "D < 0, ƒействительных корней уравнени€ не существует";
    }


    void display()
    {
        std::cout << "x1=" <<this->x1 <<std::endl;
        std::cout << "x2=" <<this->x2 <<std::endl;
    }
};

int main()
{
    Linear l1(4,2);
    Square s1(1,3,2);
    l1.getRoot();
    s1.getRoot();
    l1.display();
    s1.display();
    return 0;
}
