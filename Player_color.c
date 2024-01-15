//
// Created by mathi on 12/01/2024.
//

#include "Include.h"

bool CompareColors(struct Color color1, struct Color color2) {
    return (color1.r == color2.r) && (color1.g == color2.g) && (color1.b == color2.b);
}

void Change_player_color(SDL_Event event, struct Player *myPlayer, struct Window my_window, struct Color player_color_1, struct Color player_color_2, struct Color player_color_3, int *width_purple, int *height_purple, int *width_green, int *height_green, int *width_yellow, int *height_yellow) {

    bool color_1 = false;
    bool color_2 = false;
    bool color_3 = false;

    if (CompareColors(myPlayer->color, player_color_1)) {
        color_1 = true;
        color_2 = false;
        color_3 = false;
    } else if (CompareColors(myPlayer->color, player_color_2)) {
        color_2 = true;
        color_1 = false;
        color_3 = false;
    } else {
        color_3 = true;
        color_1 = false;
        color_2 = false;
    }

    // couleur violette
    if (((event.motion.x >= 175 * my_window.width / 1080) && (event.motion.x <= 325 * my_window.width / 1080) &&
         (event.motion.y >= 400 * my_window.height / 768) && (event.motion.y <= 550 * my_window.height / 768))) {
        *width_purple = 160 * my_window.width / 1080;
        *height_purple = 160 * my_window.height / 768;
        if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
            *width_purple = 140 * my_window.width / 1080;
            *height_purple = 140 * my_window.height / 768;
        } else if (event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT) {
            myPlayer->color = player_color_1;
        }
    } else if (color_1) {
        *width_purple = 170 * my_window.width / 1080;
        *height_purple = 170 * my_window.height / 768;
    } else {
        *width_purple = 150 * my_window.width / 1080;
        *height_purple = 150 * my_window.height / 768;
    }

    // couleur verte
    if (((event.motion.x >= 475 * my_window.width / 1080) && (event.motion.x <= 625 * my_window.width / 1080) &&
         (event.motion.y >= 400 * my_window.height / 768) && (event.motion.y <= 550 * my_window.height / 768))) {
        *width_green = 160 * my_window.width / 1080;
        *height_green = 160 * my_window.height / 768;
        if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
            *width_green = 140 * my_window.width / 1080;
            *height_green = 140 * my_window.height / 768;
        } else if (event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT) {
            myPlayer->color = player_color_2;
        }
    } else if (color_2) {
        *width_green = 170 * my_window.width / 1080;
        *height_green = 170 * my_window.height / 768;
    } else {
        *width_green = 150 * my_window.width / 1080;
        *height_green = 150 * my_window.height / 768;
    }

    // couleur jaune
    if (((event.motion.x >= 800 * my_window.width / 1080) && (event.motion.x <= 950 * my_window.width / 1080) &&
         (event.motion.y >= 400 * my_window.height / 768) && (event.motion.y <= 550 * my_window.height / 768))) {
        *width_yellow = 160 * my_window.width / 1080;
        *height_yellow = 160 * my_window.height / 768;
        if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
            *width_yellow = 140 * my_window.width / 1080;
            *height_yellow = 140 * my_window.height / 768;
        } else if (event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT) {
            myPlayer->color = player_color_3;
        }
    } else if (color_3) {
        *width_yellow = 170 * my_window.width / 1080;
        *height_yellow = 170 * my_window.height / 768;
    } else {
        *width_yellow = 150 * my_window.width / 1080;
        *height_yellow = 150 * my_window.height / 768;
    }
}