//
// Created by eric on 8/1/18.
//

#ifndef PARTICLESIMULATOR_PARTICLE_H
#define PARTICLESIMULATOR_PARTICLE_H

namespace visual {
    struct Particle {
    public:
        double m_x;
        double m_y;

    private:
        double m_speed;
        double m_direction;

    public:
        Particle();

        virtual ~Particle();

        void update(int interval);

    private:
        void init();
    };
}

#endif //PARTICLESIMULATOR_PARTICLE_H
