/*
 * Swarm.cpp
 *
 *  Created on: 17 mar. 2021
 *      Author: sandrade
 */

#include "Swarm.h"

namespace fpg {

	Swarm::Swarm(): lastUpdate(0) {
		m_pParticles = new Particle[NPARTICLES];

	}

	Swarm::~Swarm() {
		delete [] m_pParticles;
	}

	const Particle* const Swarm::getParticles() {
		return m_pParticles;
	}

	void Swarm::update(Uint32 elapsedTime) {
		int interval = elapsedTime - lastUpdate;
		for (int i = 0; i < NPARTICLES; i++) {
			m_pParticles[i].update(interval);
		}
		lastUpdate = elapsedTime;
	}
} /* namespace fpg */
