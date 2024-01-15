//
// Created by mathi on 04/12/2023.
//

#include "Include.h"

int gameloop(SDL_Renderer *renderer, SDL_Window* window) {
    SDL_bool quit = false;
    srand(time(NULL));
    SDL_Event event;

    //create player
    struct Color player_color_1 = {127, 0, 255};
    struct Color player_color_2 = {34, 120, 15};
    struct Color player_color_3 = {200, 200, 40};
    struct Player my_player = {500, 700, 75, 10, 3, false, false,player_color_1};
    struct Player *myPlayer = &my_player;

    //create window struct
    int windowWidth, windowHeight;
    SDL_GetWindowSize(window, &windowWidth, &windowHeight);
    struct Window my_window = {windowWidth, windowHeight, window};

    //Main menu
    int width_button = 150 * my_window.width / 1080;
    int height_button = 150 * my_window.height / 768;
    int width_settings = 70 * my_window.width / 1080;
    int height_settings = 70 * my_window.height / 768;
    int width_exit = 70 * my_window.width / 1080;
    int height_exit = 70 * my_window.height / 768;
    TTF_Font *font = TTF_OpenFont("..\\assets\\stocky\\stocky.ttf", 130);
    SDL_Color color_menu = {255, 255, 255};
    SDL_Surface *surface = TTF_RenderText_Blended(font, "Casse Brique", color_menu);
    SDL_Texture *texture_tilte = SDL_CreateTextureFromSurface(renderer, surface);

    surface = IMG_Load("..\\assets\\Main_menu_fond.png");
    SDL_Texture *texture_fond_menu = SDL_CreateTextureFromSurface(renderer,surface);

    surface = IMG_Load("..\\assets\\Play_button.png");
    SDL_Texture *texture_play_button = SDL_CreateTextureFromSurface(renderer,surface);

    surface = IMG_Load("..\\assets\\settings.png");
    SDL_Texture *texture_settings_button = SDL_CreateTextureFromSurface(renderer,surface);

    surface = IMG_Load("..\\assets\\exit.png");
    SDL_Texture *texture_exit_button = SDL_CreateTextureFromSurface(renderer,surface);

    //Settings
    int width_return_menu = 75 * my_window.width / 1080;
    int height_return_menu = 75 * my_window.height / 768;
    int width_purple = 150 * my_window.width / 1080;
    int height_purple = 150 * my_window.height / 768;
    int width_green = 150 * my_window.width / 1080;
    int height_green = 150 * my_window.height / 768;
    int width_yellow = 150 * my_window.width / 1080;
    int height_yellow = 150 * my_window.height / 768;
    SDL_Color color_settings = {0, 0, 0};
    surface = TTF_RenderText_Blended(font, "Settings", color_settings);
    SDL_Texture *texture_settings = SDL_CreateTextureFromSurface(renderer, surface);

    surface = IMG_Load("..\\assets\\retour_menu.png");
    SDL_Texture *texture_retour_menu_button = SDL_CreateTextureFromSurface(renderer,surface);

    surface = IMG_Load("..\\assets\\fond_settings.png");
    SDL_Texture *texture_fond_settings = SDL_CreateTextureFromSurface(renderer,surface);

    surface = IMG_Load("..\\assets\\Couleur_violet.png");
    SDL_Texture *texture_purple_button = SDL_CreateTextureFromSurface(renderer,surface);

    surface = IMG_Load("..\\assets\\Couleur_verte.png");
    SDL_Texture *texture_green_button = SDL_CreateTextureFromSurface(renderer,surface);

    surface = IMG_Load("..\\assets\\Couleur_jaune.png");
    SDL_Texture *texture_yellow_button = SDL_CreateTextureFromSurface(renderer,surface);

    bool game = false;
    bool settings = false;

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
                break;
            } else if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
                quit = true;
                break;
            }

            //animation du bouton du menu
            if (!game && !settings) {
                game = Get_anim_play_button(event, my_window, &width_button, &height_button);
                settings = Get_anim_settings_button(event, my_window, &width_settings, &height_settings);
            }

            if (settings) {
                settings = Get_anim_return_menu_button(event, my_window, &width_return_menu, &height_return_menu);
                //change de couleur + animation des bouttons
                Change_player_color(event, myPlayer, my_window, player_color_1, player_color_2, player_color_3, &width_purple, &height_purple, &width_green, &height_green, &width_yellow, &height_yellow);
            }
            quit = Get_anim_exit_menu_button(event, my_window, &width_exit, &height_exit);
        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        if(game && !settings) {
            //le jeu
            quit = true;
            my_game(renderer, my_window, myPlayer, 1);
        } else if (!settings){
            //le menu
            DisplayFond(renderer, texture_fond_menu, my_window);
            DisplayTitle(renderer, texture_tilte, my_window);
            DisplayPlayButton(renderer, texture_play_button, my_window, width_button, height_button);
            DisplaySettings(renderer, texture_settings_button, my_window, width_settings, height_settings);
            DisplayExitMenu(renderer, texture_exit_button, my_window, width_exit,  height_exit);
        } else {
            //dans les settings
            DisplayFond(renderer, texture_fond_settings, my_window);
            DisplayTitleSettings(renderer, texture_settings, my_window);
            DisplayReturnMenuButton(renderer, texture_retour_menu_button, my_window, width_return_menu, height_return_menu);
            DisplayPurpleButton(renderer, texture_purple_button, my_window, width_purple, height_purple);
            DisplayGreenButton(renderer, texture_green_button, my_window, width_green, height_green);
            DisplayYellowButton(renderer, texture_yellow_button, my_window, width_yellow, height_yellow);
            DisplayExitMenu(renderer, texture_exit_button, my_window, width_exit,  height_exit);
        }
        SDL_RenderPresent(renderer);
    }
    free_menu_settings(texture_settings_button, texture_tilte, texture_fond_menu, texture_play_button, texture_settings, texture_fond_settings, texture_retour_menu_button, texture_purple_button, texture_green_button, texture_yellow_button, texture_exit_button);
    return 0;
}