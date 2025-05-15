#include <iostream>
using namespace std;

int Double(int* i)
{
	*i = *i * 2;
	return *i;
};

int square(int& i)
{
	i = i * i;
	return i;
}


int main()
{
	// ** REFERENCE **
	// 
	// declare an int variable and set the value to some number (less than 10)
	// declare a int reference and set it to the int variable above

	int i = 5;
	int& iRef = i;

	// output the int variable

	cout << "i: " << i << endl;

	// set the int reference to some number
	// output the int variable
	// what happened to the int variable when the reference was changed? (The int variable changed when I changed the reference.)

	iRef = 10;
	cout << "i changed: " << i << endl;

	// output the address of the int variable
	// output the address of the int reference
	// are the addresses the same or different? (the same)
	cout << "i address: " << &i << endl;
	cout << "iRef address: " << &iRef << endl;

	// ** REFERENCE PARAMETER **
	//
	// create a function above main() called Square that takes in an int parameter
	// in the function, multiply the int parameter by itself and assign it back to the parameter (i = i * i)
	// call the Square function with the int variable created in the REFERENCE section

	// output the int variable to the console

	int squared = square(i);
	cout << "i squared: " << i << endl;

	// !! notice how the variable has not changed, this is because we only passed the value to the function !!
	// change the Square function to take a int reference
	// !! notice how the calling variable has now changed, this is because we 'passed by reference' !!
	// !! when a function takes a reference parameter, any changes to the parameter changes the calling variable ""

	// ** POINTER VARIABLE **
	// 
	// declare an int pointer, set it to nullptr (it points to nothing)
	// set the int pointer to the address of the int variable created in the REFERENCE section

	int* intPtr = nullptr;
	intPtr = &i;

	cout << "intPtr: " << intPtr << endl;

	// output the value of the pointer
	// what is this address that the pointer is pointing to? (000000CE3E2FFBD4)
	// output the value of the object the pointer is pointing to (dereference the pointer)

	cout << "intPtr value: " << *intPtr << endl;

	// ** POINTER PARAMETER **
	//
	// create a function above main() called Double that takes in an int pointer parameter
	// in the function, multiply the int pointer parameter by 2 and assign it back to the parameter (i = i * 2)
	// !! make sure to dereference the pointer to set the value and not set the address !!
	// call the Double function with the pointer created in the POINTER VARIABLE section

	int doubled = Double(intPtr);
	cout << "doubled: " << doubled << endl;
	cout << "i value: " << i << endl;
	
	// output the dereference pointer
	// output the int variable created in the REFERENCE section
	// did the int variable's value change when using the pointer?
	// (yes, the int variable's value changed when using the pointer)

}