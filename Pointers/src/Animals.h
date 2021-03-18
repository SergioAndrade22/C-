/*
 * Animals.h
 *
 *  Created on: 15 mar. 2021
 *      Author: sandrade
 */

#ifndef ANIMALS_H_
#define ANIMALS_H_

#include <iostream>

using namespace std;

namespace sdac {

	const string CATRACE = "Persian";

	class Cat {
		public:
			Cat();
			virtual ~Cat();
			void speak() const;
	};

} /* namespace sdac */

#endif /* ANIMALS_H_ */
