/*
 * Dog.cpp
 *
 *  Created on: 10 mar. 2021
 *      Author: sandrade
 */
#include <iostream>

#include "Dog.h"

using namespace std;

Dog::Dog() {
	cout << "Dog created" << endl;
	happy = true;
}

Dog::~Dog() {
	cout << "Dog destroyed" << endl;
}

void Dog::speak() {
	if (happy)
		cout << "Bark!!!" << endl;
	else
		cout << "Grrrr!!!" << endl;
}

void Dog::poop() {
	cout << "Smelly in carpet!!!" << endl;
}

void Dog::jump() {
	cout << "Jumped!!!" << endl;
}

void Dog::makeHappy() {
	happy = true;
}

void Dog::makeSad() {
	happy = false;
}
