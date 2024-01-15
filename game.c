//
// Created by mathi on 04/12/2023.
//

#include "Include.h"

void Display_life(SDL_Renderer *renderer, struct Player *myPlayer, struct life_remain *myLife) {
    for (int i = 0; i < myPlayer->pv; i++) {
        SDL_Rect life = {10 + (i * 15), 10, 10, 10};
        SDL_SetRenderDrawColor(renderer, myLife->color.r, myLife->color.g, myLife->color.b, 255);
        SDL_RenderFillRect(renderer, &life);
    }
}

int my_game(SDL_Renderer *renderer, struct Window my_window, struct Player *myPlayer, int level) {
    SDL_bool quit = false;
    SDL_Event event;

    //create life struct (les pv du joueur)
    struct Color life_color = {0, 255, 255};
    struct life_remain my_life = {life_color};
    struct life_remain *myLife = &my_life;

    //create ball
    struct Color ball_color = {255, 255, 255};
    struct Ball my_ball = {myPlayer->pos_x + (myPlayer->width / 2) - 5, myPlayer->pos_y - 10, 10, 10, 0, 0, 0, ball_color};
    struct Ball *myBall = &my_ball;

    //augmentation nb block
    int nb_block = rand() % (9 * level) + (8 * level); // 8 à 16 niveau 1
    if (nb_block > 72) {
        nb_block = 72;
        myPlayer->width -= 20; // ajout de difficulté mais c'est deja tres dur
    }
    struct Block block[nb_block];
    Generate_block(block, nb_block);

    int lastTimer = SDL_GetTicks();
    bool win = false;
    bool loose = false;

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
                break;
            } else if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
                quit = true;
                break;
            }
            Get_player_moove(myPlayer, event);
        }

        if(SDL_GetTicks() - lastTimer > 16) {
            Do_player_moove(myPlayer, my_window, level);
            Do_ball_moove(myPlayer, myBall, level);

            check_collision_ball_player(myPlayer, myBall);
            check_collision_ball_block(block, nb_block, myBall);

            win = player_win(myBall, nb_block);
            loose = player_loose(myPlayer);

            if (win) {
                quit = true;
                level++;
                my_game(renderer, my_window, myPlayer, level);
            }

            if (loose) {
                quit = true;
                loose_screen(renderer, my_window, myPlayer);
            }

            lastTimer = SDL_GetTicks();
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        Display_block(renderer, block, nb_block);

        // afficher la balle
        SDL_Rect ball = {myBall->pos_x, myBall->pos_y, myBall->width, myBall->height};
        SDL_SetRenderDrawColor(renderer, myBall->color.r, myBall->color.g, myBall->color.b, 255);
        SDL_RenderFillRect(renderer, &ball);

        // afficher la raquette
        SDL_Rect player = {myPlayer->pos_x, myPlayer->pos_y, myPlayer->width, myPlayer->height};
        SDL_SetRenderDrawColor(renderer, myPlayer->color.r, myPlayer->color.g, myPlayer->color.b, 255);
        SDL_RenderFillRect(renderer, &player);

        // afficher pv du joueur
        Display_life(renderer, myPlayer, myLife);

        SDL_RenderPresent(renderer);
    }
    return 0;
}