//
// Created by mathi on 08/12/2023.
//

#include "Include.h"

bool Get_anim_play_button(SDL_Event event, struct Window my_window, int *width_button, int *height_button) {

    if (((event.motion.x >= 490 * my_window.width / 1080) && (event.motion.x <= 490 * my_window.width / 1080 + 150 * my_window.width / 1080)
        && (event.motion.y >= 570 * my_window.height / 768) && (event.motion.y <= 570 * my_window.height / 768 + 150 * my_window.height / 768))) {
    *width_button = 160 * my_window.width / 1080;
    *height_button = 160 * my_window.height / 768;
        if(event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
            *width_button = 140 * my_window.width / 1080;
            *height_button = 140 * my_window.height / 768;
        } else if (event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT) {
            return true;
        }
    } else {
    *width_button = 150 * my_window.width / 1080;
    *height_button = 150 * my_window.height / 768;
    }
    return false;
}

bool Get_anim_settings_button(SDL_Event event, struct Window my_window, int *width_settings, int *height_settings) {

    if (((event.motion.x >= 1000 * my_window.width / 1080) && (event.motion.x <= 1000 * my_window.width / 1080 + 70 * my_window.width / 1080) &&
         (event.motion.y >= 10 * my_window.height / 768) && (event.motion.y <= 10 * my_window.height / 768 + 70 * my_window.height / 768))) {
        *width_settings = 80 * my_window.width / 1080;
        *height_settings = 80 * my_window.height / 768;
        if(event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
            *width_settings = 60 * my_window.width / 1080;
            *height_settings = 60 * my_window.height / 768;
        } else if (event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT) {
            return true;
        }
    } else {
        *width_settings = 70 * my_window.width / 1080;
        *height_settings = 70 * my_window.height / 768;
    }
    return false;
}

bool Get_anim_exit_menu_button(SDL_Event event, struct Window my_window, int *width_exit_button, int *height_exit_button) {
    if (event.type == SDL_QUIT || ((event.motion.x >= 15 * my_window.width / 1080) && (event.motion.x <= 85 * my_window.width / 1080) &&
                                   (event.motion.y >= 15 * my_window.height / 768) && (event.motion.y <= 85 * my_window.height / 768))) {
        *width_exit_button = 80 * my_window.width / 1080;
        *height_exit_button = 80 * my_window.height / 768;
        if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
            *width_exit_button = 60 * my_window.width / 1080;
            *height_exit_button = 60 * my_window.height / 768;
        } else if (event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT) {
            return true;
        }
    } else {
        *width_exit_button = 70 * my_window.width / 1080;
        *height_exit_button = 70 * my_window.height / 768;
    }
    return false;
}

bool Get_anim_exit_button(SDL_Event event, struct Window my_window, int *width_exit_button, int *height_exit_button) {
    if (event.type == SDL_QUIT || ((event.motion.x >= 1000 * my_window.width / 1080) && (event.motion.x <= 1060 * my_window.width / 1080) &&
                                   (event.motion.y >= 10 * my_window.height / 768) && (event.motion.y <= 70 * my_window.height / 768))) {
        *width_exit_button = 70 * my_window.width / 1080;
        *height_exit_button = 70 * my_window.height / 768;
        if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
            *width_exit_button = 50 * my_window.width / 1080;
            *height_exit_button = 50 * my_window.height / 768;
        } else if (event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT) {
            return true;
        }
    } else {
        *width_exit_button = 60 * my_window.width / 1080;
        *height_exit_button = 60 * my_window.height / 768;
    }
    return false;
}

bool Get_anim_play_again_button(SDL_Event event, struct Window my_window, int *width_play_again, int *height_play_again) {
    if (((event.motion.x >= 450 * my_window.width / 1080) && (event.motion.x <= 650 * my_window.width / 1080) &&
         (event.motion.y >= 600 * my_window.height / 768) && (event.motion.y <= 700 * my_window.height / 768))) {
        *width_play_again = 210 * my_window.width / 1080;
        *height_play_again = 110 * my_window.height / 768;
        if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
            *width_play_again = 190 * my_window.width / 1080;
            *height_play_again = 90 * my_window.height / 768;
        } else if (event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT) {
            return true;
        }
    } else {
        *width_play_again = 200 * my_window.width / 1080;
        *height_play_again = 100 * my_window.height / 768;
    }
    return false;
}

bool Get_anim_return_menu_button(SDL_Event event, struct Window my_window, int *width_return_menu, int *height_return_menu) {
    if (((event.motion.x >= 900 * my_window.width / 1080) && (event.motion.x <= 975 * my_window.width / 1080) &&
         (event.motion.y >= 10 * my_window.height / 768) && (event.motion.y <= 85 * my_window.height / 768))) {
        *width_return_menu = 85 * my_window.width / 1080;
        *height_return_menu = 85 * my_window.height / 768;
        if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
            *width_return_menu = 65 * my_window.width / 1080;
            *height_return_menu = 65 * my_window.height / 768;
        } else if (event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT) {
            return false;
        }
    } else {
        *width_return_menu = 75 * my_window.width / 1080;
        *height_return_menu = 75 * my_window.height / 768;
    }
    return true;
}
