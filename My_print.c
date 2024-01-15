//
// Created by mathi on 04/12/2023.
//

#include "Include.h"

//menu
void DisplayFond(SDL_Renderer *renderer, SDL_Texture *texture, struct Window my_window) {
    SDL_Rect dest = {0, 0, 1080 * my_window.width / 1080, 768 * my_window.height / 768};
    SDL_RenderCopy(renderer, texture, NULL, &dest);
}

void DisplayTitle(SDL_Renderer *renderer, SDL_Texture *texture, struct Window my_window) {
    SDL_Rect dest = {300 * my_window.width / 1080, 150 * my_window.height / 768, 500 * my_window.width / 1080, 250 * my_window.height / 768};
    SDL_RenderCopy(renderer, texture, NULL, &dest);
}

void DisplayPlayButton(SDL_Renderer *renderer, SDL_Texture *texture, struct Window my_window, int w, int h) {
    SDL_Rect dest = {490 * my_window.width / 1080, 570 * my_window.height / 768, w, h};
    SDL_RenderCopy(renderer,texture,NULL,&dest);
}

void DisplaySettings(SDL_Renderer *renderer, SDL_Texture *texture, struct Window my_window, int w, int h) {
    SDL_Rect dest = {1000 * my_window.width / 1080, 10 * my_window.height / 768, w, h};
    SDL_RenderCopy(renderer,texture,NULL,&dest);
}



//settings screen
void DisplayTitleSettings(SDL_Renderer *renderer, SDL_Texture *texture, struct Window my_window) {
    SDL_Rect dest = {340 * my_window.width / 1080, 75 * my_window.height / 768, 400 * my_window.width / 1080, 150 * my_window.height / 768};
    SDL_RenderCopy(renderer, texture, NULL, &dest);
}

void DisplayPurpleButton(SDL_Renderer *renderer, SDL_Texture *texture, struct Window my_window, int w, int h) {
    SDL_Rect dest = {175 * my_window.width / 1080, 400 * my_window.height / 768, w, h};
    SDL_RenderCopy(renderer,texture,NULL,&dest);
}

void DisplayGreenButton(SDL_Renderer *renderer, SDL_Texture *texture, struct Window my_window, int w, int h) {
    SDL_Rect dest = {475 * my_window.width / 1080, 400 * my_window.height / 768, w, h};
    SDL_RenderCopy(renderer,texture,NULL,&dest);
}

void DisplayYellowButton(SDL_Renderer *renderer, SDL_Texture *texture, struct Window my_window, int w, int h) {
    SDL_Rect dest = {800 * my_window.width / 1080, 400 * my_window.height / 768, w, h};
    SDL_RenderCopy(renderer,texture,NULL,&dest);
}

void DisplayExitMenu(SDL_Renderer *renderer, SDL_Texture *texture, struct Window my_window, int w, int h) {
    SDL_Rect dest = {15 * my_window.width / 1080, 15 * my_window.height / 768, w, h};
    SDL_RenderCopy(renderer,texture,NULL,&dest);
}



//loose screen
void DisplayText_loose(SDL_Renderer *renderer, SDL_Texture *texture, struct Window my_window) {
    SDL_Rect dest = {200 * my_window.width / 1080, 150 * my_window.height / 768, 750 * my_window.width / 1080, 250 * my_window.height / 768};
    SDL_RenderCopy(renderer, texture, NULL, &dest);
}

void DisplayExitButton(SDL_Renderer *renderer, SDL_Texture *texture, struct Window my_window, int w, int h) {
    SDL_Rect dest = {1000 * my_window.width / 1080, 10 * my_window.height / 768, w, h};
    SDL_RenderCopy(renderer,texture,NULL,&dest);
}

void DisplayReturnMenuButton(SDL_Renderer *renderer, SDL_Texture *texture, struct Window my_window, int w, int h) {
    SDL_Rect dest = {900 * my_window.width / 1080, 10 * my_window.height / 768, w, h};
    SDL_RenderCopy(renderer,texture,NULL,&dest);
}

void DisplayPlayAgainButton(SDL_Renderer *renderer, SDL_Texture *texture, struct Window my_window, int w, int h) {
    SDL_Rect dest = {450 * my_window.width / 1080, 600 * my_window.height / 768, w, h};
    SDL_RenderCopy(renderer,texture,NULL,&dest);
}


