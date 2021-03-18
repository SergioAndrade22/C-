/*
 * Cat.h
 *
 *  Created on: 15 mar. 2021
 *      Author: sandrade
 */

#ifndef CAT_H_
#define CAT_H_

#include <iostream>

using namespace std;

namespace cats{

	const string CATRACE = "Sphynx";

	class Cat {
		public:
			Cat();
			virtual ~Cat();
			void speak() const;
	};
}

#endif /* CAT_H_ */
