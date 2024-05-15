#ifndef _KEYPRESS__H
#define _KEYPRESS__H

#include<SDL.h>
#include"defs.h"

struct Input{
    int keyboard[MAX_KEYBOARD_KEYS];

    void init(){
        memset(&keyboard, 0, sizeof(keyboard));
    }

    void doKeyDown(SDL_KeyboardEvent *event){
        if ( event->repeat == 0 && event->keysym.scancode < MAX_KEYBOARD_KEYS){
            keyboard[event->keysym.scancode] = 1;
        }
    }

    void doKeyUp(SDL_KeyboardEvent *event){
        if ( event->repeat == 0 && event->keysym.scancode < MAX_KEYBOARD_KEYS){
            keyboard[event->keysym.scancode] = 0;
        }
    }

    void getInput(SDL_Event e){
            switch (e.type){
                case SDL_QUIT:
                    exit(0);
                    break;
                case SDL_KEYDOWN:
                    doKeyDown(&e.key);
                    break;
                case SDL_KEYUP:
                    doKeyUp(&e.key);
                    break;
                default:
                    break;
            }
    }
};

#endif
