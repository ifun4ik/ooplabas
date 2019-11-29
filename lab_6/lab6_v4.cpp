#include <iostream>
#include <locale>

using namespace std;

int counter = 0;



class TCost {
	private:

	public:
	    int first;
		int second;
			// пустой конструктор
		TCost() {
			this->first;
			this->second;
			counter++;
		}
			// конструктор инициализации
		TCost(int x, int y) {
			this->first = x;
			this->second = y;
			counter++;
		}
			//конструктор копирования
		TCost(const TCost &C) {
			this->first = C.first;
			this->second = C.second;
			counter++;
		}


		void Init(int num1, int num2) {
			int Naminal[9] = { 1, 2, 5, 10, 50, 100, 500, 1000, 5000 };
			second = num2;
			bool try1 = false;

			for (int i = 0; i < sizeof(Naminal); i++) {
				if (num1 == Naminal[i]) {
					try1 = true;
					if (try1 == true) {
						first = num1;
						break;
					}
				}
			}

			if (try1 == false) {
				cout << "You've entered wrong number" << endl;
			}
		};

		int Money() {
			return first * second;
		};

		//friend void TCostActions::Display(TCost &a);
		//friend void TCostActions::Read(TCost &a);
};

class TCostActions{
	public:
		void Display(TCost &a);
		void Read(TCost &a);
};

void TCostActions::Display(TCost &a) {
	cout << "You've entered denomination: " << a.first << " In quantity " << a.second << endl << "Whole sum: " << a.Money() << endl;
};

void TCostActions::Read(TCost &a) {
	int first, second;
	cout << "Enter the denomination and it's quantity: " << endl;
	cin >> first >> second;
	a.Init(first, second);
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


