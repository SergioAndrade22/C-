//============================================================================
// Name        : Pointers.cpp
// Author      : Sergio AndradeSergio Andrade
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "Animals.h"
#include "Cat.h"

using namespace std;
// We can avoid the using namespace statement if we explicitly use namespace::class/variable
//using namespace sdac;
//using namespace cats;

int main() {
	sdac::Cat cat1;
	cout << "Greating from a " << sdac::CATRACE << " cat!" << endl;
	cat1.speak();

	cout << "Greating from a " << cats::CATRACE << " cat!" << endl;
	cats::Cat cat2;
	cat2.speak();
	return 0;
}

/*
	delete [] pointer; // line used to delete arrays of pointers
*/

/* Some objet information
class used:
	class Animal {
	private:
		string name;
	public:
		Animal() { cout << "Animal Created" << endl; };
		// as we are in the same class we can access private fields
		// you can only call const methods on the copy constructor object param
		Animal(const Animal& other): name(other.name) { // this is the copy constructor, invoked when using '=' on an already created object
			cout<< "Animal Copied" << endl;
		};
		~Animal() { cout << "Desctructor Called" << endl; };
		void setName(string name) { this->name = name; };
		// using const prevents the method to change the value of class attributes
		void speak() const { cout << "My name is: " << this->name << endl; };
	};

	Animal createAnimal() {
		Animal a;
		a.setName("Bert");

		return a;
	}

main file:
	// using new to create an object forces you to manually deallocate memory with delete
	Animal *pCat1 = new Animal(); // the () are optional

	pCat1->setName("Fred"); // optionally (*pCat1).setName("Fred");
	pCat1->speak();

	// calling delete on a NULL pointer raises an error
	delete pCat1; // this forces to deallocate the memory assigned to the pointer pCat1


Animal* createAnimal() { // returning a pointer prevents the object to be deallocated
	Animal *pAnimal = new Animal();
	pAnimal->setName("Bert");

	return pAnimal;
}
*/

/* Pointer reference and manipulation
// this param sintax ensures the size of the array
void show3(string (&texts)[3]) {
	for(unsigned int i = 0; i < sizeof(texts)/sizeof(string); i++){
		cout << texts[i] << endl;
	}
}

int changeVal(double &val) { // must be called like changeVal(val)
	val = 4.321;
	return 0;
}

int changeVal2(double* val) { // must be called like changeVal(&val)
	*val = 8.765;
	return 0;
}

int stringReverPointerLike(string text) {
	int nChars = sizeof(text) - 4;

	char *pStart = &text[0];
	char *pEnd = &text[nChars];

//	if using text inside same scope
//	  int nChars = sizeof(text) - 1;
//	  char *pStart = text;
//	  char *pEnd = text + nChars - 1


	char aux;

	while (pStart < pEnd) {
		aux = *pStart;
		*pStart = *pEnd;
		*pEnd = aux;

		pStart++;
		pEnd--;
	}

	cout << text << endl;
	return 0;
}

int stringReverseArrayLike(string text) {
	int i = 0;
	int j = sizeof(text) - 4; // tengo que retroceder 4 por el puntero

//	int j = sizeof(text) - 2; // si fuera una variable dentro de la función solamente elimino el caracter nulo

	char aux;
	while (i < j) {
		aux = text[i];
		text[i] = text[j];
		text[j] = aux;

		i++;
		j--;
	}

	cout << text << endl;
	return 0;
}
*/

/* Simple operations special cases
	double value1 = 7/2; // due to performing an integer division, the result will be integer nonetheless
	cout << value1 << endl;

	double value2 = 7.0/2; // however, this will yield the intended result, as 7/2.0 will
	cout << value2 << endl;

	int div1 = 7;
	int div2 = 2;

	double value3 = ((double) div1)/div2;
	cout << value3 << endl; // we can also use casting

//	int int1 = 7.3; // this might yield compilation warning/error based on compiler
	int int1 = (int) 7.9; // but we can use explicit casting by truncating the number
	cout << int1 << endl;
*/

/* Simple pointer manipulation
Outside main:
	void manipulate(double *p_val){
		*p_val = 10.0;
		cout << "Manipulated value in function: " << *p_val << endl;
	}
Inside main:
	int val = 8;
	int* p_val = &val;

	cout << "Int value: " << val << endl;
	cout << "Addres value: " << p_val << endl;
	cout << "Get value from pointer: " << *p_val << endl;

	cout << "/===================== Testing manipulation =====================\\";
	double dVal = 123.4;
	cout << "1. dVal: " << dVal << endl;
	manipulate(&dVal);
	cout << "2. dVal after manipulate: " << dVal << endl;

	string texts[] = {"one", "two", "three"};
	string pTexts = texts;

	// this uses a pointer to iterate over an array, using its arithmetics
	for (unsigned int i = 0; i < sizeof(texts)/sizeof(string); i++, pTexts++){
		cout << *pTexts << " " << flush;
	}

	// continue in either block A or block B
*/

/* Block A
	string *pElement = &texts[0];
	string *pEnd = &texts[sizeof(texts)/sizeof(string) - 1];

	while(true)
		coout << *pElement << " " << flush;

		if (pElement == pEnd)
			break;

		pElement++;
	}
*/

/* Block B
	string *pElement = &texts[0];
	string *pEnd = &texts[sizeof(texts)/sizeof(string)]; // do NOT reference this pointers content

	while(pElement != pEnd)
		coout << *pElement << " " << flush;
		pElement++;
	}
*/
