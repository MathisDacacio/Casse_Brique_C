//
// Created by mathi on 09/01/2024.
//

#include "Include.h"

void check_collision_ball_block(struct Block block[], int nb_block, struct Ball *my_ball) {
    for (int i = 0; i < nb_block; ++i) {
        if (block[i].pv > 0 && my_ball->pos_x + my_ball->width >= block[i].rect.x &&
            my_ball->pos_x <= block[i].rect.x + block[i].rect.w &&
            my_ball->pos_y + my_ball->height >= block[i].rect.y &&
            my_ball->pos_y <= block[i].rect.y + block[i].rect.h) {

            block[i].pv--;
            if(block[i].pv == 0)
                my_ball->block_destroy++;

            // Calcul de vers où renvoyer la balle
            int collisionX = my_ball->pos_x + my_ball->width / 2 - (block[i].rect.x + block[i].rect.w / 2);
            int collisionY = my_ball->pos_y + my_ball->height / 2 - (block[i].rect.y + block[i].rect.h / 2);

            if (abs(collisionX) > abs(collisionY)) {
                // horizontale
                if (collisionX > 0) {
                    my_ball->speed_x = abs(my_ball->speed_x);
                } else {
                    my_ball->speed_x = -abs(my_ball->speed_x);
                }
            } else {
                // verticale
                if (collisionY > 0) {
                    my_ball->speed_y = abs(my_ball->speed_y);
                } else {
                    my_ball->speed_y = -abs(my_ball->speed_y);
                }
            }
            break;
        }
    }
}

void check_collision_ball_player(struct Player *my_player, struct Ball *my_ball) {
    if (my_ball->pos_x + my_ball->width >= my_player->pos_x &&
        my_ball->pos_x <= my_player->pos_x + my_player->width &&
        my_ball->pos_y + my_ball->height >= my_player->pos_y &&
        my_ball->pos_y <= my_player->pos_y + my_player->height) {

        // pour éviter le bug de balle bloquée dans la raquette
        if (my_ball->pos_y + my_ball->height > my_player->pos_y &&
            my_ball->pos_y < my_player->pos_y + my_player->height) {
            my_ball->pos_y = my_player->pos_y - my_ball->height;
        }
            // inverser la direction de la balle seulement si elle se dirige vers le joueur
        if (my_ball->speed_y > 0) {
            my_ball->speed_y = -my_ball->speed_y;
        }
    }
}


