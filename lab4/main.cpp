#include <iostream>
#include <math.h>

using namespace std;

class Vector3D{
    int xcoord;
    int ycoord;
    int zcoord;
    public:
        void Init(const Vector3D& val ){
            xcoord = val.xcoord;
            ycoord = val.ycoord;
            zcoord = val.zcoord;
        }
        void Read(){
            cout << "Input point:" << endl;
            cin >> xcoord >> ycoord >> zcoord;
        }
        void Display(){
            cout << "(" << xcoord <<"; "<< ycoord <<"; "<< zcoord <<")"<<endl;
        }
        void VectorSum(const Vector3D &val, const Vector3D &val2) {
            int result[3] = {0, 0, 0};
            int x1 = val.xcoord;
            int y1 = val.ycoord;
            int z1 = val.zcoord;
            int x2 = val2.xcoord;
            int y2 = val2.ycoord;
            int z2 = val2.zcoord;
            result[0] = x1+x2;
            result[1] = y1+y2;
            result[2] = z1+z2;
            cout << "(" << result[0] <<"; "<< result[1] <<"; "<< result[2] <<")"<<endl;
        }
        void VectorSub (const Vector3D &val, const Vector3D &val2){
            int result[3] = {0, 0, 0};
            int x1 = val.xcoord;
            int y1 = val.ycoord;
            int z1 = val.zcoord;
            int x2 = val2.xcoord;
            int y2 = val2.ycoord;
            int z2 = val2.zcoord;
            result[0] = x1-x2;
            result[1] = y1-y2;
            result[2] = z1-z2;
            cout << "(" << result[0] <<"; "<< result[1] <<"; "<< result[2] <<")"<<endl;
        }
        void VectorScalMul (const Vector3D &val, const Vector3D &val2){
            int result = 0;
            int x1 = val.xcoord;
            int y1 = val.ycoord;
            int z1 = val.zcoord;
            int x2 = val2.xcoord;
            int y2 = val2.ycoord;
            int z2 = val2.zcoord;
            result = x1*x2+y1*y2+z1*z2;
            cout << result << endl;
        }
        void VectorMulScal (const Vector3D &val){
            int multiplier = 0;
            cin >> multiplier;
            int result[3] = {0, 0, 0};
            int x1 = val.xcoord;
            int y1 = val.ycoord;
            int z1 = val.zcoord;
            result[0] = x1*multiplier;
            result[1] = y1*multiplier;
            result[2] = z1*multiplier;
            cout << "(" << result[0] <<"; "<< result[1] <<"; "<< result[2] <<")"<<endl;
        }
        void VectorEqu (const Vector3D &val, const Vector3D &val2){
            int x1 = val.xcoord;
            int y1 = val.ycoord;
            int z1 = val.zcoord;
            int x2 = val2.xcoord;
            int y2 = val2.ycoord;
            int z2 = val2.zcoord;
            if(x1==x2 && y1==y2 && z1==z2){
                cout << "Vectors are equal"<<endl;
            }
            else{
                cout << "Vectors aren't equal"<<endl;
            }
        }
        void VectorLength (const Vector3D &val){
            int x = val.xcoord;
            int y = val.ycoord;
            int z = val.zcoord;
            int squaredSum = (x*x)+(y*y)+(z*z);
            double result = sqrt(squaredSum);
            cout << "The vector length is " << result <<endl;
        }
        void VectorLengthEqu (const Vector3D &val, const Vector3D &val2){
            int x1 = val.xcoord;
            int y1 = val.ycoord;
            int z1 = val.zcoord;
            int x2 = val2.xcoord;
            int y2 = val2.ycoord;
            int z2 = val2.zcoord;
            double length1 = (x1*x1+y1*y1+z1*z1);
            double length2 = (x2*x2+y2*y2+z2*z2);
            if (length1 > length2){
                cout << "The vector 1 is longer"<<endl;
            } else if (length2 > length1){
                cout << "The vector 2 is longer"<<endl;
            } else {
                cout << "The vectors are equal"<<endl;
            }
        }

};

int main() {
    while (1) {
        cout << "Hello! Choose the option:" << endl << "1. Add vectors" << endl << "2. Subtract vectors" << endl
             << "3. Scal multiplying the vectors" << endl << "4. Vector * scalar" << endl << "5. Equal vectors" << endl
             << "6. Vector length" << endl << "7. Vectors length equal" << endl << endl << endl << "0. Kill the program"
             << endl;
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                Vector3D p1, p2, p3;
                p1.Read();
                p2.Read();
                p3.VectorSum(p1,p2);
                break;
            case 0:
                cout << "Goodbye" << endl;
                return 0;
            default:
                cout << "Не ломайся, выбери нормально." << endl << endl;
                break;
        }
    }
}