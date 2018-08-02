#include <iostream>
#include <cstdio>
#include <cmath>
#include "Screen.h"
#include <cstdlib>
#include <ctime>
#include "Swarm.h"
#include <random>

using namespace std;
using namespace visual;


int main() {

    srand(time(nullptr));

    Screen screen;

    if (!screen.init()) {
        cout << "Error initializing screen" << endl;
    }

    Swarm swarm;
    screen.clear();

    while (true) {

        int elapsed = SDL_GetTicks();

        //screen.clear();
        swarm.update(elapsed);

        double green = (1 + sin(elapsed * 0.0005)) * 127.5;
        double red = (1 + sin(elapsed * 0.001)) * 127.5;
        double blue = (1 + sin(elapsed * 0.00075)) * 127.5;


//        for(int y=0; y<Screen::SCREEN_HEIGHT; y++){
//            for (int x = 0; x < Screen::SCREEN_WIDTH; ++x) {
//                screen.setPixel(x, y, 0, 0, 0);
//            }
//        }

        const Particle *const pParticles = swarm.getParticles();
        for (int i = 0; i < Swarm::NPARTICLES; ++i) {
            Particle particle = pParticles[i];
            auto x = (int) ((particle.m_x + 1) * Screen::SCREEN_WIDTH / 2);
            auto y = (int) (particle.m_y * Screen::SCREEN_WIDTH / 2 + Screen::SCREEN_HEIGHT / 2);
            screen.setPixel(x, y, red, green, blue);
        }
        if (!screen.processEvents())
            break;

        screen.boxBlur();

        screen.update();
    }

    screen.close();

    return 0;
}