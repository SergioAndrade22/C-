/*
 * Dog.h
 *
 *  Created on: 10 mar. 2021
 *      Author: sandrade
 */

#ifndef DOG_H_
#define DOG_H_

class Dog {
private:
	bool happy;

public:
	Dog();
	~Dog();
	void makeHappy();
	void makeSad();
	void speak();
	void poop();
	void jump();
};

#endif /* DOG_H_ */
