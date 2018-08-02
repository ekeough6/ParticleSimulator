//
// Created by eric on 8/1/18.
//

#ifndef PARTICLESIMULATOR_SWARM_H
#define PARTICLESIMULATOR_SWARM_H

#include "Particle.h"

namespace visual {
    class Swarm {
    public:
        const static int NPARTICLES = 5000;

    private:
        Particle *m_pParticles;
        int lastTime;
    public:
        Swarm();

        virtual ~Swarm();

        const Particle *const getParticles() { return m_pParticles; };

        void update(int elapsed);
    };
}


#endif //PARTICLESIMULATOR_SWARM_H
