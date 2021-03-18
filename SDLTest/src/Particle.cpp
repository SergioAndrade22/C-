/*
 * Particle.cpp
 *
 *  Created on: 17 mar. 2021
 *      Author: sandrade
 */

#include "Particle.h"
#include "Screen.h"
#include <math.h>

namespace fpg {

	Particle::Particle() {
		init();
	}

	void Particle::init() {
		m_x = 0;
		m_y = 0;
		m_direction = (2.0 * M_PI * rand())/RAND_MAX; // this way we obtain the radian angle
		m_speed = pow((0.4 * rand())/RAND_MAX, 3.0);
	}

	Particle::~Particle() {
		// TODO Auto-generated destructor stub
	}

	void Particle::update(Uint32 interval) {

		m_direction += interval * 0.001;

		double xSpeed = m_speed * cos(m_direction);
		double ySpeed = m_speed * sin(m_direction);

		m_x += xSpeed * interval;
		m_y += ySpeed * interval;

		if (m_x < -1 || m_x > 1 || m_y < -1 || m_y > 1){
			init();
		}

		if (rand() < (RAND_MAX/100)) {
			init();
		}
	}
} /* namespace fpg */
