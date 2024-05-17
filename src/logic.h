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
#include <SDL_mixer.h>


using namespace std;

struct logic {
    Entity player;
    SDL_Texture* MinnowTexture, *PlayerTexture, *PlayerTextureRight, *MinnowTextureRight, *PlayerBiteLeft, *PlayerBiteRight, *BarraTexture,
    *ScoreTextTexture, *BarraTextureRight, *OrcaTexture, *OrcaTextureRight, *MarlinTexture, *MarlinTextureRight, *pause, *pause_2,
    *healthbar, *healthbarframe, *BombTexture, *SharkTexture, *SharkTextureRight, *LionfishTexture, *LionfishTextureRight, *ExplodeTexture;
    Mix_Music *MusicGame;
    Mix_Chunk *BiteSound, *ExplosionSound, *HurtSound;
    list<Entity*> Minnow, Barra, Orca, Marlin, Bomb, Shark, Lionfish;
    Uint32 MinnowTime = 0, BarraTime = 0, OrcaTime = 0, MarlinTime = 0, BombTime = 0, SharkTime = 0, LionfishTime = 0;
    int score = 0, status = 0, health = HEALTH, mouse_x, mouse_y;
    SDL_Color textColor;
    TTF_Font* textFont, *textFontHighScore, *textHealth;
    stringstream scoreText;

    void setBegin() {
        Minnow.clear();
        Barra.clear();
        Orca.clear();
        Marlin.clear();
        Lionfish.clear();
        Shark.clear();
        Bomb.clear();
        score = 0, health = HEALTH;
    }

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
        LionfishTexture = graphics.loadTexture(LIONFISH_SPRITE_FILE);
        LionfishTextureRight = graphics.loadTexture(LIONFISH_SPRITE_FILE_RIGHT);
        SharkTexture = graphics.loadTexture(SHARK_SPRITE_FILE);
        SharkTextureRight = graphics.loadTexture(SHARK_SPRITE_FILE_RIGHT);
        ExplodeTexture = graphics.loadTexture(EXPLODE_SPRITE_FILE);
        BombTexture = graphics.loadTexture("image\\bomb.png");
        pause = graphics.loadTexture("Menu\\pause.png");
        pause_2 = graphics.loadTexture("Menu\\pause_2.png");
        healthbar = graphics.loadTexture("image\\HealthBar.png");
        healthbarframe = graphics.loadTexture("image\\Frame_healthbar.png");
        MusicGame = graphics.loadMusic("asset\\underwater.mp3");
        BiteSound = graphics.loadSound("asset\\bite.mp3");
        ExplosionSound = graphics.loadSound("asset\\explosion.mp3");
        HurtSound = graphics.loadSound("asset\\hurt.mp3");
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
        player.dx = PLAYER_SPEED;
        player.dy = PLAYER_SPEED;
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
        bot->dx = BOT_SPEED;
        bot->dy = BOT_SPEED;

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
        bot->dx = BOT_SPEED;
        bot->dy = BOT_SPEED;

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
        bot->dx = BOT_SPEED;
        bot->dy = BOT_SPEED;

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
        bot->dx = BOT_SPEED;
        bot->dy = BOT_SPEED;

        bot->moveleft.RenderFish = 4;
        bot->moveleft.init(MarlinTexture, MARLIN_FRAMES, MARLIN_CLIPS);

        bot->moveright.RenderFish = 4;
        bot->moveright.init(MarlinTextureRight, MARLIN_FRAMES_RIGHT, MARLIN_CLIPS_RIGHT);
        Marlin.push_back(bot);
    }

    void InitLionFish() {
        Entity *bot = new Entity();
        bot->x = minnowposx[rand() % 2];
        bot->y = rand() % SCREEN_HEIGHT;
        bot->dx = BOT_SPEED;
        bot->dy = BOT_SPEED;

        bot->moveleft.RenderFish = 4;
        bot->moveleft.init(LionfishTexture, LIONFISH_FRAMES, LIONFISH_CLIPS);

        bot->moveright.RenderFish = 4;
        bot->moveright.init(LionfishTextureRight, LIONFISH_FRAMES_RIGHT, LIONFISH_CLIPS_RIGHT);
        Lionfish.push_back(bot);
    }

    void InitShark() {
        Entity *bot = new Entity();
        bot->x = minnowposx[rand() % 2];
        bot->y = rand() % SCREEN_HEIGHT;
        bot->dx = BOT_SPEED;
        bot->dy = BOT_SPEED;

        bot->moveleft.RenderFish = 4;
        bot->moveleft.init(SharkTexture, SHARK_FRAMES, SHARK_CLIPS);

        bot->moveright.RenderFish = 4;
        bot->moveright.init(SharkTextureRight, SHARK_FRAMES_RIGHT, SHARK_CLIPS_RIGHT);
        Shark.push_back(bot);
    }
    void InitBomb() {
        Entity *bot = new Entity();
        bot->x = rand() % (SCREEN_WIDTH - int(bot->w));
        bot->y = 0;
        bot->dx = 1;
        bot->dy = 1;
        player.exploded.RenderFish = 6;
        player.exploded.init(ExplodeTexture, EXPLODE_FRAMES, EXPLODE_CLIPS);
        Bomb.push_back(bot);
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

    void doGame(int KeyInput[], Graphics &graphics) {
        doPlayer(KeyInput);
        if(score <= SCORE_BARRA) {
            if(SDL_GetTicks() - MinnowTime >= 800) {
                InitMinnow();
                MinnowTime = SDL_GetTicks();
            }
            if(SDL_GetTicks() - BarraTime >= 1500) {
                InitBarra();
                BarraTime = SDL_GetTicks();
            }
            if(SDL_GetTicks() - OrcaTime >= 2500) {
                InitOrca();
                OrcaTime = SDL_GetTicks();
            }
            if(SDL_GetTicks() - MarlinTime >= 3000) {
                InitMarlin();
                MarlinTime = SDL_GetTicks();
            }
        }
        else if(score <= SCORE_ORCA) {
            if(SDL_GetTicks() - MinnowTime >= 2000) {
                InitMinnow();
                MinnowTime = SDL_GetTicks();
            }
            if(SDL_GetTicks() - BarraTime >= 1800) {
                InitBarra();
                BarraTime = SDL_GetTicks();
            }
            if(SDL_GetTicks() - OrcaTime >= 1500) {
                InitOrca();
                OrcaTime = SDL_GetTicks();
            }
            if(SDL_GetTicks() - MarlinTime >= 1200) {
                InitMarlin();
                MarlinTime = SDL_GetTicks();
            }
        }
        else if(score <= SCORE_MARLIN) {
            if(SDL_GetTicks() - MinnowTime >= 3000) {
                InitMinnow();
                MinnowTime = SDL_GetTicks();
            }
            if(SDL_GetTicks() - BarraTime >= 2500) {
                InitBarra();
                BarraTime = SDL_GetTicks();
            }
            if(SDL_GetTicks() - OrcaTime >= 1500) {
                InitOrca();
                OrcaTime = SDL_GetTicks();
            }
            if(SDL_GetTicks() - MarlinTime >= 1000) {
                InitMarlin();
                MarlinTime = SDL_GetTicks();
            }
            if(SDL_GetTicks() - LionfishTime >= 2000) {
                InitLionFish();
                LionfishTime = SDL_GetTicks();
            }
            if(SDL_GetTicks() - BombTime >= 3500) {
                InitBomb();
                BombTime = SDL_GetTicks();
            }

        }
        else if(score <= SCORE_LIONFISH) {
            if(SDL_GetTicks() - BarraTime >= 3000) {
                InitBarra();
                BarraTime = SDL_GetTicks();
            }
            if(SDL_GetTicks() - OrcaTime >= 2000) {
                InitOrca();
                OrcaTime = SDL_GetTicks();
            }
            if(SDL_GetTicks() - MarlinTime >= 1800) {
                InitMarlin();
                MarlinTime = SDL_GetTicks();
            }
            if(SDL_GetTicks() - LionfishTime >= 1200) {
                InitLionFish();
                LionfishTime = SDL_GetTicks();
            }
            if(SDL_GetTicks() - SharkTime >= 2000) {
                InitShark();
                SharkTime = SDL_GetTicks();
            }
            if(SDL_GetTicks() - BombTime >= 3000) {
                InitBomb();
                BombTime = SDL_GetTicks();
            }
        }
        else if(score <= SCORE_SHARK) {
            if(SDL_GetTicks() - OrcaTime >= 3000) {
                InitOrca();
                OrcaTime = SDL_GetTicks();
            }
            if(SDL_GetTicks() - MarlinTime >= 2000) {
                InitMarlin();
                MarlinTime = SDL_GetTicks();
            }
            if(SDL_GetTicks() - LionfishTime >= 1500) {
                InitLionFish();
                LionfishTime = SDL_GetTicks();
            }
            if(SDL_GetTicks() - SharkTime >= 1500) {
                InitShark();
                SharkTime = SDL_GetTicks();
            }
            if(SDL_GetTicks() - BombTime >= 3000) {
                InitBomb();
                BombTime = SDL_GetTicks();
            }
        }
        doMinnow();
        doBarra(graphics);
        doOrca(graphics);
        doMarlin(graphics);
        doLionfish(graphics);
        doShark(graphics);
        doBomb();
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
                    score += EAT_MINNOW;
                    player.caneat = 1;
                    player.hitting = true;
                }
            if(bot->offScreen() || sqrt((bot->x - player.x) * (bot->x - player.x) + (bot->y - player.y) * (bot->y - player.y)) < 25) {
                    delete bot;
                    Minnow.erase(tmp);
                }
            it++;
        }
    }

    void doBarra(Graphics &graphics) {
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
                if(bot->flipstatus == 0 && score >= SCORE_BARRA) {
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
                if(score >= SCORE_BARRA) {
                    score += EAT_BARRA;
                    player.caneat = 1;
                    player.hitting = true;
                }
                else{
                        health -= 10;
                        bot->vacham = true;
                        graphics.playSound(HurtSound);
                }
            }
            if(bot->offScreen() || sqrt((bot->x - player.x) * (bot->x - player.x) + (bot->y - player.y) * (bot->y - player.y)) < 25 && score >= SCORE_BARRA) {
                    delete bot;
                    Barra.erase(tmp);
                }
            it++;
        }
    }

    void doOrca(Graphics &graphics) {
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
                if(bot->flipstatus == 0 && score >= SCORE_ORCA) {
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
                if(score >= SCORE_ORCA) {
                    score += EAT_ORCA;
                    player.caneat = 1;
                    player.hitting = true;
                }
                else{
                        health -= 10;
                        bot->vacham = true;
                        graphics.playSound(HurtSound);
                }
            }
            if(bot->offScreen() || sqrt((bot->x - player.x) * (bot->x - player.x) + (bot->y - player.y) * (bot->y - player.y)) < 25 && score >= SCORE_ORCA) {
                    delete bot;
                    Orca.erase(tmp);
                }
            it++;
        }
    }

    void doMarlin(Graphics &graphics) {
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
                if(bot->flipstatus == 0 && score >= SCORE_MARLIN) {
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
                if(score >= SCORE_MARLIN) {
                    score += EAT_MARLIN;
                    player.caneat = 1;
                    player.hitting = true;
                }
                else{
                        health -= 10;
                        bot->vacham = true;
                        graphics.playSound(HurtSound);
                }
            }
            if(bot->offScreen() || sqrt((bot->x - player.x) * (bot->x - player.x) + (bot->y - player.y) * (bot->y - player.y)) < 25 && score >= SCORE_MARLIN) {
                    delete bot;
                    Marlin.erase(tmp);
                }
            it++;
        }
    }

    void doLionfish(Graphics &graphics) {
        auto it = Lionfish.begin();
        while(it != Lionfish.end()) {
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
                if(bot->flipstatus == 0 && score >= SCORE_MARLIN) {
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
                if(score >= SCORE_LIONFISH) {
                    score += EAT_LIONFISH;
                    player.caneat = 1;
                    player.hitting = true;
                }
                else{
                        health -= 10;
                        bot->vacham = true;
                        graphics.playSound(HurtSound);
                }
            }
            if(bot->offScreen() || sqrt((bot->x - player.x) * (bot->x - player.x) + (bot->y - player.y) * (bot->y - player.y)) < 25 && score >= SCORE_LIONFISH) {
                    delete bot;
                    Lionfish.erase(tmp);
                }
            it++;
        }
    }

    void doShark(Graphics &graphics) {
        auto it = Shark.begin();
        while(it != Shark.end()) {
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
                if(bot->flipstatus == 0 && score >= SCORE_SHARK) {
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
                if(score >= SCORE_SHARK) {
                    score += EAT_SHARK;
                    player.caneat = 1;
                    player.hitting = true;
                }
                else{
                        health -= 10;
                        bot->vacham = true;
                        graphics.playSound(HurtSound);
                }
            }
            if(bot->offScreen() || sqrt((bot->x - player.x) * (bot->x - player.x) + (bot->y - player.y) * (bot->y - player.y)) < 25 && score >= SCORE_SHARK) {
                    delete bot;
                    Shark.erase(tmp);
                }
            it++;
        }
    }
    void doBomb() {
        auto it = Bomb.begin();
        while(it != Bomb.end()) {
            auto tmp = it;
            Entity *bot = *tmp;
            bot->turnSouth();
            if(sqrt((bot->x - player.x) * (bot->x - player.x) + (bot->y - player.y) * (bot->y - player.y)) < 50 && !bot->vacham ) {
                    player.explode = 1;
                    health -= 20;
                    bot->vacham = true;
                    player.posx = bot->x - bot->w - 70;
                    player.posy = bot->y - 20;
            }
            if(bot->offScreen() || sqrt((bot->x - player.x) * (bot->x - player.x) + (bot->y - player.y) * (bot->y - player.y)) < 50) {
                    delete bot;
                    Bomb.erase(tmp);
                }
            it++;
        }
    }
    void drawGame(Graphics &graphics) {
        if(player.right) {
            player.moveright.tick();
            if(player.caneat == 0)
            graphics.render2(player.x, player.y, player.moveright, score);
        }
        else {
            player.moveleft.tick();
            if(player.caneat == 0)
            graphics.render2(player.x, player.y, player.moveleft, score);
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
        for(Entity* bot : Lionfish) {
            if(bot->right) {
                bot->moveright.tick();
                graphics.render(bot->x, bot->y, bot->moveright);
            }
            else {
                bot->moveleft.tick();
                graphics.render(bot->x, bot->y, bot->moveleft);
            }
        }
        for(Entity* bot : Shark) {
            if(bot->right) {
                bot->moveright.tick();
                graphics.render(bot->x, bot->y, bot->moveright);
            }
            else {
                bot->moveleft.tick();
                graphics.render(bot->x, bot->y, bot->moveleft);
            }
        }
        for(Entity* bot : Bomb) {
            graphics.renderTexture(BombTexture, bot->x, bot->y);
        }
        if(player.caneat == 1) {
            if(player.hitting) {
                player.hitting = false;
                graphics.playSound(BiteSound);
            }
            if(player.right) {
                player.biteright.tick();
                graphics.render(player.x, player.y, player.biteright);
            }
            else {
                player.biteleft.tick();
                graphics.render(player.x, player.y, player.biteleft);
            }
            if(player.biteright.currentFrame == PLAYER_BITE_FRAMES_RIGHT - 1 || player.biteleft.currentFrame == PLAYER_BITE_FRAMES_RIGHT - 1){
                player.caneat = 0;
                player.biteright.currentFrame = 0;
                player.biteleft.currentFrame = 0;
            }
        }
        if(player.explode) {
                graphics.playSound(ExplosionSound);
                player.exploded.tick();
                graphics.render(player.posx, player.posy, player.exploded);
                if(player.exploded.currentFrame == EXPLODE_FRAMES - 1){
                    player.exploded.currentFrame = 0;
                    player.explode = 0;
                    player.posx = 0;
                    player.posy = 0;
                }
            }
        scoreText.str("");
        scoreText << "Score: " << to_string(score);
        ScoreTextTexture = graphics.loadTextTexture(scoreText.str().c_str(), textColor, textFont);
        graphics.renderTexture(ScoreTextTexture, 10, 10);

        graphics.renderTexture(healthbarframe, SCREEN_WIDTH - 140, 10);
        graphics.renderTexture2(healthbar, SCREEN_WIDTH - 138, 12, health);
        if(gameover()) {
            Mix_HaltMusic();
            status = 4;
        }
        if(wingame()) {
            Mix_HaltMusic();
            status = 5;
        }
        graphics.play(MusicGame);
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
    int gameover() {
        return (health <= 0);
    }
    int wingame() {
        return (score >= WINSCORE);
    }
};
#endif
