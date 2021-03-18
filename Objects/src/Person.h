/*
 * Person.h
 *
 *  Created on: 10 mar. 2021
 *      Author: sandrade
 */

#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>

using namespace std;

class Person {
private:
	string name;
	int age;
public:
	Person();
	Person(string, int);
	void setName(string);
	string getName();
	void setAge(int);
	int getAge();
	string toString();
	void print();
};

#endif /* PERSON_H_ */
