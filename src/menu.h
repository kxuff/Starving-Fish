#ifndef _MENU__H
#define _MENU__H

#include <SDL.h>
#include <SDL_image.h>
#include "defs.h"
#include "graphics.h"
#include <SDL_ttf.h>

struct Menu {
    SDL_Texture *background_menu, *option_menu, *start1, *start2, *exit1, *exit2, *highscore1, *highscore2, *back_option, *TextureTitle1,
    *ScoreTextTexture, *turnback, *turnback_2, *pause, *pause_2, *home, *home_2, *resume, *resume_2, *TextureGameover;
    int mouse_x, mouse_y, highScore;
    SDL_Color textColor1, textColor2, textColor3;
    TTF_Font* textTitle1, *textFontScore, *textGameover;
    stringstream Titlegame1, GameoverText, scoreText;
    void init(Graphics &graphics) {
        background_menu = graphics.loadTexture("background\\back_menu.png");
        option_menu = graphics.loadTexture("background\\option_menu.png");
        start1 = graphics.loadTexture("Menu\\start_game.png");
        start2 = graphics.loadTexture("Menu\\start_game_2.png");
        exit1 = graphics.loadTexture("Menu\\exit.png");
        exit2 = graphics.loadTexture("Menu\\exit_2.png");
        highscore1 = graphics.loadTexture("Menu\\high_score.png");
        highscore2 = graphics.loadTexture("Menu\\high_score_2.png");
        back_option = graphics.loadTexture("background\\option_back.png");
        turnback = graphics.loadTexture("Menu\\turnback.png");
        turnback_2 = graphics.loadTexture("Menu\\turnback_2.png");
        pause = graphics.loadTexture("Menu\\pause.png");
        pause_2 = graphics.loadTexture("Menu\\pause_2.png");
        resume = graphics.loadTexture("Menu\\resume.png");
        resume_2 = graphics.loadTexture("Menu\\resume_2.png");
        home = graphics.loadTexture("Menu\\home.png");
        home_2 = graphics.loadTexture("Menu\\home_2.png");
        textTitle1 = graphics.loadFont(TITLE_IMG, 90);
        textFontScore = graphics.loadFont(SCORE_IMG, 40);
        textGameover = graphics.loadFont(GAMEOVER_IMG, 80);
        textColor1 = {0, 250, 150, 200};
        textColor2 = {225, 225, 125, 235};
        textColor3 = {225, 0, 0, 0};
    }
    void drawMenu(Graphics &graphics) {
        graphics.renderTexture(background_menu, 0, 0);
        Titlegame1.str("");
        Titlegame1 << "STARVING FISH";
        TextureTitle1 = graphics.loadTextTexture(Titlegame1.str().c_str(), textColor1, textTitle1);
        graphics.renderTexture(TextureTitle1, 190, 50);
    }
    void drawHighscore(Graphics &graphics) {
        graphics.renderTexture(back_option, 0, 0);
        graphics.renderTexture(option_menu, 135, 100);
        scoreText.str("");
        scoreText << to_string(highScore);
        ScoreTextTexture = graphics.loadTextTexture(scoreText.str().c_str(), textColor2, textFontScore);
        graphics.renderTexture(ScoreTextTexture, SCREEN_WIDTH/2 - 10, SCREEN_HEIGHT/2 - 10);
    }
    void drawPause(Graphics &graphics) {
        graphics.renderTexture(back_option, 0, 0);
        graphics.renderTexture(option_menu, 135, 100);
    }
    void drawGameover(Graphics &graphics) {
        graphics.renderTexture(back_option, 0, 0);
        GameoverText.str("");
        GameoverText << "GAME OVER";
        TextureGameover = graphics.loadTextTexture(GameoverText.str().c_str(), textColor3, textGameover);
        graphics.renderTexture(TextureGameover, 250, 80);
    }
    void doMenu(logic& game, Graphics &graphics){
        SDL_Event event;
        SDL_GetMouseState(&mouse_x, &mouse_y);
        if ( mouse_x >= 287 && mouse_x <= 407 && mouse_y >= 199 && mouse_y <= 319){
            graphics.renderTexture(start2, SCREEN_WIDTH/2 - 150, SCREEN_HEIGHT/2 - 130);
        }
        else graphics.renderTexture(start1, SCREEN_WIDTH/2 - 150, SCREEN_HEIGHT/2 - 130);

        if ( mouse_x >= 482 && mouse_x <= 602 && mouse_y >= 309 && mouse_y <= 427){
            graphics.renderTexture(highscore2, SCREEN_WIDTH/2 + 50, SCREEN_HEIGHT/2 - 20);
        }
        else graphics.renderTexture(highscore1, SCREEN_WIDTH/2 + 50, SCREEN_HEIGHT/2 - 20);

        if ( mouse_x >= 287 && mouse_x <= 407 && mouse_y >= 424 && mouse_y <= 542){
            graphics.renderTexture(exit2, SCREEN_WIDTH/2 - 150, SCREEN_HEIGHT/2 + 95);
        }
        else graphics.renderTexture(exit1, SCREEN_WIDTH/2 - 150, SCREEN_HEIGHT/2 + 95);

        while (SDL_PollEvent(&event)){
            switch(event.type){
            case SDL_QUIT:
                exit(0);
                break;
            case SDL_MOUSEBUTTONDOWN:
                if ( mouse_x >= 287 && mouse_x <= 407 && mouse_y >= 199 && mouse_y <= 319){
                    game.status = 1;
                }
                if ( mouse_x >= 482 && mouse_x <= 602 && mouse_y >= 309 && mouse_y <= 427){
                    game.status = 2;
                }
                if ( mouse_x >= 287 && mouse_x <= 407 && mouse_y >= 424 && mouse_y <= 542){
                    exit(0);
                }
                break;
            }
        }
    }
    void doHighscore(logic &game, Graphics &graphics) {
        SDL_Event event;
        SDL_GetMouseState(&mouse_x, &mouse_y);
        if ( mouse_x >= 380 && mouse_x <= 460 && mouse_y >= 570 && mouse_y <= 650){
            graphics.renderTexture(turnback, 380, 570);
        }
        else graphics.renderTexture(turnback_2, 380, 570);
        while (SDL_PollEvent(&event)){
            switch(event.type){
            case SDL_QUIT:
                exit(0);
                break;
            case SDL_MOUSEBUTTONDOWN:
                if ( mouse_x >= 380 && mouse_x <= 530 && mouse_y >= 570 && mouse_y <= 650){
                    game.status = 0;
                }
                break;
            }
        }
    }
    void doPause(logic &game, Graphics &graphics) {
        SDL_Event event;
        SDL_GetMouseState(&mouse_x, &mouse_y);
        if ( mouse_x >= SCREEN_WIDTH/2 - 100&& mouse_x <= SCREEN_WIDTH/2 - 30 && mouse_y >= 300 && mouse_y <= 370){
            graphics.renderTexture(home_2, SCREEN_WIDTH/2 - 100, 300);
        }
        else graphics.renderTexture(home, SCREEN_WIDTH/2 - 100, 300);
        if ( mouse_x >= SCREEN_WIDTH/2 + 50 && mouse_x <= SCREEN_WIDTH/2 + 120 && mouse_y >= 300 && mouse_y <= 370){
            graphics.renderTexture(resume_2, SCREEN_WIDTH/2 + 50, 300);
        }
        else graphics.renderTexture(resume, SCREEN_WIDTH/2 + 50, 300);
        while (SDL_PollEvent(&event)){
            switch(event.type){
            case SDL_QUIT:
                exit(0);
                break;
            case SDL_MOUSEBUTTONDOWN:
                if ( mouse_x >= SCREEN_WIDTH/2 - 100&& mouse_x <= SCREEN_WIDTH/2 - 30 && mouse_y >= 300 && mouse_y <= 370) {
                    game.status = 0;
                }
                if( mouse_x >= SCREEN_WIDTH/2 + 50 && mouse_x <= SCREEN_WIDTH/2 + 120 && mouse_y >= 300 && mouse_y <= 370) {
                    game.status = 1;
                }
                break;
            }
        }
    }
    void doGameover(logic &game, Graphics &graphics) {
        SDL_Event event;
        SDL_GetMouseState(&mouse_x, &mouse_y);
        if ( mouse_x >= SCREEN_WIDTH/2 - 40&& mouse_x <= SCREEN_WIDTH/2 + 30 && mouse_y >= 300 && mouse_y <= 370){
            graphics.renderTexture(home_2, SCREEN_WIDTH/2 - 40, 300);
        }
        else graphics.renderTexture(home, SCREEN_WIDTH/2 - 40, 300);
        while (SDL_PollEvent(&event)){
            switch(event.type){
            case SDL_QUIT:
                exit(0);
                break;
            case SDL_MOUSEBUTTONDOWN:
                if ( mouse_x >= SCREEN_WIDTH/2 - 40&& mouse_x <= SCREEN_WIDTH/2 + 30 && mouse_y >= 300 && mouse_y <= 370) {
                    game.status = 0;
                }
                break;
            }
        }
    }
};
#endif
