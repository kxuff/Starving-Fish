#ifndef ENTITY_H
#define ENTITY_H

#include<iostream>
using namespace std;

struct Entity {
    double x, y, dx, dy, health, w, h, flipstatus = 0, caneat = 0, explode = 0, posx = 0 , posy = 0;
    SDL_Texture* texture;
    Sprite moveleft, moveright, biteright, biteleft, exploded;
    bool vacham = false, hitting = false;
    bool right = true;
    void setBegin() {
        flipstatus = 0, caneat = 0, explode = 0, posx = 0, posy = 0;
    }
	void move() {
	    x += dx;
	    y += dy;
	}
    void turnNorth() {
        y -= dy;
    }

    void turnSouth() {
        y += dy;
    }
    void turnWest() {
        x -= dx;
    }

    void turnEast() {
        x += dx;
    }
	bool offScreen() {
	     return (x <= -w || y <= 0 || x >= SCREEN_WIDTH || y >= SCREEN_HEIGHT);
	}
};

#endif
