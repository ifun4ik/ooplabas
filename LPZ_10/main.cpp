#include <iostream>

using namespace std;

class FazzyNumber{
public:
    struct Number{
    double A;
    double al;
    double ar;
    double B;
    double bl;
    double br;
};
    Number fn;

    FazzyNumberAdd(double a,double al,double ar,double b,double bl,double br){
        this->fn.A=a;
        this->fn.al=al;
        this->fn.ar=ar;
        this->fn.B=b;
        this->fn.bl=bl;
        this->fn.br=br;
    }

    Display(){
        cout<<this->fn.A<<"-"<<this->fn.al<<","<<this->fn.A<<","<<this->fn.A<<"+"<<this->fn.ar<<endl;
        cout<<this->fn.B<<"-"<<this->fn.bl<<","<<this->fn.B<<","<<this->fn.B<<"+"<<this->fn.br<<endl;
    }

    double Divide(){
        if(this->fn.B>0){
            if(this->fn.B-this->fn.bl>0){
                if(this->fn.B+this->fn.br>0){
                    cout<<(this->fn.A-this->fn.al)/(this->fn.B+this->fn.br)<<","<<this->fn.A/this->fn.B<<","<<(this->fn.A+this->fn.ar)/(this->fn.B-this->fn.bl)<<endl;
                }
                else{
                    cout<<"Divide by zero"<<endl;
                }
            }
            else{
                cout<<"Divide by zero"<<endl;
            }
        }
        else {
            cout<<"Divide by zero"<<endl;
        }
    }

    DivideThrow(){
        if(this->fn.B>0){
            if(this->fn.B-this->fn.bl>0){
                if(this->fn.B+this->fn.br>0){

                }
                else{
                    throw "Division by zero!";
                }
            }
            else{
               throw "Division by zero!";
           }
        }
        else {
            throw "Division by zero!";
        }
        cout<<(this->fn.A-this->fn.al)/(this->fn.B+this->fn.br)<<","<<this->fn.A/this->fn.B<<","<<(this->fn.A+this->fn.ar)/(this->fn.B-this->fn.bl)<<endl;
    }

    DivideTry(){
        try{
        double a=(this->fn.A-this->fn.al)/(this->fn.B+this->fn.br);
        a=this->fn.A/this->fn.B;
        a=(this->fn.A+this->fn.ar)/(this->fn.B-this->fn.bl);
        }
        catch(...)
        {
            cout<<"ERROR"<<endl;
        }
    }

};

int main()
{
    FazzyNumber f;
    f.FazzyNumberAdd(2,1,1,0,1,1);
    f.Display();
    f.Divide();
    f.DivideThrow();
    f.DivideTry();
    return 0;
}
