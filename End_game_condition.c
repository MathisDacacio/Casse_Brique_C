//
// Created by mathi on 10/01/2024.
//

#include "Include.h"

bool player_loose(struct Player *my_player) {
    if (my_player->pv == 0) {
        return true;
    }
    return false;
}

bool player_win(struct Ball *my_ball, int nb_block) {
    if (my_ball->block_destroy == nb_block) {
        my_ball->block_destroy = 0;
        return true;
    }
    return false;
}