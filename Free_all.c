//
// Created by mathi on 11/01/2024.
//

#include "Include.h"

void free_menu_settings(SDL_Texture *texture_settings_button, SDL_Texture *texture_tilte, SDL_Texture *texture_fond_menu, SDL_Texture *texture_play_button, SDL_Texture *texture_settings, SDL_Texture *texture_fond_settings, SDL_Texture *texture_retour_menu_button, SDL_Texture *texture_purple_button, SDL_Texture *texture_green_button, SDL_Texture *texture_yellow_button, SDL_Texture *texture_exit_button) {
    //free menu
    SDL_DestroyTexture(texture_settings_button);
    SDL_DestroyTexture(texture_tilte);
    SDL_DestroyTexture(texture_fond_menu);
    SDL_DestroyTexture(texture_play_button);

    //free settings
    SDL_DestroyTexture(texture_settings);
    SDL_DestroyTexture(texture_retour_menu_button);
    SDL_DestroyTexture(texture_fond_settings);
    SDL_DestroyTexture(texture_purple_button);
    SDL_DestroyTexture(texture_green_button);
    SDL_DestroyTexture(texture_yellow_button);
    SDL_DestroyTexture(texture_exit_button);
}

void free_loose_screen(SDL_Texture *texture_play_again_button, SDL_Texture *texture_text_loose, SDL_Texture *texture_exit_button, SDL_Texture *texture_retour_menu_button) {
    SDL_DestroyTexture(texture_play_again_button);
    SDL_DestroyTexture(texture_text_loose);
    SDL_DestroyTexture(texture_exit_button);
    SDL_DestroyTexture(texture_retour_menu_button);
}
