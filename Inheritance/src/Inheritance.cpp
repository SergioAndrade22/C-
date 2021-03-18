//============================================================================
// Name        : Inheritance.cpp
// Author      : Sergio AndradeSergio Andrade
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Animal {
private:
	string greeting;

public:
	Animal() { this->greeting = "Animal greeting"; }
	void speak() const { cout << "Grrrr" << endl; }
};

class Cat: public Animal {
public:
	void jump() const { cout << "Cat jumping" << endl; }
	void speak() const { cout << "Cat overwriting method" << endl; };
//	void greet() const { cout << Animal::greeting << endl; } Is not possible because greeting is private
};

class Frog: public Animal {
private: // data fields
	string name;

private: // methods
	string getName() { return name; }

public: // data fields
	string greeting;

public: // methods
	Frog(string name): name(name) { this->greeting = "Greeting from a Frog!"; }
	void info() { cout << "My name is: " << getName() << endl; }
};

class Machine { // base constructors are called before derived instances constructors
private:
	int id;
public:
	Machine(): id(0) { cout << "Machine no-argument constructor called!" << endl; }
	Machine(int id): id(id) { cout << "Machine one-argument constructor" << endl; }
	void info() { cout << "ID: " << this->id << endl; }
};

class Vehicle: public Machine {
public:
	Vehicle() { cout << "Vehicle no-argument constructor" << endl; }
	Vehicle(int id): Machine(id) { cout << "Vehicle one-argument constructor" << endl; }
};

class Car: public Vehicle {
public:
	Car(): Vehicle(94) { cout << "Car no-argument constructor" << endl; }
};

int main() {
//	Animal a;
//	a.speak();
//
//	Cat c;
//	c.speak();
//	c.Animal::speak();
//	c.jump();
//
//	Frog frog("Freddy");
//	frog.info();

	Vehicle vehicle;
	vehicle.info(); // data is set and gotten from the base class, despite vehicle not being able to access id on machine

	Car car;
	car.info();

	Machine machine(1234);
	machine.info();

	Vehicle vehicle2(145);
	vehicle2.info();

	Car car2;
	car2.info();
	return 0;
}
