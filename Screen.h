//
// Created by eric on 5/13/18.
//

#ifndef PARTICLESIMULATOR_SCREEN_H
#define PARTICLESIMULATOR_SCREEN_H


#include <SDL2/SDL.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_keyboard.h>

namespace visual {
    class Screen {
    public:
        static const int SCREEN_WIDTH = 800;
        static const int SCREEN_HEIGHT = 600;


    private:
        SDL_Window *m_window;
        SDL_Renderer *m_renderer;
        SDL_Texture *m_texture;
        Uint32 *m_buffer1;
        Uint32 *m_buffer2;

    public:
        Screen();

        bool init();

        bool processEvents();

        void update();

        void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);

        void close();

        void clear();

        void boxBlur();
    };
}

#endif //PARTICLESIMULATOR_SCREEN_H
