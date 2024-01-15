//
// Created by mathi on 04/12/2023.
//


#ifndef DACACIO_MATHIS_CASSE_BRIQUE_STRUCT_H
#define DACACIO_MATHIS_CASSE_BRIQUE_STRUCT_H

struct Color {
    int r;
    int g;
    int b;
};

struct Player {
    int pos_x;
    int pos_y;
    int width;
    int height;
    int pv;
    bool q_press;
    bool d_press;

    struct Color color;
};

struct Ball {
    int pos_x;
    int pos_y;
    int width;
    int height;
    int speed_x;
    int speed_y;
    int block_destroy;

    struct Color color;
};

struct Block {
    SDL_Rect rect;
    int pv;

    struct Color color;
};

struct Window {
    int width;
    int height;
    SDL_Window* window;
};

struct life_remain {
    struct Color color;
};

#endif //DACACIO_MATHIS_CASSE_BRIQUE_STRUCT_H
