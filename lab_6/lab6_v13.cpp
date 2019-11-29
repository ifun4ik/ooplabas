#include <iostream>
#include <cctype>
#include <math.h>

using namespace std;
int counter = 0;

class TCost {
	private:

	public:
	    float first, second;

		void Init(float _first, float _second) {
			//if (isdigit(_first) && isdigit(_second)) {
				first = _first;
				second = _second;
			//} else {
			//	cout << endl <<"You've entered not a number ";
				//exit(1);
			//}
		};

        TCost operator + (TCost t1){
            return TCost(sqrt(t1.first + t1.second));
        }

		float Hypotenuse() {
			return pow(first, 2) + pow(second, 2);
		};

		TCost() {
			this->first;
			this->second;
			counter++;
		}

		TCost(int x, int y) {
			this->first = x;
			this->second = y;
			counter++;
		}

		TCost(const TCost& C) {
			this->first = C.first;
			this->second = C.second;
			counter++;
		}

		//friend void TCostActions::Display(TCost &a);
		//friend void TCostActions::Read(TCost &a);
};

class TCostActions {
	public:
		void Read(TCost &a);
		void Display(TCost &a);
};

void TCostActions::Read(TCost &a) {
	float _first, _second;

	cout << "Enter the legs A and B of the triangle: ";
	cin >> _first >> _second;

	a.Init(_first, _second);
};

void TCostActions::Display(TCost &a) {
	cout << endl << "Hypotenuse: " << a.Hypotenuse() << endl;
};

int main(){
	setlocale(LC_ALL, "Russian");

	TCostActions A;
	TCost B;

	A.Read(B);
	A.Display(B);

	//cout << "Was created " << counter << " objects" << endl;

	return 0;
}
