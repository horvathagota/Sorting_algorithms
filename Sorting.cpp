#include <SDL.h>
#include <SDL_gfxPrimitives.h>
#include <SDL_ttf.h>
#include <iostream>
#include "algorithms.h"
#include "drawing_object.h"

int main(int argc, char *argv[]) {
    SDL_Event ev;

    SDL_Init(SDL_INIT_VIDEO);

    try{
        screen = SDL_SetVideoMode(804, 560, 0, SDL_ANYFORMAT);
    }catch(...){
        std::cerr << "Nem sikerült megnyitni az ablakot!" << std::endl << std::endl;
    }

    TTF_Init();
    font = TTF_OpenFont("BTTF.ttf", 16);
    font2 = TTF_OpenFont("BTTF.ttf", 8);

    SDL_WM_SetCaption("Sorting algorithms", "Sorting algorithms");

    /*az objektumokat tároló tömb*/
    Drawing_Object tomb[159];

    /*az objektumok létrehozása*/
    int X, height;
    for(int i = 0, X = 0, height = 0; i < 200; ++i)
         tomb[i].setPosition(height += 1, 550, X += 5);

    /*a tömb elemeinek megkeverése majd kirajzolása a képernyőre*/
    shuffle(tomb,159);
    SDL_Flip(screen);

    /*engedélyezzük az animációt*/
    for(int i = 0; i < 159; ++i)
        tomb[i].setAnimation(true);

    /*valamelyik rendezés*/
    /*bubble, selection, gnome, insertion, pancake, shell, cocktail, merge, quick, heap, comb, bogo*/
    SDL_Delay(1000);
    pancake(tomb,159);

    SDL_Flip(screen);

    while (SDL_WaitEvent(&ev) && ev.type!=SDL_QUIT) {}

    SDL_Quit();

    return 0;
}
