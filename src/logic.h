#ifndef LOGIC_H
#define LOGIC_H

#include<bits/stdc++.h>
#include<SDL.h>
#include<SDL_image.h>
#include "Entity.h"
#include "graphics.h"
#include "defs.h"
#include "keypress.h"
#include <SDL_ttf.h>



using namespace std;

struct logic {
    Entity player;
    SDL_Texture* MinnowTexture, *PlayerTexture, *PlayerTextureRight, *MinnowTextureRight, *PlayerBiteLeft, *PlayerBiteRight, *BarraTexture,
    *ScoreTextTexture, *BarraTextureRight, *OrcaTexture, *OrcaTextureRight, *MarlinTexture, *MarlinTextureRight, *pause, *pause_2;
    list<Entity*> Minnow, Barra, Orca, Marlin;
    Uint32 MinnowTime = 0, BarraTime = 0, OrcaTime = 0, MarlinTime = 0;
    int score = 0, status = 0, highScore = 0, health = HEALTH, tmp1 = HEALTH, mouse_x, mouse_y, frameCount, lastFrame;
    SDL_Color textColor;
    TTF_Font* textFont, *textFontHighScore, *textHealth;
    stringstream scoreText;

    void InitGame(Graphics &graphics) {
        MinnowTexture = graphics.loadTexture(MINNOW_SPRITE_FILE);
        PlayerTexture = graphics.loadTexture(PLAYER_SPRITE_FILE);
        PlayerTextureRight = graphics.loadTexture(PLAYER_SPRITE_FILE_RIGHT);
        MinnowTextureRight = graphics.loadTexture(MINNOW_SPRITE_FILE_RIGHT);
        PlayerBiteLeft = graphics.loadTexture(PLAYER_BITE_SPRITE_FILE);
        PlayerBiteRight = graphics.loadTexture(PLAYER_BITE_SPRITE_FILE_RIGHT);
        BarraTexture = graphics.loadTexture(BARRA_SPRITE_FILE);
        BarraTextureRight = graphics.loadTexture(BARRA_SPRITE_FILE_RIGHT);
        OrcaTexture = graphics.loadTexture(ORCA_SPRITE_FILE);
        OrcaTextureRight = graphics.loadTexture(ORCA_SPRITE_FILE_RIGHT);
        MarlinTexture = graphics.loadTexture(MARLIN_SPRITE_FILE);
        MarlinTextureRight = graphics.loadTexture(MARLIN_SPRITE_FILE_RIGHT);
        pause = graphics.loadTexture("Menu\\pause.png");
        pause_2 = graphics.loadTexture("Menu\\pause_2.png");
        textFont = graphics.loadFont(SCORE_IMG, 25);
        textFontHighScore = graphics.loadFont(SCORE_IMG, 50);
        textHealth = graphics.loadFont(SCORE_IMG, 25);
        textColor = {225, 225, 125, 235};
        InitPlayer();
    }

    void InitPlayer() {
        player.x = SCREEN_HEIGHT/2;
        player.y = SCREEN_WIDTH/2;
        player.w = 50;
        player.h = 45;
        player.dx = 3;
        player.dy = 3;
        player.health = 50;

        player.moveleft.RenderFish = 4;
        player.moveleft.init(PlayerTexture, PLAYER_FRAMES, PLAYER_CLIPS);

        player.moveright.RenderFish = 4;
        player.moveright.init(PlayerTextureRight, PLAYER_FRAMES_RIGHT, PLAYER_CLIPS_RIGHT);

        player.biteright.RenderFish = 6;
        player.biteright.init(PlayerBiteRight, PLAYER_BITE_FRAMES_RIGHT, PLAYER_BITE_CLIPS_RIGHT);

        player.biteleft.RenderFish = 6;
        player.biteleft.init(PlayerBiteLeft, PLAYER_BITE_FRAMES, PLAYER_BITE_CLIPS);

    }

    void InitMinnow() {
        Entity *bot = new Entity();
        bot->x = minnowposx[rand() % 2];
        bot->y = rand() % SCREEN_HEIGHT;
        bot->dx = 2;
        bot->dy = 2;

        bot->moveleft.RenderFish = 4;
        bot->moveleft.init(MinnowTexture, MINNOW_FRAMES, MINNOW_CLIPS);

        bot->moveright.RenderFish = 4;
        bot->moveright.init(MinnowTextureRight, MINNOW_FRAMES_RIGHT, MINNOW_CLIPS_RIGHT);
        Minnow.push_back(bot);
    }

    void InitBarra() {
        Entity *bot = new Entity();
        bot->x = minnowposx[rand() % 2];
        bot->y = rand() % SCREEN_HEIGHT;
        bot->dx = 2;
        bot->dy = 2;

        bot->moveleft.RenderFish = 4;
        bot->moveleft.init(BarraTexture, BARRA_FRAMES, BARRA_CLIPS);

        bot->moveright.RenderFish = 4;
        bot->moveright.init(BarraTextureRight, BARRA_FRAMES_RIGHT, BARRA_CLIPS_RIGHT);
        Barra.push_back(bot);
    }

    void InitOrca() {
        Entity *bot = new Entity();
        bot->x = minnowposx[rand() % 2];
        bot->y = rand() % SCREEN_HEIGHT;
        bot->dx = 2;
        bot->dy = 2;

        bot->moveleft.RenderFish = 4;
        bot->moveleft.init(OrcaTexture, ORCA_FRAMES, ORCA_CLIPS);

        bot->moveright.RenderFish = 4;
        bot->moveright.init(OrcaTextureRight, ORCA_FRAMES_RIGHT, ORCA_CLIPS_RIGHT);
        Orca.push_back(bot);
    }

    void InitMarlin() {
        Entity *bot = new Entity();
        bot->x = minnowposx[rand() % 2];
        bot->y = rand() % SCREEN_HEIGHT;
        bot->dx = 2;
        bot->dy = 2;

        bot->moveleft.RenderFish = 4;
        bot->moveleft.init(MarlinTexture, MARLIN_FRAMES, MARLIN_CLIPS);

        bot->moveright.RenderFish = 4;
        bot->moveright.init(MarlinTextureRight, MARLIN_FRAMES_RIGHT, MARLIN_CLIPS_RIGHT);
        Marlin.push_back(bot);
    }
    void doPlayer(int KeyInput[]) {
        if(KeyInput[SDL_SCANCODE_DOWN] && player.y <= SCREEN_HEIGHT - player.h) {
            player.turnSouth();
        }
        if(KeyInput[SDL_SCANCODE_UP] && player.y >= 0) {
            player.turnNorth();
        }
        if(KeyInput[SDL_SCANCODE_LEFT] && player.x >= 0) {
            player.turnWest();
            player.right = false;
        }
        if(KeyInput[SDL_SCANCODE_RIGHT] && player.x <= SCREEN_WIDTH - player.w) {
            player.turnEast();
            player.right = true;
        }
    }

    void doGame(int KeyInput[]) {
        doPlayer(KeyInput);
        if(score <= 200) {
            if(SDL_GetTicks() - MinnowTime >= 600) {
                InitMinnow();
                MinnowTime = SDL_GetTicks();
            }
            if(SDL_GetTicks() - BarraTime >= 1500) {
                InitBarra();
                BarraTime = SDL_GetTicks();
            }
            if(SDL_GetTicks() - OrcaTime >= 2000) {
                InitOrca();
                OrcaTime = SDL_GetTicks();
            }
            if(SDL_GetTicks() - MarlinTime >= 2000) {
                InitMarlin();
                MarlinTime = SDL_GetTicks();
            }
        }
        else if(score <= 300) {
            if(SDL_GetTicks() - MinnowTime >= 2000) {
                InitMinnow();
                MinnowTime = SDL_GetTicks();
            }
            if(SDL_GetTicks() - BarraTime >= 1800) {
                InitBarra();
                BarraTime = SDL_GetTicks();
            }
            if(SDL_GetTicks() - OrcaTime >= 1200) {
                InitOrca();
                OrcaTime = SDL_GetTicks();
            }
            if(SDL_GetTicks() - MarlinTime >= 1200) {
                InitMarlin();
                MarlinTime = SDL_GetTicks();
            }
        }
        else if(score <= 500) {
            if(SDL_GetTicks() - MinnowTime >= 2500) {
                InitMinnow();
                MinnowTime = SDL_GetTicks();
            }
            if(SDL_GetTicks() - BarraTime >= 2000) {
                InitBarra();
                BarraTime = SDL_GetTicks();
            }
            if(SDL_GetTicks() - OrcaTime >= 1600) {
                InitOrca();
                OrcaTime = SDL_GetTicks();
            }
            if(SDL_GetTicks() - MarlinTime >= 1000) {
                InitMarlin();
                MarlinTime = SDL_GetTicks();
            }
        }
        doMinnow();
        doBarra();
        doOrca();
        doMarlin();
    }

    void doMinnow() {
        auto it = Minnow.begin();
        while(it != Minnow.end()) {
            auto tmp = it;
            Entity *bot = *tmp;
            if(bot->x == 0) {
                bot->right = true;
            }
            else if(bot->x == SCREEN_WIDTH) {
                bot->right = false;
            }
            if(bot->right) {
                bot->turnEast();
            }
            else {
                bot->turnWest();
            }
            if(sqrt((bot->x - player.x) * (bot->x - player.x) + (bot->y - player.y) * (bot->y - player.y))<= 50 &&
               sqrt((bot->x - player.x) * (bot->x - player.x) + (bot->y - player.y) * (bot->y - player.y))>= 25 ) {
                if(bot->flipstatus == 0) {
                    if(bot->right) {
                        bot->turnWest();
                        bot->right = false;
                    }
                    else {
                        bot->turnEast();
                        bot->right = true;
                    }
                    bot->flipstatus = 1;
                }
            }
            if(sqrt((bot->x - player.x) * (bot->x - player.x) + (bot->y - player.y) * (bot->y - player.y)) < 25) {
                    score += 10;
                    tmp1 += 20;
                    player.caneat = 1;
                    highScore = max(highScore, score);
                }
            if(bot->offScreen() || sqrt((bot->x - player.x) * (bot->x - player.x) + (bot->y - player.y) * (bot->y - player.y)) < 25) {
                    player.caneat = 1;
                    delete bot;
                    Minnow.erase(tmp);
                }
            it++;
        }
    }

    void doBarra() {
        auto it = Barra.begin();
        while(it != Barra.end()) {
            auto tmp = it;
            Entity *bot = *tmp;
            if(bot->x == 0) {
                bot->right = true;
            }
            else if(bot->x == SCREEN_WIDTH) {
                bot->right = false;
            }
            if(bot->right) {
                bot->turnEast();
                if(player.y < bot->y) bot->y -= 0.75;
                else if(player.y > bot->y) bot->y += 0.75;
            }
            else {
                bot->turnWest();
                if(player.y < bot->y) bot->y -= 0.75;
                else if(player.y > bot->y) bot->y += 0.75;
            }
            if(sqrt((bot->x - player.x) * (bot->x - player.x) + (bot->y - player.y) * (bot->y - player.y))<= 50 &&
               sqrt((bot->x - player.x) * (bot->x - player.x) + (bot->y - player.y) * (bot->y - player.y))>= 25 ) {
                if(bot->flipstatus == 0 && score >= 200) {
                    if(bot->right) {
                        bot->turnWest();
                        bot->right = false;
                    }
                    else {
                        bot->turnEast();
                        bot->right = true;
                    }
                    bot->flipstatus = 1;
                }
            }
            if(sqrt((bot->x - player.x) * (bot->x - player.x) + (bot->y - player.y) * (bot->y - player.y)) < 25 && !bot->vacham ) {
                if(score >= 200) {
                    score += 8;
                    player.caneat = 1;
                    highScore = max(highScore, score);
                }
                else{
                        health -= 10;
                        bot->vacham = true;
                }
            }
            if(bot->offScreen() || sqrt((bot->x - player.x) * (bot->x - player.x) + (bot->y - player.y) * (bot->y - player.y)) < 25 && score >= 200) {
                    player.caneat = 1;
                    delete bot;
                    Barra.erase(tmp);
                }
            it++;
        }
    }

    void doOrca() {
        auto it = Orca.begin();
        while(it != Orca.end()) {
            auto tmp = it;
            Entity *bot = *tmp;
            if(bot->x == 0) {
                bot->right = true;
            }
            else if(bot->x == SCREEN_WIDTH) {
                bot->right = false;
            }
            if(bot->right) {
                bot->turnEast();
                if(player.y < bot->y) bot->y -= 0.5;
                else if(player.y > bot->y) bot->y += 0.5;
            }
            else {
                bot->turnWest();
                if(player.y < bot->y) bot->y -= 0.5;
                else if(player.y > bot->y) bot->y += 0.5;
            }
            if(sqrt((bot->x - player.x) * (bot->x - player.x) + (bot->y - player.y) * (bot->y - player.y))<= 50 &&
               sqrt((bot->x - player.x) * (bot->x - player.x) + (bot->y - player.y) * (bot->y - player.y))>= 25 ) {
                if(bot->flipstatus == 0 && score >= 300) {
                    if(bot->right) {
                        bot->turnWest();
                        bot->right = false;
                    }
                    else {
                        bot->turnEast();
                        bot->right = true;
                    }
                    bot->flipstatus = 1;
                }
            }
            if(sqrt((bot->x - player.x) * (bot->x - player.x) + (bot->y - player.y) * (bot->y - player.y)) < 25 && !bot->vacham ) {
                if(score >= 300) {
                    score += 8;
                    player.caneat = 1;
                    highScore = max(highScore, score);
                }
                else{
                        health -= 10;
                        bot->vacham = true;
                }
            }
            if(bot->offScreen() || sqrt((bot->x - player.x) * (bot->x - player.x) + (bot->y - player.y) * (bot->y - player.y)) < 25 && score >= 300) {
                    player.caneat = 1;
                    delete bot;
                    Orca.erase(tmp);
                }
            it++;
        }
    }

    void doMarlin() {
        auto it = Marlin.begin();
        while(it != Marlin.end()) {
            auto tmp = it;
            Entity *bot = *tmp;
            if(bot->x == 0) {
                bot->right = true;
            }
            else if(bot->x == SCREEN_WIDTH) {
                bot->right = false;
            }
            if(bot->right) {
                bot->turnEast();
                if(player.y < bot->y) bot->y -= 0.5;
                else if(player.y > bot->y) bot->y += 0.5;
            }
            else {
                bot->turnWest();
                if(player.y < bot->y) bot->y -= 0.5;
                else if(player.y > bot->y) bot->y += 0.5;
            }
            if(sqrt((bot->x - player.x) * (bot->x - player.x) + (bot->y - player.y) * (bot->y - player.y))<= 50 &&
               sqrt((bot->x - player.x) * (bot->x - player.x) + (bot->y - player.y) * (bot->y - player.y))>= 25 ) {
                if(bot->flipstatus == 0 && score >= 450) {
                    if(bot->right) {
                        bot->turnWest();
                        bot->right = false;
                    }
                    else {
                        bot->turnEast();
                        bot->right = true;
                    }
                    bot->flipstatus = 1;
                }
            }
            if(sqrt((bot->x - player.x) * (bot->x - player.x) + (bot->y - player.y) * (bot->y - player.y)) < 25 && !bot->vacham ) {
                if(score >= 450) {
                    score += 8;
                    player.caneat = 1;
                    highScore = max(highScore, score);
                }
                else{
                        health -= 10;
                        bot->vacham = true;
                }
            }
            if(bot->offScreen() || sqrt((bot->x - player.x) * (bot->x - player.x) + (bot->y - player.y) * (bot->y - player.y)) < 25 && score >= 450) {
                    player.caneat = 1;
                    delete bot;
                    Marlin.erase(tmp);
                }
            it++;
        }
    }
    void drawGame(Graphics &graphics) {
        if(player.right) {
            player.moveright.tick();
            graphics.render(player.x, player.y, player.moveright);
        }
        else {
            player.moveleft.tick();
            graphics.render(player.x, player.y, player.moveleft);
        }
        for(Entity* bot : Minnow) {
            if(bot->right) {
                bot->moveright.tick();
                graphics.render(bot->x, bot->y, bot->moveright);
            }
            else {
                bot->moveleft.tick();
                graphics.render(bot->x, bot->y, bot->moveleft);
            }
        }
        for(Entity* bot : Barra) {
            if(bot->right) {
                bot->moveright.tick();
                graphics.render(bot->x, bot->y, bot->moveright);
            }
            else {
                bot->moveleft.tick();
                graphics.render(bot->x, bot->y, bot->moveleft);
            }
        }
        for(Entity* bot : Orca) {
            if(bot->right) {
                bot->moveright.tick();
                graphics.render(bot->x, bot->y, bot->moveright);
            }
            else {
                bot->moveleft.tick();
                graphics.render(bot->x, bot->y, bot->moveleft);
            }
        }
        for(Entity* bot : Marlin) {
            if(bot->right) {
                bot->moveright.tick();
                graphics.render(bot->x, bot->y, bot->moveright);
            }
            else {
                bot->moveleft.tick();
                graphics.render(bot->x, bot->y, bot->moveleft);
            }
        }
        if(player.caneat == 1) {
            if(player.right) {
                player.biteright.tick();
                graphics.render(player.x, player.y, player.biteright);
            }
            else {
                player.biteleft.tick();
                graphics.render(player.x, player.y, player.biteleft);
            }
            player.caneat = 0;
        }
        scoreText.str("");
        scoreText << "Score: " << to_string(score);
        ScoreTextTexture = graphics.loadTextTexture(scoreText.str().c_str(), textColor, textFont);
        graphics.renderTexture(ScoreTextTexture, 10, 10);

        scoreText.str("");
        scoreText << "Health: " << to_string(health);
        ScoreTextTexture = graphics.loadTextTexture(scoreText.str().c_str(), textColor, textHealth);
        graphics.renderTexture(ScoreTextTexture, SCREEN_WIDTH - 150, 10);
        if(gameover()) status = 4;
    }

    void doPause(Graphics &graphics) {
        SDL_Event event;
        SDL_GetMouseState(&mouse_x, &mouse_y);
        if ( mouse_x >= SCREEN_WIDTH/2 && mouse_x <= SCREEN_WIDTH/2 + 30 && mouse_y >= 10 && mouse_y <= 40){
            graphics.renderTexture(pause_2, SCREEN_WIDTH/2, 10);
        }
        else graphics.renderTexture(pause, SCREEN_WIDTH/2, 10);
        while (SDL_PollEvent(&event)){
            switch(event.type){
            case SDL_QUIT:
                exit(0);
                break;
            case SDL_MOUSEBUTTONDOWN:
                if ( mouse_x >= SCREEN_WIDTH/2 && mouse_x <= SCREEN_WIDTH/2 + 30 && mouse_y >= 10 && mouse_y <= 40){
                    status = 3;
                }
                break;
            }
        }
    }

    void getheatlh(){
        health  = tmp1 - 10*(SDL_GetTicks()/1000);
    }
    int gameover() {
        return (health <= 0);
    }

};
#endif
