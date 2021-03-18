/*
 * Swarm.h
 *
 *  Created on: 17 mar. 2021
 *      Author: sandrade
 */

#ifndef SWARM_H_
#define SWARM_H_

#include <SDL.h>
#include "Particle.h"

namespace fpg {

class Swarm {
	private:
		Particle* m_pParticles;

	public:
		const static int NPARTICLES = 8000;
		int lastUpdate;

	public:
		Swarm();
		virtual ~Swarm();
		void update(Uint32 elapsedTime);

		// the first const make each particle constant, and the second makes the pointer constant
		const Particle* const getParticles();
	};

} /* namespace fpg */

#endif /* SWARM_H_ */
