/*
 * Person.cpp
 *
 *  Created on: 10 mar. 2021
 *      Author: sandrade
 */

#include <sstream> // Allows you to manipulate string before outputing to cout
#include "Person.h"

Person::Person() {
	this->name="John Dow";
	this->age=0;
};

// this can be used as a shothand constructor, this technique is only for constructors
Person::Person(string name, int age) : name(name), age(age) {}

void Person::setName(string name) {
	this->name = name;
}

string Person::getName() {
	return this->name;
}

void Person::setAge(int age) {
	this->age = age;
}

int Person::getAge() {
	return this->age;
}

void Person::print() {
	stringstream ss;
	ss << "Object allocated at: ";
	ss << this << endl;
	ss << "Is a person named: ";
	ss << this->name << endl;
	ss << "At, ";
	ss << this->age;
	ss<< " years old.";

	string info = ss.str();

	cout << info << endl;
}

string Person::toString() {
	return "This object represents a person named: " + this->name;
}
