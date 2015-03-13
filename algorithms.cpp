#include <SDL.h>
#include <SDL_gfxPrimitives.h>
#include <SDL_ttf.h>
#include "algorithms.h"

SDL_Surface *screen;
TTF_Font *font;
TTF_Font *font2;
SDL_Surface *felirat;
SDL_Color piros = {255, 0, 0};
SDL_Color zold = {0, 139, 0};
SDL_Rect hova = {0, 0, 0, 0};
int comparison_value = 0;
int swap_value = 0;
int count = 0;

void title(const char* s, int x, int y, TTF_Font* font, SDL_Color colour){
    felirat = TTF_RenderUTF8_Blended(font, s, colour);
    hova.x = x;
    hova.y = y;
    SDL_BlitSurface(felirat, nullptr, screen, &hova);
    SDL_FreeSurface(felirat);
}
