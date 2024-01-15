//
// Created by mathi on 09/01/2024.
//

#include "Include.h"

void Display_block(SDL_Renderer *renderer, struct Block *block, int nb_block) {
    struct Color block_color_1 = {0, 255, 0};
    struct Color block_color_2 = {0, 0, 255};
    struct Color block_color_3 = {255, 0, 0};

    for (int i = 0; i < nb_block; ++i) {
        if (block[i].pv == 1)
            block[i].color = block_color_1;
        else if (block[i].pv == 2)
            block[i].color = block_color_2;
        else
            block[i].color = block_color_3;

        if (block[i].pv != 0) {
            SDL_SetRenderDrawColor(renderer, block[i].color.r, block[i].color.g, block[i].color.b, 255);
            SDL_RenderFillRect(renderer, &block[i].rect);
        }
    }
}

void Generate_block(struct Block block[], int nb_block) {
    int space = 50;
    int nb_space = 0;
    int nb_line = 0;

    for (int i = 0; i < nb_block; ++i, nb_space++) {
        block[i].pv = rand() % 3 + 1;
        block[i].rect.w = 75;
        block[i].rect.h = 25;
        block[i].rect.x = 60 + (nb_space * (block[i].rect.w + space));

        if(block[i].rect.x >= 1080 - block[i].rect.w - 60) {
            nb_space = 0;
            block[i].rect.x = 60 + (nb_space * (block[i].rect.w + space));
            nb_line++;
        }
        block[i].rect.y = 50 + (nb_line * space);
    }
}
