cmake_minimum_required(VERSION 3.26)
project(Dacacio_Mathis_Casse_Brique C)

set(CMAKE_C_STANDARD 17)


set(SDL2_PATH "C:\\Users\\mathi\\Cours ENIGMA\\C\\SDL2-devel-2.28.5-mingw\\SDL2-2.28.5\\x86_64-w64-mingw32")
set(SDL2_IMAGE_PATH "C:\\Users\\mathi\\Cours ENIGMA\\C\\SDL2_image-2.6.3\\SDL2_image-2.6.3\\x86_64-w64-mingw32")
set(SDL2_TTF_PATH "C:\\Users\\mathi\\Cours ENIGMA\\C\\SDL2_ttf-devel-2.20.2-mingw\\SDL2_ttf-2.20.2\\x86_64-w64-mingw32")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories( ${SDL2_INCLUDE_DIR} )
include_directories( ${SDL2_IMAGE_INCLUDE_DIRS} )
include_directories( ${SDL2_TTF_INCLUDE_DIRS} )

add_executable(Dacacio_Mathis_Casse_Brique main.c
        Include.h
        Struct.h
        Gameloop.c
        My_print.c
        game.c
        Player_moove.c
        Get_anim_button.c
        Ball_moove.c
        Generate_block.c
        Check_colision.c
        End_game_condition.c
        Free_all.c
        Loose_screen.c
        Player_color.c
)


target_link_libraries(Dacacio_Mathis_Casse_Brique ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARIES} ${SDL2_TTF_LIBRARIES})

