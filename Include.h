//
// Created by mathi on 04/12/2023.
//

#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdbool.h>
#include <time.h>
#include "Struct.h"

#ifndef DACACIO_MATHIS_CASSE_BRIQUE_INCLUDE_H
#define DACACIO_MATHIS_CASSE_BRIQUE_INCLUDE_H

//Ball_moove.c
void Do_ball_moove(struct Player *my_player, struct Ball *my_ball, int level);

//Check_colision.c
void check_collision_ball_block(struct Block block[], int nb_block, struct Ball *my_ball);
void check_collision_ball_player(struct Player *my_player, struct Ball *my_ball);

//End_game_condition.c
bool player_win(struct Ball *my_ball, int nb_block);
bool player_loose(struct Player *my_player);

//Free_all.c
void free_menu_settings(SDL_Texture *texture_settings_button, SDL_Texture *texture_tilte, SDL_Texture *texture_fond_menu, SDL_Texture *texture_play_button, SDL_Texture *texture_settings, SDL_Texture *texture_fond_settings, SDL_Texture *texture_retour_menu_button, SDL_Texture *texture_purple_button, SDL_Texture *texture_green_button, SDL_Texture *texture_yellow_button, SDL_Texture *texture_exit_button);
void free_loose_screen(SDL_Texture *texture_play_again_button, SDL_Texture *texture_text_loose, SDL_Texture *texture_exit_button, SDL_Texture *texture_retour_menu_button);

//game.c
int my_game(SDL_Renderer *renderer, struct Window my_window, struct Player *myPlayer, int level);

//Gameloop.c
int gameloop(SDL_Renderer *renderer, SDL_Window* window);

//Generate_block.c
void Generate_block(struct Block *block, int nb_block);
void Display_block(SDL_Renderer *renderer, struct Block *block, int nb_block);

//Get_anim_button.c
bool Get_anim_play_button(SDL_Event event, struct Window my_window, int *width_button, int *height_button);
bool Get_anim_settings_button(SDL_Event event, struct Window my_window, int *width_settings, int *height_settings);
bool Get_anim_exit_button(SDL_Event event, struct Window my_window, int *width_exit_button, int *height_exit_button);
bool Get_anim_play_again_button(SDL_Event event, struct Window my_window, int *width_play_again, int *height_play_again);
bool Get_anim_return_menu_button(SDL_Event event, struct Window my_window, int *width_return_menu, int *height_return_menu);
bool Get_anim_exit_menu_button(SDL_Event event, struct Window my_window, int *width_exit_button, int *height_exit_button);

//Loose_screen.c
int loose_screen(SDL_Renderer *renderer, struct Window my_window, struct Player *myPlayer);

//My_print.c
    //main menu screen
void DisplayTitle(SDL_Renderer *renderer, SDL_Texture *texture, struct Window my_window);
void DisplayFond(SDL_Renderer *renderer, SDL_Texture *texture, struct Window my_window);
void DisplayPlayButton(SDL_Renderer *renderer, SDL_Texture *texture, struct Window my_window, int w, int h);
void DisplaySettings(SDL_Renderer *renderer, SDL_Texture *texture, struct Window my_window, int w, int h);
void DisplayExitMenu(SDL_Renderer *renderer, SDL_Texture *texture, struct Window my_window, int w, int h);

    //settings screen
void DisplayTitleSettings(SDL_Renderer *renderer, SDL_Texture *texture, struct Window my_window);
void DisplayPurpleButton(SDL_Renderer *renderer, SDL_Texture *texture, struct Window my_window, int w, int h);
void DisplayGreenButton(SDL_Renderer *renderer, SDL_Texture *texture, struct Window my_window, int w, int h);
void DisplayYellowButton(SDL_Renderer *renderer, SDL_Texture *texture, struct Window my_window, int w, int h);

    //loose screen;
void DisplayText_loose(SDL_Renderer *renderer, SDL_Texture *texture, struct Window my_window);
void DisplayExitButton(SDL_Renderer *renderer, SDL_Texture *texture, struct Window my_window, int w, int h);
void DisplayReturnMenuButton(SDL_Renderer *renderer, SDL_Texture *texture, struct Window my_window, int w, int h);
void DisplayPlayAgainButton(SDL_Renderer *renderer, SDL_Texture *texture, struct Window my_window, int w, int h);

//Player_color.c
void Change_player_color(SDL_Event event, struct Player *myPlayer, struct Window my_window, struct Color player_color_1, struct Color player_color_2, struct Color player_color_3, int *width_purple, int *height_purple, int *width_green, int *height_green, int *width_yellow, int *height_yellow);

//Player_moove.c
void Get_player_moove(struct Player *my_player, SDL_Event event);
void Do_player_moove(struct Player *my_player, struct Window my_window, int level);


#endif //DACACIO_MATHIS_CASSE_BRIQUE_INCLUDE_H
