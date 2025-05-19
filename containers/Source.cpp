#include <vector>
#include <map>
#include <array>
#include <list>
#include <string>
#include <iostream>
using namespace std;

void printArray() {
	array<string, 7> daysOftheWeek = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };

	for (string day : daysOftheWeek) {
		cout << day << endl;
	};
};

void printVector() {
	vector<int> numbers = { 1, 2, 3, 4, 5 };
	numbers.push_back(6);
	numbers.push_back(7);
	numbers.pop_back();
	for (int number : numbers) {
		cout << number << endl;
	};
};

void printList() {
	list<string> fruits = { "Apple", "Banana", "Cherry" };
	fruits.push_front("Dragonfruit");
	fruits.push_back("Watermelon");
	fruits.remove("Banana");
	for (string fruit : fruits) {
		cout << fruit << endl;
	};
};

void printMap(){
	map<string, int> grocerys = { {"Milk", 7}, {"Bread", 2}, {"Eggs", 10} };
	grocerys["Milk"] = 5;
	for (auto grocery : grocerys) {
		cout << grocery.first << " " << grocery.second << endl;
	};

}


int main(){
	printArray();
	printVector();
	printList();
	printMap();
	return 0;
};