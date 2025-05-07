
#include <iostream>
using namespace std;

class Sandwich
{
public:
	string bread;
	float price;
	int calories;
	
	void printSandwich()
	{
		cout << "Bread: " << bread << endl;
		cout << "Price: $" << price << endl;
		cout << "Calories: " << calories << endl;
	}
};




int main() {
	Sandwich bbq;
	bbq.bread = "white";
	bbq.price = 5.99;
	bbq.calories = 300;
	bbq.printSandwich();
}

