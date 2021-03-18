/*
 * Particle.h
 *
 *  Created on: 17 mar. 2021
 *      Author: sandrade
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

#include <stdlib.h>
#include <SDL.h>

namespace fpg {
	// the only difference with class, is that structs have members as public for default
	struct Particle {
		double m_x;
		double m_y;

	private:
		double m_speed;
		double m_direction;

	private:
		void init();

	public:
		Particle();
		virtual ~Particle();
		void update(Uint32 interval);
	};

} /* namespace fpg */

#endif /* PARTICLE_H_ */
