//
// Created by mathi on 04/12/2023.
//

#include "Include.h"

void Get_player_moove(struct Player *my_player, SDL_Event event) {

    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_d) {
        my_player->d_press = true;
    } else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_q) {
        my_player->q_press = true;
    } else if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_d) {
        my_player->d_press = false;
    } else if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_q) {
        my_player->q_press = false;
    }
}

void Do_player_moove(struct Player *my_player, struct Window my_window, int level) {
    int speed = 5 * level;
    if (speed > 15)
        speed = 15;

    if (my_player->d_press && my_player->pos_x <= (1080 * my_window.width / 1080) - my_player->width) {
        my_player->pos_x += speed * my_window.width / 1080;
    }
    if (my_player->q_press && my_player->pos_x >= 0) {
        my_player->pos_x -= speed * my_window.width / 1080;
    }
}
