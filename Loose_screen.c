//
// Created by mathi on 11/01/2024.
//

#include "Include.h"

int loose_screen(SDL_Renderer *renderer, struct Window my_window, struct Player *myPlayer) {
    SDL_bool quit = false;
    SDL_Event event;

    int width_play_again = 200 * my_window.width / 1080;
    int height_play_again = 100 * my_window.height / 768;
    int width_return_menu = 75 * my_window.width / 1080;
    int height_return_menu = 75 * my_window.height / 768;
    int width_exit_button = 60 * my_window.width / 1080;
    int height_exit_button = 60 * my_window.height / 768;
    TTF_Font *font = TTF_OpenFont("..\\assets\\stocky\\stocky.ttf", 130);
    SDL_Color color_menu = {255, 0, 0};
    SDL_Surface *surface = TTF_RenderText_Blended(font, "Vous avez perdu...", color_menu);
    SDL_Texture *texture_text_loose = SDL_CreateTextureFromSurface(renderer, surface);

    surface = IMG_Load("..\\assets\\playAgainButton.png");
    SDL_Texture *texture_play_again_button = SDL_CreateTextureFromSurface(renderer,surface);

    surface = IMG_Load("..\\assets\\retour_menu.png");
    SDL_Texture *texture_retour_menu_button = SDL_CreateTextureFromSurface(renderer,surface);

    surface = IMG_Load("..\\assets\\exit.png");
    SDL_Texture *texture_exit_button = SDL_CreateTextureFromSurface(renderer,surface);

    bool menu = true;

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            quit = Get_anim_play_again_button(event, my_window, &width_play_again, &height_play_again);
            if (quit) {
                quit = true;
                myPlayer->pv = 3;
                myPlayer->pos_x = 500;
                my_game(renderer, my_window, myPlayer, 1);
                break;
            }
            quit = Get_anim_exit_button(event, my_window, &width_exit_button, &height_exit_button);
            menu = Get_anim_return_menu_button(event, my_window, &width_return_menu, &height_return_menu);
            if (!menu) {
                quit = true;
                gameloop(renderer, my_window.window);
                break;
            }

        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        DisplayText_loose(renderer, texture_text_loose, my_window);
        DisplayExitButton(renderer, texture_exit_button, my_window, width_exit_button, height_exit_button);
        DisplayPlayAgainButton(renderer, texture_play_again_button, my_window, width_play_again, height_play_again);
        DisplayReturnMenuButton(renderer, texture_retour_menu_button, my_window, width_return_menu, height_return_menu);

        SDL_RenderPresent(renderer);
    }
    free_loose_screen(texture_play_again_button, texture_text_loose, texture_exit_button, texture_retour_menu_button);
    return 0;
}