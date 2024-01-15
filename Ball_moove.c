//
// Created by mathi on 08/01/2024.
//

#include "Include.h"

void Do_ball_moove(struct Player *my_player, struct Ball *my_ball, int level) {
    int speed = 4 * level;
    if (speed > 12)
        speed = 12;

    //moove au spawn
    if (my_player->d_press && my_ball->speed_x == 0 && my_ball->speed_y == 0) {
        my_ball->speed_x = speed;
        my_ball->speed_y = -speed;
    } else if (my_player->q_press && my_ball->speed_x == 0 && my_ball->speed_y == 0) {
        my_ball->speed_x = -speed;
        my_ball->speed_y = -speed;
    }
    // les murs en haut et sur les cotes
    // + respawn sur la raquette
    if (my_ball->speed_x != 0 && my_ball->speed_y != 0) {
        my_ball->pos_y += my_ball->speed_y;
        my_ball->pos_x += my_ball->speed_x;
        if(my_ball->pos_y >= 780) {
            my_ball->speed_x = 0;
            my_ball->speed_y = 0;
            my_ball->pos_x = my_player->pos_x + (my_player->width / 2) - 5;
            my_ball->pos_y = my_player->pos_y - 10;
            my_player->pv -= 1;
        } else if (my_ball->pos_y <= 0)
            my_ball->speed_y = -my_ball->speed_y;
        if(my_ball->pos_x <= 0 || my_ball->pos_x >= 1080 - my_ball->width)
            my_ball->speed_x = -my_ball->speed_x;
        }
}