//============================================================================
// Name        : Objects.cpp
// Author      : Sergio AndradeSergio Andrade
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "Dog.h"
#include "Person.h"

using namespace std;

int main() {
	cout << "Start of program" << endl;

	{
		// This curly brackets can be used to force a memory deallocation before the functions finishes
		// This happens because the object destructor binds to the nearest pair of curly brackets
		Dog bob; // if constructor takes no params, it runs automatically
		bob.speak();
	}

	// Person person = Person("Mark", 32);
	Person person("Mark", 32); // Can simplify constructor
	cout << "Using toString(): " << person.toString() << endl;
	cout << "Mark's age: " << person.getAge() << " Happy bithday!" << endl;
	person.setAge(person.getAge() + 1);
	cout << "Mark's new age: " << person.getAge() << endl;

	person.setName("Paul");
	cout << "Using getName(): " << person.getName() << endl;

	Person person2;
	person2.print();

	cout << "End of program" << endl;
	return 0;
}
